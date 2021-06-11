/**
 * @file
 * @author  Matiss Senkans <senkans.matiss@gmail.com>
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * The matrix library implements matrix transpose, multiplication
 * and addition in C++.
 */

using namespace std;

template <typename num, size_t rows, size_t cols>

class Matrix {
public:
    
    typedef num row_type[cols];
    typedef row_type matrix_type[rows];
    
    matrix_type _matrix;
    size_t _r;
    size_t _c;

    /**
    * Constructor that declares a matrix of a given size with
    * all of the entries set to 0.
    */
    
    Matrix() {
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                _matrix[i][j] = 0;
            }
        }
        _r = rows;
        _c = cols;
    }

    /**
    * Constructor that initializes a matrix given a 2D array.
    * 
    * @param matrix is a 2D array that we want to use as a matrix
    */
    
    Matrix (const matrix_type &matrix) {
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                _matrix[i][j] = matrix[i][j];
                
            }
        }
        _r = rows;
        _c = cols;
    }
    
    /**
    * Class method that returns the transpose of the matrix object.
    * 
    * @return Matrix object that is the transpose of the current matrix.
    */

    Matrix<num, cols, rows> transpose() {
        num T[cols][rows];
        
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                T[j][i] = _matrix[i][j];
            }
        }
        
        Matrix<num,cols,rows> t(T);
        return t;
    }

    /**
    * Class method that sets the matrix value in the provided location.
    * 
    * @param val is the desired value to be set.
    * @param i is the index of the row for the value
    * @param j is the index of the column for the value
    */
    void setij(num val, size_t i, size_t j) {
        _matrix[i][j] = val;
    }

    /**
    * Class method that returns the matrix value in the provided location.
    * 
    * @param i is the index of the row for the value
    * @param j is the index of the column for the value
    * 
    * @return the value in the requested index
    */
    num getij(size_t i, size_t j) {
        return _matrix[i][j];
    }

    /**
    * Class method that overloads the addition operator to allow matrix addition
    * 
    * @param matrix is the matrix that is added to the current Matrix
    * 
    * @return a new Matrix object that is the sum of the given two matrices
    */
    Matrix<num,rows,cols> operator+ (Matrix<num,rows,cols> &matrix) {
        num mat3[rows][cols];
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                mat3[i][j] = _matrix[i][j] + matrix._matrix[i][j];
            }
        }
        Matrix<num,rows,cols> sum(mat3);
        return sum;
    }

    /**
    * Class method that overloads the subtraction operator to allow matrix subtraction
    * 
    * @param matrix is the matrix that is subtracted from the current Matrix
    * 
    * @return a new Matrix object that is the difference between the given two matrices
    */

    Matrix<num,rows,cols> operator- (Matrix<num,rows,cols> &matrix) {
        num mat3[rows][cols];
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                mat3[i][j] = _matrix[i][j] - matrix._matrix[i][j];
            }
        }
        Matrix<num,rows,cols> diff(mat3);
        return diff;
    }
    
    /**
    * Class method that overloads the multiplication operator to allow matrix multiplication
    * 
    * @param matrix is the matrix that is multiplied to the current Matrix
    * 
    * @return a new Matrix object that is the multiplication of the given two matrices
    */
    template <size_t cols2>
    Matrix<num,rows,cols2> operator* (const Matrix<num,cols,cols2> &matrix) {
        num mult[rows][cols2];
        num sum;
        
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols2; j++) {
                sum = 0;
                for (size_t k = 0; k < cols; k++) {
                    sum += _matrix[i][k] * matrix._matrix[k][j];
                }
                mult[i][j] = sum;
            }
        }
        
        Matrix<num,rows,cols2> M(mult);
        return M;
    };
    
    /**
    * Class method that overloads the multiplication operator to allow a Matrix
    * to be multiplied by a constant
    * 
    * @param val is the number every entry of the Matrix will be multiplied by
    * 
    * @return a new Matrix object that is the given Matrix multiplied by val
    */

    Matrix<num,rows,cols> operator* (const num val) {
        num result[rows][cols];
        
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                result[i][j] = _matrix[i][j] * val;
            }
        }
        Matrix<num,rows,cols> mult(result);
        return mult;
    }

    /**
    * Class method that overloads the =* operator to allow a Matrix to be multiplied by a constant
    * 
    * @param val is the number every entry of the Matrix will be multiplied by
    * 
    * @return Matrix, which is the same matrix multiplied by val
    */
    
    Matrix<num,rows,cols> operator*= (const num val) {
        
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                _matrix[i][j] = _matrix[i][j] * val;
            }
        }
        return *this;
    }

    /**
    * Class method that prints the entries of the Matrix
    */
    
    void print() {
            for (size_t i = 0; i < rows; i++) {
                for (size_t j = 0; j < cols; j++) {
                    cout << _matrix[i][j] << " ";
                }
                cout << endl;
            }
        cout << endl;
    }

    /**
    * Class method that returns the row size of the Matrix
    * 
    * @return _r the row size of the Matrix
    */
    
    size_t row_size() {
        return _r;
    }

    /**
    * Class method that returns the column size of the Matrix
    * 
    * @return _c the column size of the Matrix
    */
    
    size_t col_size() {
        return _c;
    }

    
};
