![Continuous Integration](https://github.com/njoy/elementary/workflows/Continuous%20Integration/badge.svg)

# elementary
Generic identifiers for elements, nuclides and reactions

## elementary in python

The python bindings for elementary are still work in progress and should be used accordingly. Please report any issues encountered while using the python bindings using the issue tracker on this repository.

### Installing elementary for python

First of all, a user should clone the elementary repository and build the python bindings:
```
git clone https://github.com/njoy/elementary
cd elementary
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ../
make elementary.python -j8
```

elementary in python requires python 3.x so you will need to have at least one python 3.x installed. When multiple python versions are installed, it may be beneficial to include ```-DPYTHON_EXECUTABLE=$(which python3)``` in the cmake configuration step so that the default python3 version will be picked. The compilation will produce a dynamic library linked to the python libraries on the user's computer (it'll be named something like `elementary.cpython-37m-darwin.so`). This name will also indicate which version of the python libraries this library is linked to. This is important since you will need to use the associated python version with the elementary python package.

In order to use the elementary python package, the user should make sure that the library is within the python path. This can be done in multiple ways. You can set that up by adding the elementary build path to the python path `$PYTHONPATH` environmental variable on your machine, or by using the following in your python code:
```
import sys
sys.path.append( < elementary-build-path > )
```
where `< elementary-build-path >` is the path to the elementary python dynamic library.

When running python in the build directory directly, none of these steps are required.

#### Troubleshooting ####

##### CMake doesn’t detect the right Python version #####

Taken from the pybind11 FAQ.

The CMake-based build system will try to automatically detect the installed version of Python and link against that. When this fails, or when there are multiple versions of Python and it finds the wrong one, delete CMakeCache.txt and then add -DPYTHON_EXECUTABLE=$(which python) to your CMake configure line. (Replace $(which python) with a path to python if your prefer.)

A version of python 3.x is preferred.

##### importError cannot import name <sysconfig> #####

This error sometimes comes up when running the cmake command. This appears to be related to an incomplete/corrupted python installation. It can be rectified by installing the distutils package for the python version that is being used. On a linux system, the following command should install the distutils package:
```
sudo apt install python3-distutils
```

##### cannot find python.h #####

When compiling the python bindings, this error indicates that the python header files and static library we need to link to are not installed on your system. This appears to be related to an incomplete python installation. It can be rectified by installing the python3-dev package (when using python 3). On a linux system, the following command should install the header files:
```
sudo apt install python3-dev
```

## LICENSE
This software is copyrighted by Los Alamos National Laboratory and distributed
according to the conditions in the accompanying [LICENSE](LICENSE) file.
