#!/bin/sh

if [[ "$1" == "clean" ]] ; then
	echo "Cleaning"
	find . -name "*.o" -delete
	rm main
else
	for target in $(find . -name "*.s") ; do
		nasm -fmacho64 $target
	done
	if [[ "$1" == "debug" ]] ; then
		echo "Debug mode"
		gcc -o main main.c *.o -DDEBUG
	else
		gcc -o main main.c *.o
	fi
fi
