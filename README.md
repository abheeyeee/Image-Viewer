# Image Viewer (PPM)

A simple image viewer written in pure C using SDL2.

This project was built as a learning exercise

The viewer currently supports loading and displaying PPM (Portable Pixmap) images through standard input.

## Features

* Loads PPM images
* Displays images using SDL2
* Handles window events
* Implemented in pure C
* No external image-loading libraries used

## Build

Requirements:

* GCC
* SDL2

Compile:

```bash
gcc -Wall -Wextra -g -o iv viewer.c $(sdl2-config --cflags --libs)
```

## Usage

Pipe a PPM image into the viewer:

```bash
cat panda.ppm | ./iv
```

You can also use input redirection:

```bash
./iv < panda.ppm
```

## Learning Objectives

During development, the following concepts were explored:

* Reading and parsing PPM headers
* Understanding image dimensions
* RGB color representation
* SDL surfaces
* SDL event handling
* Resource management and cleanup
* Memory allocation 
* Row-major image storage (`y` = rows, `x` = columns)

## Project Structure

```text
.
├── viewer.c
├── panda.ppm
├── .gitignore
└── README.md
```
## References

The following resources were helpful during development:

* SDL2 Documentation
* SDL Wiki
* PPM (Portable Pixmap) File Format Specification

SDL Documentation:

https://wiki.libsdl.org/

PPM Format Reference:

https://netpbm.sourceforge.net/doc/ppm.html


## Notes

This project was written in approximately 6 hours as a hands-on learning project to gain a deeper understanding of low-level graphics programming in C and SDL2.
