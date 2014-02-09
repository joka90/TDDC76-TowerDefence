export ANDROID_NDK=/home/joka/TDDC76/android-ndk-r9c
cd ../SFML/
export ANDROID_CMAKE_TOOLCHAIN=cmake/toolchains/android.toolchain.cmake
#mkdir build && cd build
#cmake -DCMAKE_TOOLCHAIN_FILE=../cmake/toolchains/android.toolchain.cmake -DANDROID_USE_STLPORT=1 ..
#make -j4
cd tools/android
./make_all.sh
