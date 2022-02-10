#include <iostream>

using namespace std;

class Matrix {
   private:
    double mat[10][10];

   public:
    Matrix() {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                mat[i][j] = 0;
            }
        }
    }

    Matrix(Matrix &other) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                mat[i][j] = other.mat[i][j];
            }
        }
    }

    virtual ~Matrix() {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                mat[i][j] = 0;
            }
        }
    }

    // Getter
    virtual double get(int row, int col) const { return mat[row][col]; }

    // Setter
    virtual void set(int row, int col, double value) { mat[row][col] = value; }

    // Add another matrix to this one - modifying this matrix
    virtual void add(const Matrix &other) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                mat[i][j] += other.mat[i][j];
            }
        }
    }

    // Compare this matrix against another for equality
    virtual bool operator==(const Matrix &other) const {
        int eqNo = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (mat[i][j] == other.mat[i][j]) {
                    eqNo++;
                }
            }
        }
        if (eqNo == 100) {
            return true;
        } else {
            return false;
        }
    };

    void print() {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                cout << mat[i][j] << " ";
            }

            cout << endl;
        }
    }
};