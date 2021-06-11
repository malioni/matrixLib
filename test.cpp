//
// Testing script for the matrix library, testing matrix addition, 
// multiplication and transpose. 
//

#include <iostream>
#include <matrix.hpp>

int main() {

    // Matrix of doubles
    typedef Matrix<double,3,4> M34;
    typedef Matrix<double,4,3> M43;
    typedef Matrix<double,4,4> M44;
    typedef Matrix<double,3,3> M33;

    double matrixd[3][4] = {
        {1.1,2.2,3.3,4.4},
        {5.5,6.6,7.7,8.8},
        {9.9,10.1,11.2,12.3}
        };

    double testd1[4][4] = {
        {129.47, 138.71, 156.86, 175.01},
        {138.71, 150.41, 171.2, 191.99},
        {156.86, 171.2, 195.62, 220.04},
        {175.01, 191.99, 220.04, 248.09}
    };

    double testd2[3][3] = {
        {36.3, 84.7, 124.19},
        {84.7, 210.54, 315.59},
        {124.19, 315.59, 476.75}
    };

    M34 matrixd1(matrixd);
    M44 testdm1(testd1);
    M33 testdm2(testd2);

    cout << "Matrix of doubles" << endl;
    cout << endl;

    cout << "Given matrix:" << endl;
    matrixd1.print();
    cout << "It's transpose is: " << endl;
    M43 matrixd2 = matrixd1.transpose();
    matrixd2.print();
    cout << "Matrix multiplied by it's transpose should be: " << endl;
    testdm2.print();
    cout << endl;
    cout << "The multiplication algorithm returns:" << endl;
    M33 matrixd3 = matrixd1 * matrixd2;
    matrixd3.print();
    cout << "The difference between the two is:" << endl;
    M33 matrixd6 = matrixd3 - testdm2;
    matrixd6.print();
    cout << "Matrix transpose multiplied by the matrix should be: " << endl;
    testdm1.print();
    cout << endl;
    cout << "The multiplication algorithm returns:" << endl;
    M44 matrixd4 = matrixd2 * matrixd1;
    matrixd4.print();
    cout << "The difference between the two is:" << endl;
    M44 matrixd5 = matrixd4 - testdm1;
    matrixd5.print();

    cout << endl;

     // Matrix of integers
    typedef Matrix<int,4,9> M49;
    typedef Matrix<int,9,4> M94;
    typedef Matrix<int,4,4> M44i;
    typedef Matrix<int,9,9> M99;

    int matrix[4][9] = {
        {5,25,3,8,7,23,1,0,5},
        {8,3,5,9,5,7,0,1,2},
        {7,32,1,8,0,7,4,2,4},
        {0,7,4,8,4,2,5,8,9}
        };

    int test1[4][4] = {
        {1327, 408, 1087, 375},
        {408,  258, 288, 173},
        {1087, 288, 1223, 378},
        {375, 173, 378, 319}
    };

    int test2[9][9] = {
        {138, 373, 62, 168, 75, 220, 33, 22, 69},
        {373, 1707, 150, 539, 218, 834, 188, 123, 322},
        {62, 150, 51, 109, 62, 119, 27, 39, 65},
        {168, 539, 109, 273, 133, 319, 80, 89, 162},
        {75, 218, 62, 133, 90, 204, 27, 37, 81},
        {220, 834, 119, 319, 204, 631, 61, 37, 175},
        {33, 188, 27, 80, 27, 61, 42, 48, 66},
        {22, 123, 39, 89, 37, 37, 48, 69, 82},
        {69, 322, 65, 162, 81, 175, 66, 82, 126}
    };

    M49 matrix1(matrix);
    M44i testm1(test1);
    M99 testm2(test2);

    cout << "Matrix of integers" << endl;
    cout << endl;

    cout << "Given matrix:" << endl;
    matrix1.print();
    cout << "It's transpose is: " << endl;
    M94 matrix2 = matrix1.transpose();
    matrix2.print();
    cout << "Matrix multiplied by it's transpose should be: " << endl;
    testm1.print();
    cout << endl;
    cout << "The multiplication algorithm returns:" << endl;
    M44i matrix3 = matrix1 * matrix2;
    matrix3.print();
    cout << "The difference between the two is:" << endl;
    M44i matrix6 = matrix3 - testm1;
    matrix6.print();
    cout << "Matrix transpose multiplied by the matrix should be: " << endl;
    testm2.print();
    cout << endl;
    cout << "The multiplication algorithm returns:" << endl;
    M99 matrix4 = matrix2 * matrix1;
    matrix4.print();
    cout << "The difference between the two is:" << endl;
    M99 matrix5 = matrix4 - testm2;
    matrix5.print();

}
