# rotwal
Simple Script for UNIX to allow slideshow wallpapers.

**Instructions**

After compiling `main.cpp`, add the paths to your desired wallpapers in `rotwal.conf`, each separated by a newline. All paths should begin from your home directory (for example, `/home/user/wallpaper.jpg` should be `wallpaper.jpg`). Run either `rotwal.sh` or your compiled executable with a single argument containing the amount of seconds you would like inbetween each wallpaper change.

**Dependencies**

<unistd.h>

Should come with UNIX systems


dylanaraps/wal

https://github.com/dylanaraps/wal
