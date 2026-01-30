// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;



class Gauss {
public:
    int re, im;

    Gauss(int r = 0, int i = 0) : re(r), im(i) {}

    Gauss operator+(const Gauss& other) const {
        return Gauss(re + other.re, im + other.im);
    }

    Gauss operator-(const Gauss& other) const {
        return Gauss(re - other.re, im - other.im);
    }

    Gauss operator*(const Gauss& other) const {
        return Gauss(re * other.re - im * other.im, re * other.im + im * other.re);
    }

    Gauss operator/(const Gauss& other) const {
        int den = other.re * other.re + other.im * other.im;
        return Gauss((re * other.re + im * other.im) / den, (im * other.re - re * other.im) / den);
    }

    bool operator==(const Gauss& other) const {
        return re == other.re && im == other.im;
    }

    friend std::ostream& operator<<(std::ostream& os, const Gauss& g) {
        os << g.re << (g.im >= 0 ? "+" : "") << g.im << "i";
        return os;
    }
};





template<typename T>
class Fractie {
private:
    T numarator, numitor;

    void simplifica() {
        // Opțional: implementare pentru întregi
        // Nu avem o funcție generală pentru GCD la tipuri generice
    }

public:
    Fractie(const T& num = T(0), const T& den = T(1)) : numarator(num), numitor(den) {}

    Fractie& operator=(const Fractie& other) {
        if (this != &other) {
            numarator = other.numarator;
            numitor = other.numitor;
        }
        return *this;
    }

    bool operator==(const Fractie& other) const {
        return numarator * other.numitor == numitor * other.numarator;
    }

    Fractie operator+(const Fractie& other) const {
        return Fractie(numarator * other.numitor + other.numarator * numitor, numitor * other.numitor);
    }

    Fractie operator-(const Fractie& other) const {
        return Fractie(numarator * other.numitor - other.numarator * numitor, numitor * other.numitor);
    }

    Fractie operator*(const Fractie& other) const {
        return Fractie(numarator * other.numarator, numitor * other.numitor);
    }

    Fractie operator/(const Fractie& other) const {
        return Fractie(numarator * other.numitor, numitor * other.numarator);
    }

    Fractie operator-() const {
        return Fractie(-numarator, numitor);
    }

    operator T() const {
        return numarator / numitor;
    }

    friend std::ostream& operator<<(std::ostream& os, const Fractie& f) {
        os << "(" << f.numarator << "/" << f.numitor << ")";
        return os;
    }
};



int main()
{
    Fractie<int> f1(3, 4), f2(3, 4);
    std::cout << "f1 + f2 = " << f1 + f2 << "\n";

    Gauss g1(1, 2), g2(3, -1);
    Fractie<Gauss> fg1(g1, g2);
    Fractie<Gauss> fg2(Gauss(2, 0), Gauss(1, 1));
    std::cout << "fg1 * fg2 = " << fg1 * fg2 << "\n";

    Gauss rezultat = static_cast<Gauss>(fg1); // conversie la tipul T
    std::cout << "fg1 ca Gauss: " << rezultat << "\n";



	return 0;
}


