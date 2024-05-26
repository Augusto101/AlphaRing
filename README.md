## Alpha Ring
### A Modding Tool for MCC

[![Build status](https://ci.appveyor.com/api/projects/status/o3qbtc7jirw81xmb?svg=true)](https://ci.appveyor.com/project/WinterSquire/alpharing)

### Showcase

![](https://raw.githubusercontent.com/WinterSquire/AlphaRing/master/img/CameraTool.png)

![](https://raw.githubusercontent.com/WinterSquire/AlphaRing/master/img/ObjectBrowser.png)

![](https://raw.githubusercontent.com/WinterSquire/AlphaRing/master/img/SplitscreenHR.png)

![](https://raw.githubusercontent.com/WinterSquire/AlphaRing/master/img/SplitscreenH3.png)

![](https://raw.githubusercontent.com/WinterSquire/AlphaRing/master/img/SplitscreenH1.png)

### Features
* Splitscreen (all games)
* Camera Tool (H3)
* Object Browser (H3)

### Installation
Download the latest stable build from the [Releases](https://github.com/WinterSquire/AlphaRing/releases) page.

Place the DLL into the "Halo The Master Chief Collection\mcc\binaries\win64" directory and launch the game with EAC off.

For Running on Steam Deck/Linux, add the following command in the Steam Game Launch Options:
``` 
WINEDLLOVERRIDES="WTSAPI32=n,b" %command%
```

### Usage
Toggle menu: `F4` or `Controller Back` + `Controller Start`

When the menu is open, game input is disabled.

**Split Screen:**
- Supports 3 or 4 players in Halo 1, Halo 3, Halo 3: ODST, Halo: Reach, and Halo 4.
- Not supported for Co-Op in Halo 2. Attempting to do so will cause the game to get stuck at loading.

### Credits
- [Assembly](https://github.com/XboxChaos/Assembly) for the tag group research.
- [Blender](https://github.com/blender/blender) for the bezier curve calculation.
- [Priception](https://github.com/Priception) for adding UI controller support and helping with the interface and crash issue.