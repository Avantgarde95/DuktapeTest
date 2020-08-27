# DuktapeTest

Example of running [Typescript](https://www.typescriptlang.org/) code natively by using [Webpack](https://webpack.js.org/) and [Duktape](https://duktape.org/).

### How to build

- Run `npm install` to install the dependencies.
- Run `npm run build` to compile the Typescript code.
- Run `mkdir build`, move to `build`, and run `cmake ..` to build the C++ code.

### How to run

After building,
make sure that the working directory is the same as the directory of the executable (`DuktapeTest(.exe)`)
and `dist` directory exists in the directory of the executable. Just run the executable.

### Requirements

- [CMake](https://cmake.org/)
- [Node.js](https://nodejs.org/)

### To do

- Multiple Typescript files
- Console input (`input()` function)
- Combine other C/C++ libraries (ex. [PDCurses](https://github.com/wmcbrine/PDCurses))
- Multiplatform (Web and native)
