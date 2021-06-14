//
// Testing script for the matrix library, testing matrix subtraction, 
// multiplication and transpose. 
//

#include <iostream>
#include <matrix.hpp>
#include "gtest/gtest.h"

using namespace std;

// Doubles
typedef Matrix<double,3,4> M34d;
typedef Matrix<double,4,3> M43d;
typedef Matrix<double,4,4> M44d;
typedef Matrix<double,3,3> M33d;

// Integers
typedef Matrix<int,4,9> M49i;
typedef Matrix<int,9,4> M94i;
typedef Matrix<int,4,4> M44i;
typedef Matrix<int,9,9> M99i;

TEST (AdditionTest,Doubles) {
    double matrixd[3][4] = {
        {1.1,2.2,3.3,4.4},
        {5.5,6.6,7.7,8.8},
        {9.9,10.1,11.2,12.3}
        };
    double matrixd2[3][4] = {
        {2.2,4.4,6.6,8.8},
        {11.0,13.2,15.4,17.6},
        {19.8,20.2,22.4,24.6}
        };
    M34d matrixd1(matrixd);
    M34d matrixsumd = matrixd1 + matrixd1;

    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 4; j++) {
            EXPECT_NEAR (matrixd2[i][j], matrixsumd.getij(i,j), 0.00000001);
        }
    }

}

TEST (AdditionTest, Ints) {
    int matrix[4][9] = {
        {5,25,3,8,7,23,1,0,5},
        {8,3,5,9,5,7,0,1,2},
        {7,32,1,8,0,7,4,2,4},
        {0,7,4,8,4,2,5,8,9}
        };
    int matrix2[4][9] = {
        {10,50,6,16,14,46,2,0,10},
        {16,6,10,18,10,14,0,2,4},
        {14,64,2,16,0,14,8,4,8},
        {0,14,8,16,8,4,10,16,18}
        };

    M49i matrix1(matrix);
    M49i matrixsumi = matrix1 + matrix1;

    for (size_t i = 0; i < 4; i++) {
        for(size_t j = 0; j < 9; j++) {
            EXPECT_EQ (matrix2[i][j], matrixsumi.getij(i,j));
        }
    }

}

TEST (TransposeTest, Doubles) {
    double matrixd[3][4] = {
        {1.1,2.2,3.3,4.4},
        {5.5,6.6,7.7,8.8},
        {9.9,10.1,11.2,12.3}
        };
    double matrixd2[4][3] = {
        {1.1,5.5,9.9},
        {2.2,6.6,10.1},
        {3.3,7.7,11.2},
        {4.4,8.8,12.3}
    };

    M34d matrix1(matrixd);
    M43d matrix2 = matrix1.transpose();

    for (size_t i = 0; i < 4; i++) {
        for(size_t j = 0; j < 3; j++) {
            EXPECT_NEAR (matrixd2[i][j], matrix2.getij(i,j),0.0000000001);
        }
    }

}

TEST (TransposeTest, Ints) {
    int matrix[4][9] = {
        {5,25,3,8,7,23,1,0,5},
        {8,3,5,9,5,7,0,1,2},
        {7,32,1,8,0,7,4,2,4},
        {0,7,4,8,4,2,5,8,9}
        };

    int matrixi[9][4] = {
        {5,8,7,0},
        {25,3,32,7},
        {3,5,1,4},
        {8,9,8,8},
        {7,5,0,4},
        {23,7,7,2},
        {1,0,4,5},
        {0,1,2,8},
        {5,2,4,9}
    };

    M49i matrix1(matrix);
    M94i matrix2 = matrix1.transpose();

    for (size_t i = 0; i < 4; i++) {
        for(size_t j = 0; j < 3; j++) {
            EXPECT_EQ (matrixi[i][j], matrix2.getij(i,j));
        }
    }
}

TEST (MultiplicationTest, Doubles) {
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

    M34d matrix1(matrixd);
    M43d matrix2 = matrix1.transpose();
    M33d matrixm1 = matrix1 * matrix2;
    M44d matrixm2 = matrix2 * matrix1;

    for (size_t i = 0; i < 4; i++) {
        for(size_t j = 0; j < 4; j++) {
            EXPECT_NEAR (testd1[i][j], matrixm2.getij(i,j),0.00000001);
        }
    }

    for (size_t i = 0; i < 3; i++) {
        for(size_t j = 0; j < 3; j++) {
            EXPECT_NEAR (testd2[i][j], matrixm1.getij(i,j),0.00000001);
        }
    }


}

TEST (MultiplicationTest, Ints) {
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

    M49i matrix1(matrix);
    M94i matrix2 = matrix1.transpose();
    M44i matrixm1 = matrix1 * matrix2;
    M99i matrixm2 = matrix2 * matrix1;

    for (size_t i = 0; i < 4; i++) {
        for(size_t j = 0; j < 4; j++) {
            EXPECT_EQ (test1[i][j], matrixm1.getij(i,j));
        }
    }

    for (size_t i = 0; i < 9; i++) {
        for(size_t j = 0; j < 9; j++) {
            EXPECT_EQ (test2[i][j], matrixm2.getij(i,j));
        }
    }
}

TEST (SubtractionTest, Doubles) {
    double matrixd[3][4] = {
        {1.1,2.2,3.3,4.4},
        {5.5,6.6,7.7,8.8},
        {9.9,10.1,11.2,12.3}
        };
    M34d matrixd1(matrixd);
    M34d matrixdiffd = matrixd1 - matrixd1;

    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 4; j++) {
            EXPECT_NEAR (0.0, matrixdiffd.getij(i,j), 0.00000001);
        }
    }
}

TEST (SubtractionTest, Ints) {
    int matrix[4][9] = {
        {5,25,3,8,7,23,1,0,5},
        {8,3,5,9,5,7,0,1,2},
        {7,32,1,8,0,7,4,2,4},
        {0,7,4,8,4,2,5,8,9}
        };

    M49i matrix1(matrix);
    M49i matrixdiffi = matrix1 - matrix1;

    for (size_t i = 0; i < 4; i++) {
        for(size_t j = 0; j < 9; j++) {
            EXPECT_EQ (0, matrixdiffi.getij(i,j));
        }
    }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
