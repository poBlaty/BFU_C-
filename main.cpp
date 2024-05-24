#include <iostream>
#include <string>

//N = row;
//M = column;

template<typename T, int N, int M>
class Matrix {

    T matrix[N][M];

public:
    Matrix() = default;

    Matrix(const Matrix &other) {}

    T &operator()(int index_i, int index_j) {
        return matrix[index_i][index_j];
    }

    template<int L>
    Matrix<T, N, L> &operator*(Matrix<T, M, L> &other) {
        Matrix<T, N, L> tmp{};
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < L; j++) {
                for (int r = 0; r < M; r++) {
                    //tmp.matrix[i][j] = (this->matrix[i][r] * other.matrix[r][j]);
                    tmp(i, j) += this->matrix[i][r] * other(r, j);
                }
            }
        }
        tmp.read(); //!!!
        return tmp;
    }

    template<int L>
    Matrix<T, N, L> &operator*=(Matrix<T, M, L> &other) {
        *this = *this * other;
        return *this;
    }

    Matrix<T, N, M> &operator*=(T value) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                this->matrix[i][j] *= value;
            }
        }
        return *this;
    }

    Matrix<T, N, M> &operator*(T value) {
        *this *= value;
        return *this;
    }


    Matrix<T, N, M> &operator+=(const Matrix<T, N, M> other) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                this->matrix[i][j] += other.matrix[i][j];
            }
        }
        return *this;
    }

    Matrix<T, N, M> &operator+(const Matrix<T, N, M> other) {
        *this += other;
        return *this;
    }

    Matrix<T, N, M> &operator++() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                this->matrix[i][j]++;
            }
        }
        return *this;
    }

    Matrix<T, N, M> operator++(int) {
        Matrix<T, N, M> tmp = *this;
        operator++();
        return tmp;
    }

    void read() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    T det() {
        if (N != M) {
            std::cout << "The matrix isn't square!" << std::endl;
            throw std::invalid_argument{"The matrix isn't square!"};
        } else if (N == 1) {
            return matrix[0][0];
        } else if (N == 2) {
            return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
        } else {
            auto tmp = *this;
            for (int k = 0; k < N - 1; k++) {
                for (int i = k + 1; i < N; i++) {
                    T value = tmp.matrix[i][k] / tmp.matrix[k][k];
                    for (int j = k; j < M; j++) {
                        tmp.matrix[i][j] -= tmp.matrix[k][j] * value;
                    }
                }
            }
            T sum = tmp.matrix[0][0];
            for (int i = 1; i < N; i++) {
                sum *= tmp.matrix[i][i];
            }
            return sum;
        }
    }

    template<typename T, int N, int M>
    friend std::ostream &operator<<(std::ostream &out, const Matrix<T, N, M> &object);

    template<typename T, int N, int M>
    friend std::istream &operator>>(std::istream &in, Matrix<T, N, M> &object);
};


template<typename T, int N, int M>
std::ostream &operator<<(std::ostream &out, const Matrix<T, N, M> &object) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            out << object.matrix[i][j] << ' ';
        }
        out << '\n';
    }
    return out;
}


template<typename T, int N, int M>
std::istream &operator>>(std::istream &in, Matrix<T, N, M> &object) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            in >> object.matrix[i][j];
        }
    }
    return in;
}

int main() {
    Matrix<int, 2, 1> alpha{};
    alpha(0, 0) = 1;
    alpha(1, 0) = 2;
    Matrix<int, 1, 2> beta{};
    beta(0, 0) = 1;
    beta(0, 1) = 2;
    Matrix<int, 1, 2> eps = beta;
    auto &test = alpha * beta;
    std::cout << test << std::endl;
    /*std::cout << eps << std::endl;
    Matrix<double, 4, 4>gamma{};
    std::cin >> gamma;
    std::cout << gamma.det() << std::endl;*/

}
