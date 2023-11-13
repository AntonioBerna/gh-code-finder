#!/bin/sh

dir="debug/"
founds="founds/"
target="gh-code-finder.app"

if [ "$#" -eq 0 ]; then
    set -xe
    mkdir "$dir" && cd "$dir"
    cmake ..
    make
    mv "$target" ../
    echo "Build complete."
    exit 0
elif [ "$#" -eq 1 ] && [ "$1" == "clear" ]; then
    if [ -d "$dir" ]; then
        rm -r "$dir"
    fi

    if [ -d "$founds" ]; then
        rm -r "$founds"
    fi

    if [ -e "$target" ]; then
        rm "$target"
    fi

    echo "Done."
    exit 0
else
    echo "Usage: sh $0 <options=[clear,]>"
    exit 1
fi