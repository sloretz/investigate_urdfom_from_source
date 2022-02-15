# Using urdfdom from different contexts

## Building urdfdom with my branch

Try both ways, with and without `APPEND_PROJECT_NAME_TO_INCLUDE_DIR` set

```
git clone https://github.com/ros/urdfdom.git -b sloretz__urdfdom__include_projectname
cd urdfdom
mkdir build
mkdir install
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=../install/
# OR to not append PROJECT_NAME:
# cmake .. -DCMAKE_INSTALL_PREFIX=../install/ -DAPPEND_PROJECT_NAME_TO_INCLUDEDIR=OFF
make
make install
```

Set these variables so the terminal can find the version urdfdom from source

```
cd urdfdom/install
export CMAKE_PREFIX_PATH=`pwd`
export LD_LIBRARY_PATH=`pwd`/lib
export PKG_CONFIG_PATH=`pwd`/lib/pkgconfig
```

Make sure the system version isn't installed

```
apt remove liburdfdom-dev
```

## Build the example with a Makefile using pkg-config

```
cd urdfdom_from_pkgconfig
make
make test
```

## Build the example with just CMake

```
cd urdfdom_from_cmake
mkdir build
cd build
cmake ..
make
./use_urdfdom_oldstyle
./use_urdfdom_modern
```

## Build the example with catkin

```
cd urdfdom_from_catkin
apt install ros-noetic-robot
apt remove liburdfdom-dev
. /opt/ros/noetic/setup.bash
catkin_make
./build/urdfdom_from_catkin/use_urdfdom_oldstyle
./build/urdfdom_from_catkin/use_urdfdom_modern
```
