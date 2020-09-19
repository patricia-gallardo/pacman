![CI-Release](https://github.com/patricia-gallardo/pacman/workflows/CI-Release/badge.svg)
![CI-Debug](https://github.com/patricia-gallardo/pacman/workflows/CI-Debug/badge.svg)
## Conan

Set this environment variable and Conan will tell you which packages you need to
intall on Linux.
CONAN_SYSREQUIRES_MODE=verify

In case of link errors around sndio, try to uninstall this package and rebuild the conan cache:
~~~
sudo apt remove libsndio-dev*
~~~
https://bugzilla.libsdl.org/show_bug.cgi?id=5105

## Ghosts
This will probably become relevant https://en.wikipedia.org/wiki/Ghosts_(Pac-Man)
This as well https://youtu.be/ataGotQ7ir8