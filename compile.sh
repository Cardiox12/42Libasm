#!/bin/sh

if [[ "$1" == "clean" ]] ; then
	echo "Cleaning"
	find . -name "*.o" -delete
	rm main
else
	for target in $(find . -name "*.s") ; do
		nasm -fmacho64 $target
	done
	gcc -o main main.c *.o
fi
