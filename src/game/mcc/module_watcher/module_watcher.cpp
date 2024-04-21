#include "module_watcher.h"

#include <mutex>

namespace Halo3Hook { extern bool Init(__int64 hModule); }

static ModuleInfo modules[7];
static std::mutex mutex;

class CModuleWatcher : public ICModuleWatcher {
public:
    eStatus initialize() override {return SYS_OK;}
    eStatus shutdown() override {return SYS_OK;}
    ModuleInfo& getModuleStatus(ModuleInfo::eTitle title) const override {
        std::lock_guard<std::mutex> lock(mutex);
        return modules[title];
    }
};

static CModuleWatcher moduleWatcher;
ICModuleWatcher* g_pModuleWatcher = &moduleWatcher;

void ModuleLoad(ModuleInfo *info) {
    {
        std::lock_guard<std::mutex> lock(mutex);
        modules[info->title] = *info;
    }

    if (info->errorCode == 0) {
        LOG_DEBUG("Module {0}: Loaded At: {1:x}", ModuleInfo::cTitle[info->title], info->hModule);
        if (info->title == ModuleInfo::Halo3) {
            Halo3Hook::Init(info->hModule);
        }
    } else {
        LOG_DEBUG("Module {0}: Loaded Error: {1}", ModuleInfo::cTitle[info->title], info->errorCode);
    }
}

void ModuleUnload(ModuleInfo *info) {
    {
        std::lock_guard<std::mutex> lock(mutex);
        modules[info->title].hModule = 0;
        modules[info->title].p_CreateDataAccess = 0;
        modules[info->title].p_ppCxxFrameHandler3 = 0;
    }

    LOG_DEBUG("Module {0}: Is about to unload", ModuleInfo::cTitle[info->title]);
}
