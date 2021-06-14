/**
 * @file
 * @author  Matiss Senkans <senkans.matiss@gmail.com>
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * The matrix library implements matrix transpose, multiplication
 * and addition.
 */

template <typename T, size_t rows, size_t cols>

class Matrix {
public:
    
    typedef T RowType[cols];
    typedef RowType MatrixType[rows];

    /**
    * Constructor that declares a matrix of a given size with
    * all of the entries set to 0.
    */
    
    Matrix() {
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                matrix_[i][j] = 0;
            }
        }
    }

    /**
    * Constructor that initializes a matrix given a 2D array.
    * 
    * @param matrix is a 2D array that we want to use as a matrix
    */
    
    Matrix (const MatrixType &matrix) {
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                matrix_[i][j] = matrix[i][j];
                
            }
        }
    }
    
    /**
    * Class method that returns the transpose of the matrix object.
    * 
    * @return Matrix object that is the transpose of the current matrix.
    */

    Matrix<T, cols, rows> transpose() {
        T trans_mat[cols][rows];
        
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                trans_mat[j][i] = matrix_[i][j];
            }
        }
        
        Matrix<T,cols,rows> t(trans_mat);
        return t;
    }

    /**
    * Class method that sets the matrix value in the provided location.
    * 
    * @param val is the desired value to be set.
    * @param i is the index of the row for the value
    * @param j is the index of the column for the value
    */
    void setij(T val, size_t i, size_t j) {
        matrix_[i][j] = val;
    }

    /**
    * Class method that returns the matrix value in the provided location.
    * 
    * @param i is the index of the row for the value
    * @param j is the index of the column for the value
    * 
    * @return the value in the requested index
    */
    T getij(size_t i, size_t j) {
        return matrix_[i][j];
    }

    /**
    * Class method that overloads the addition operator to allow matrix addition
    * 
    * @param matrix is the matrix that is added to the current Matrix
    * 
    * @return a new Matrix object that is the sum of the given two matrices
    */
    Matrix<T,rows,cols> operator+ (Matrix<T,rows,cols> &matrix) {
        T mat3[rows][cols];
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                mat3[i][j] = matrix_[i][j] + matrix.matrix_[i][j];
            }
        }
        Matrix<T,rows,cols> sum(mat3);
        return sum;
    }

    /**
    * Class method that overloads the subtraction operator to allow matrix subtraction
    * 
    * @param matrix is the matrix that is subtracted from the current Matrix
    * 
    * @return a new Matrix object that is the difference between the given two matrices
    */

    Matrix<T,rows,cols> operator- (const Matrix<T,rows,cols> &matrix) {
        T mat3[rows][cols];
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                mat3[i][j] = matrix_[i][j] - matrix.matrix_[i][j];
            }
        }
        Matrix<T,rows,cols> diff(mat3);
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
    Matrix<T,rows,cols2> operator* (Matrix<T,cols,cols2> &matrix) {
        T mult[rows][cols2];
        T sum;
        
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols2; j++) {
                sum = 0;
                for (size_t k = 0; k < cols; k++) {
                    sum += matrix_[i][k] * matrix.getij(k,j);
                }
                mult[i][j] = sum;
            }
        }
        
        Matrix<T,rows,cols2> M(mult);
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

    Matrix<T,rows,cols> operator* (const T val) {
        T result[rows][cols];
        
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                result[i][j] = matrix_[i][j] * val;
            }
        }
        Matrix<T,rows,cols> mult(result);
        return mult;
    }

    /**
    * Class method that overloads the =* operator to allow a Matrix to be multiplied by a constant
    * 
    * @param val is the number every entry of the Matrix will be multiplied by
    * 
    * @return Matrix, which is the same matrix multiplied by val
    */
    
    Matrix<T,rows,cols> operator*= (const T val) {
        
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                matrix_[i][j] = matrix_[i][j] * val;
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
                    std::cout << matrix_[i][j] << " ";
                }
                std::cout << std::endl;
            }
        std::cout << std::endl;
    }

    /**
    * Class method that returns the row size of the Matrix
    * 
    * @return _r the row size of the Matrix
    */
    
    size_t row_size() {
        return rows;
    }

    /**
    * Class method that returns the column size of the Matrix
    * 
    * @return _c the column size of the Matrix
    */
    
    size_t col_size() {
        return cols;
    }

private:
    MatrixType matrix_;

    
};
