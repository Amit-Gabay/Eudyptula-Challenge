Replace `linux` by a symlink to the most up-to-date stable linux version you've cloned.
I chose to use symlink instead to not mess up with inner git repos, while git submodule is not a good usage in our case.

Create a Linux Kernel Config:
* I've copied the default config file from the relevant `/boot/config-*` file corresponding to the currently running kernel version.
* Then, I've manually modified the configuration file.
* Finally, I've addapted the configuration file using `make localmodconfig`.

Compiling the Kernel:
Using the previously created `.config` file, it's easy:
Run `make`.

Kernel Modules Installation:
Simply use `sudo make modules_install` in order to install the brand new compiled kernel modules into the relevant modules directories.

Kernel Installation:
Finally, use `sudo make install` to install our compiled kernel image into `/boot` dir, while updating the `grub` bootloader configuration accordingly to load specifically our compiled kernel image.

Before Boot:
Let's check the currently running kernel version, to validate our installation worked - and to figure out what kernel image to get back to incase our kernel won't boot successfully.
```
➜  Task2 git:(dev-task2) ✗ uname -r
6.13.8-200.fc41.x86_64
```

After Boot:
```
➜  ~ uname -r
6.14.0-02665-g1e26c5e28ca5
```
As you can se we're running the latest version of the linux kernel!!! :D
