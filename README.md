# TamarVision

- Made by David Tamaratare Oghenebrume
- TamarVision is a computer-vision-based application that was made using OpenCV and the C++ programming language.
- This application was made for the purpose of displaying images from the command line.

### *Prerequistes:*
- CMake.
- A C++ Compiler that supports at least C++20 (MSVC is recommended if you're developing on Windows).
- A working terminal or command line.

### *Build Requirements:*
- [OpenCV C++ API](https://github.com/opencv/opencv)
- Eigen3

## *Project usage example:*
```bash
C:\ TamarVision --version
TamarVision version: 0.0.1

Made by David Tamaratare Oghenebrume
C:\ TamarVision
Made by David Tamaratare Oghenebrume
Usage:

    Run 'TamarVision --help' for more information.

C:\ TamarVision <path_to_image>
```
The above command displays the argument that is passed to the executable (i.e an image).

## *How to use this project:*
Run the following in your terminal:
- ```C:/ git clone https://github.com/opencv/opencv.git```
- Follow their build instructions on their [website](https://docs.opencv.org/4.x/df/d65/tutorial_table_of_content_introduction.html)
```bash
C:\ git clone https://github.com/lil-brumski/TamarVision.git
C:\ cd TamarVision/
C:\TamarVision> mkdir build/
C:\TamarVision> cd build/
C:\TamarVision\build> cmake ..
C:\TamarVision\build> cmake --build .
```
- Look for the executable in one of `build`'s subdirectories (e.g Release/ or Debug/) and run it (this is mainly for Windows users).

This is how you run executables from the terminal: 

## *For Windows:*
```bash
C:/TamarVision/build/release> ./TamarVision.exe
```

## *For Linux distros like Ubuntu:*
```bash
C:/TamarVision/build> ./TamarVision
```

This project uses the MIT Licensing. See the LICENSE file for more information.

