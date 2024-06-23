#!/bin/bash

BUILD_DIR="build"
BIN_DIR="bin"
CMAKE_BUILD_TYPE="Release"
CMAKE_GENERATOR="Unix Makefiles"
EXECUTABLE_NAME="aoc_solve"

show_help() {
    echo "Usage: ./build.sh [option]"
    echo "Options:"
    echo "  --clean     Clean the build directory"
    echo "  --rebuild   Clean and rebuild the project"
    echo "  --debug     Build with debug symbols"
    echo "  --help      Show this help message"
}

clean() {
    echo "Cleaning build directory..."
    rm -rf "$BUILD_DIR" "$BIN_DIR"
}

build() {
    mkdir -p "$BUILD_DIR"
    cd "$BUILD_DIR" || exit
    cmake -G "$CMAKE_GENERATOR" -DCMAKE_BUILD_TYPE="$CMAKE_BUILD_TYPE" ..
    cmake --build . --target "$EXECUTABLE_NAME" -- -j"$(nproc)"
    cd ..
    mkdir -p "$BIN_DIR"
    cp "$BUILD_DIR/$EXECUTABLE_NAME" "$BIN_DIR/"
}

case "$1" in
    --clean)
        clean
        ;;
    --rebuild)
        clean
        build
        ;;
    --debug)
        CMAKE_BUILD_TYPE="Debug"
        build
        ;;
    --help)
        show_help
        ;;
    *)
        build
        ;;
esac