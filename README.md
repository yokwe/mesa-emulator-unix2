# mesa-emulator-unix
xerox mesa processor emulator in c++ on unix

First target OS is MacOS and FreeBSD. Later it will expand to Linux

Still in development. Don't expect it will work as you expecting.

Difference between mesa-emulator-unix and mesa-emulator-unix2 are
  Replace QT with STL
  Replace log4cpp with log4cxx
  Get type information using clang -ast-dump=json
  Use Link Time Optimization to improve performance