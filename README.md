# repel
A simple, fast utility for finding and replacing code throughout your codebase

## Why?

repel was created in order to solve the issue of having to find and replace code through out a codebase with out manaully going through each file. For example, suppose you have a function that you use all through out your code and you decide to change the name of the function. You could go file by file finding and replacing that function or you could run ```repel replace . myFunc newFunc```. If you only want to change the function in a certain directory you can do that with ```repel replace myDir myFunc newFunc``` or if you want to remove it from your code you can use ```repel erase . myFunc```.

# Installation 
## Linux/WSL
Required packages:
- gcc
- git
- make
```
git clone https://github.com/sunfish-dev/repel.git
cd repel/build
sudo make install
```
Alternatively, you can build repel statically
```
git clone https://github.com/sunfish-dev/repel.git
cd repel/build
sudo make install-static
```
## Windows
I'd reccomend using WSL to use repel however you should be able to build repel on Windows using these steps. Note you may need to use ```mingw32-make``` instead of ```make``` or use the ```make win32``` or ```make win64``` commands depending on your system.

You'll need:
- GCC (MinGW specificly. Should come with make)
- git

1. Clone and build repel
```
git clone https://github.com/sunfish-dev/repel.git
cd repel/build
make release
```
Alternatively, you can build repel statically
```
git clone https://github.com/sunfish-dev/repel.git
cd repel/build
make static
```
2. Add the path to repel to your path settings in Windows

You may encounter issues with the filesystem library building on Windows. The issue should be fixed by using the latest release of GCC. You can also build the Windows version on Linux/WSL by using the ```make win32``` or ```make win64``` commands depending on your system and having the proper MinGW packages installed which vary by distro and are typically named something like ```mingw-w64-gcc```.