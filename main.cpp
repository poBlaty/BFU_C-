#include <iostream>
#include <string>

using std::cout;
using std::string;

namespace mt {
    class BigInt {

        int *num;
        int sizeNum;
        bool is_negative;

    public:

        //Базовый конструктор
        BigInt() {
            this->num = nullptr;
            this->sizeNum = 0;
            this->is_negative = false;
        }

        BigInt(const string &bignum) {
            if (bignum[0] == '-') {
                is_negative = true;
                sizeNum = size(bignum) - 1;
                num = new int[sizeNum];
                for (int i = 0; i < sizeNum; i++) {
                    num[i] = bignum[i + 1] - '0';
                }
            } else {
                is_negative = false;
                sizeNum = size(bignum);
                num = new int[sizeNum];
                for (int i = 0; i < sizeNum; i++) {
                    num[i] = bignum[i] - '0';
                }
            }
        }

        //Конструктор копирования (если необходим)
        BigInt(const BigInt &other) {
            this->sizeNum = other.sizeNum;
            this->is_negative = other.is_negative;
            this->num = new int[this->sizeNum];
            for (int i = 0; i < this->sizeNum; i++) {
                this->num[i] = other.num[i];
            }
        }

        //Оператор присваивания копированием (если необходим)
        BigInt &operator=(const BigInt &other) {
            if (this != &other) {
                delete[] this->num;

                this->sizeNum = other.sizeNum;
                this->is_negative = other.is_negative;
                this->num = new int[this->sizeNum];
                for (int i = 0; i < this->sizeNum; i++) {
                    this->num[i] = other.num[i];
                }
            }
            return *this;
        }

        //Деструктор (если необходим)
        ~BigInt() {
            delete[] num;
        }

        //Операторы <, >, ==, !=
        bool operator<(BigInt &other) {
            if (this->is_negative != other.is_negative) { return this->is_negative; }

            if (this->sizeNum != other.sizeNum) {
                if (this->is_negative) {
                    return this->sizeNum > other.sizeNum;
                } else {
                    return this->sizeNum < other.sizeNum;
                }
            }

            if (this->is_negative) {
                for (int i = 0; i < sizeNum; i++) {
                    if (this->num[i] > other.num[i]) { return true; }
                }
            } else {
                for (int i = 0; i < sizeNum; i++) {
                    if (this->num[i] < other.num[i]) { return true; }
                }
            }
            return false;
        }

        bool operator>(BigInt &other) {
            return other < *this;
        }

        bool operator==(BigInt &other) {
            return !(*this < other) && !(other < *this);
        }

        bool operator!=(BigInt &other) {
            return !(*this == other);
        }

        //Операторы + и +=
        BigInt operator+(BigInt &other) {
            BigInt sum;
            if (this->is_negative == other.is_negative) {
                sum.sizeNum = std::max(sizeNum, other.sizeNum) + 1;
                sum.num = new int[sum.sizeNum];
                int next = 0;
                int add;
                for (int i = 0; i < sum.sizeNum; i++) {
                    add = next;
                    if (i < this->sizeNum) {
                        add += this->num[i];
                    }
                    if (i < other.sizeNum) {
                        add += other.num[i];
                    }
                    sum.num[i] = add % 10;
                    next = add / 10;
                }
                sum.is_negative = this->is_negative;
            } else {
                sum.sizeNum = std::max(this->sizeNum, other.sizeNum);
                sum.num = new int[sum.sizeNum];

                BigInt bigger = other;
                BigInt smaller = *this;
                if (this->sizeNum > other.sizeNum) {
                    bigger = *this;
                    smaller = other;
                } else if (this->sizeNum == other.sizeNum) {
                    for (int i = 0; i < this->sizeNum; i++) {
                        if (this->num[i] > other.num[i]) {
                            bigger = *this;
                            smaller = other;
                        }
                    }
                }

                for (int i = 0; i < sum.sizeNum; i++) {

                    if (i < (sum.sizeNum - smaller.sizeNum)) {
                        sum.num[i] = bigger.num[i];
                        continue;
                    }
                    if (bigger.num[i] - smaller.num[i + smaller.sizeNum - sum.sizeNum] < 0) {
                        for (int j = 1; j <= i; j++) {
                            if (bigger.num[i - j] != 0) {
                                bigger.num[i] += 10;
                                bigger.num[i - j] -= 1;
                            } else {
                                bigger.num[i - j] = 9;
                            }
                        }
                    }
                    sum.num[i] = bigger.num[i] - smaller.num[i + smaller.sizeNum - sum.sizeNum];
                }
                sum.is_negative = (bigger.is_negative > smaller.is_negative);
                if (sum.num[sum.sizeNum - 1] == 0) { // если финальная цифра ноль, то уменьшить длину
                    --sum.sizeNum;
                }
            }

            return sum;
        }

        BigInt &operator+=(BigInt &other) {
            *this = *this + other;
            return *this;
        }


        //Операторы ввода и вывода в поток
        friend std::ostream &operator<<(std::ostream &out, BigInt &other);

        friend std::istream &operator>>(std::istream &in, BigInt &other);

    };

    std::ostream &operator<<(std::ostream &out, BigInt &other) {
        if (other.is_negative) {
            out << '-';
        }
        for (int i = 0; i < other.sizeNum; i++) {
            out << other.num[i];
        }
        return out;
    }

    std::istream &operator>>(std::istream &in, BigInt &other) {
        std::string value;
        in >> value;
        other = BigInt(value);
        return in;
    }

}

int main() {
    mt::BigInt b("-23465");
    mt::BigInt a("23465454875768967");
    mt::BigInt c = a + b;
    a += b;
    cout << c << std::endl;
    cout << a << std::endl;
    return 0;
}
