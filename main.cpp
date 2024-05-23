#include <iostream>
#include <stdexcept>

using std::cout;

namespace mt {
    class String {
        char *string;
        size_t len;

    public:
        //Базовый конструктор
        String(const char *str) {
            len = strlen(str) + 1;
            string = new char[len];
            std::copy(str, str + len, string);
        }

        //Конструктор копирования (правило 3-х)
        String(const String &other) {
            this->len = other.len;
            this->string = new char[this->len];
            std::copy(other.string, other.string + len, this->string);
        }

        //Оператор присваивания копированием (правило 3-х)
        String &operator=(const String &other) {
            if (this != &other) {
                delete[] this->string;

                this->len = other.len;
                this->string = new char[this->len];
                std::copy(other.string, other.string + len, this->string);

                return *this;
            }
        }


        // Оператор +=
        String &operator+=(const String &other) {
            String New(*this);

            delete[] this->string;
            this->len += other.len - 1;
            this->string = new char[this->len];
            std::copy(New.string, New.string + New.len, this->string);
            strcat(this->string, other.string);

            return *this;
        }

        //Оператор +
        String operator+(const String &other) {

            String New(*this);
            New += other;
            return New;
        }

        //Оператор []
        char &operator[](int index) {
            return string[index];
        }

        //Операторы <
        bool operator<(const String &other) {
            if (this->len >= other.len) { return false; }
            return true;
        }

        //Операторы >
        bool operator>(const String &other) {
            if (this->len <= other.len) { return false; }
            return true;
        }

        //Операторы ==
        bool operator==(const String &other) {
            if (this->len != other.len) { return false; }

            for (int i = 0; i < this->len; i++) {
                if (this->string != other.string) { return false; }
            }
            return true;
        }

        //Деструктор (правило 3-х)
        ~String() {
            delete[] string;
        }

        //Метод find – поиск первого вхождения символа в строку слева
        int find(char letter) {
            for (int i = 0; i < len; i++) {
                if (string[i] == letter) { return i; }
            }
            return -1;
        }

        // Метод length – длина строки
        size_t length(){
            return len;
        }


        //Метод c_str – получить массив char
        char **c_str(){
            return &string;
        }

        //Метод at для получения доступа (чтение и изменение) к элементу строки с проверкой на выход за пределы строки
        char &at(int index){
            if (index >= len){throw std::invalid_argument{"vishli za pdeli nu nu nu"};}
            return string[index];
        }

        //Операторы ввода и вывода в поток
        friend std::iostream &operator>>(std::iostream &in, const String &str);

        friend std::ostream &operator<<(std::ostream &in, const String &str);
    };

    std::iostream &operator>>(std::iostream &in, const String &str) {
        std::cin >> str.string;
        return in;
    }

    std::ostream &operator<<(std::ostream &out, const String &str) {
        out << str.string;
        return out;
    }

}

int main() {
    mt::String M = "asjgdh";
    mt::String G = "ajshkg";
    mt::String F = G + M;
    cout << (M < G);
    cout << M.c_str();
    cout << G.at(4);
    G.at(4) = 'z';
    cout << G.at(4);
    return 0;
}
