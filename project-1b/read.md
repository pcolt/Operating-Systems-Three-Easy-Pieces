git clone xv6-public-repository   //download xv6 source code

sudo apt-get install qemu    //install emulator qemu

cd xv6-public

make [TOOLPREFIX=i386-elf-] qemu-nox    //build and run xv6 without separate window
make qemu        //with separate window

Ctr-a x          //to quit the emulation
