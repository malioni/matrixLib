# matrixLib

Matrix library that implements matrix multiplication, addition and subtraction.

To use the library, download the repository, and then go to the directory with the repository on your terminal, then input:

```
mkdir build
cd build
cmake ..
make -j 8
./matrixLib_test
```
The last line is used to see the results from the `test.cpp` file. To use the library in any other file, you need to `#include <matrix.hpp>` at the top of your `.cpp` file.

To see the documentation, go to the directory with the Doxyfile and type in:
```
doxygen Doxyfile

```
It will generate documentation in `.html` and in `.rtf` formats, the latter can be opened with most document editing programs, e.g. Microsoft Word.