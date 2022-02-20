
Building Boost
```
git submodule update --init --recursive
mkdir thirdparty/bin
cd thirdparty/src/boost
./bootstrap.sh --prefix=$(pwd)/../../bin
./b2
./b2 install
```

Building and running the application
```
mkdir build
cd build
cmake ..
make
./main
```
