# Computational-physics
*Computational physics routines in C*

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

This will compile the library and put the executables in the directory `build` (which will not be traked by git, as it should be with the executables).

After compiling, execute the following command to install the library locally:
```
make install
```
After doing that, the library will be installed in the path
```
.local/cmake/CompPhy
```
After this procedure, you can import in your .c files the header files listed in the directory `include`, with the notation
```
#include <filename.h>
```
## Content
The source code (i.e. the .c files) is in the directory `src`.

The header files are in the directory `include`. 

The directory `docs` contains the documentation of the source code, which is made with Doxygen and generated with `cmake`.

The directory `test` contains unit test programs based on the extern module googletest, which is located in `extern/googletest`.


