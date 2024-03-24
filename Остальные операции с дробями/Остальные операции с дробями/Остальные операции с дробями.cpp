#include <iostream>
#include <algorithm>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        reduce();
    }

    void reduce() {
        int divisor = gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;
    }

    Fraction operator+(const Fraction& other) const {
        int new_num = numerator * other.denominator + other.numerator * denominator;
        int new_denom = denominator * other.denominator;
        return Fraction(new_num, new_denom);
    }

    Fraction operator-(const Fraction& other) const {
        int new_num = numerator * other.denominator - other.numerator * denominator;
        int new_denom = denominator * other.denominator;
        return Fraction(new_num, new_denom);
    }

    Fraction operator*(const Fraction& other) const {
        int new_num = numerator * other.numerator;
        int new_denom = denominator * other.denominator;
        return Fraction(new_num, new_denom);
    }

    Fraction operator/(const Fraction& other) const {
        int new_num = numerator * other.denominator;
        int new_denom = denominator * other.numerator;
        return Fraction(new_num, new_denom);
    }

    Fraction operator-() const {
        return Fraction(-numerator, denominator);
    }

    Fraction& operator++() {
        numerator += denominator;
        reduce();
        return *this;
    }

    Fraction operator++(int) {
        Fraction temp = *this;
        ++(*this);
        return temp;
    }

    Fraction& operator--() {
        numerator -= denominator;
        reduce();
        return *this;
    }

    Fraction operator--(int) {
        Fraction temp = *this;
        --(*this);
        return temp;
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
        os << frac.numerator << "/" << frac.denominator;
        return os;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    int num1, denom1, num2, denom2;
    std::cout << "Введите числитель дроби 1: ";
    std::cin >> num1;
    std::cout << "Введите знаменатель дроби 1: ";
    std::cin >> denom1;
    std::cout << "Введите числитель дроби 2: ";
    std::cin >> num2;
    std::cout << "Введите знаменатель дроби 2: ";
    std::cin >> denom2;

    Fraction frac1(num1, denom1);
    Fraction frac2(num2, denom2);

    std::cout << frac1 << " + " << frac2 << " = " << frac1 + frac2 << std::endl;
    std::cout << frac1 << " - " << frac2 << " = " << frac1 - frac2 << std::endl;
    std::cout << frac1 << " * " << frac2 << " = " << frac1 * frac2 << std::endl;
    std::cout << frac1 << " / " << frac2 << " = " << frac1 / frac2 << std::endl;

    std::cout << "++" << frac1 << " * " << frac2 << " = " << ++frac1 * frac2 << std::endl;
    std::cout << "Значение дроби 1 = " << frac1 << std::endl;

    std::cout << frac1 << "-- * " << frac2 << " = " << frac1-- * frac2 << std::endl;
    std::cout << "Значение дроби 1 = " << frac1 << std::endl;

    return 0;
}