# Computational-physics
*Computational physics routines in C*

This repository contains some C routines for computational physics such as numerical integration, methods for differential equations and linear algebra wrappers.

The CMake structure creates a **static library** `compphy-lib` that you can install to your computer following the instructions in this file.

## Install
To install the code of this library locally, first download this repository from github.

After downloading, open a terminal and move to your local copy of the repository. 

From the main directory, execute

```
mkdir build
cd build
cmake ..
make -j
```

This will compile the library and put the executables in the directory `build`.

After compiling, execute the following command to install the library:
```
make install
```
After doing that, the library will be installed in the location
```
$HOME/.local/
```
After this procedure, you can include with brackets the header files of the compphy-lib.

## Linking
Make sure to link the Compphy library when you compile, if you are using the compphy-lib. You can do this by compiling with the following flags:
```
gcc <c_file> -o <executable_name> -I$HOME/.local/include -L$HOME/.local/lib -lcompphy
```
## Content
The source code (i.e. the .c files) is in the directory `src`.

The header files are in the directory `include`. 

## Documentation
The source code is documented with Doxygen. To generate the documentation, make sure to have Doxygen installed and then use `cmake` with the documentation option:
```
cmake .. -DDOCS=ON
make -j
```
After that, you can find documentation files in the directory `build/docs`.

