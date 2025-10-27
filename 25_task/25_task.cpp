#include <iostream>
using namespace std;

class Geometry{
private:
    static int count;

    //new tone
    static double mySqrt(double x) {
        if (x <= 0) return 0;
        double guess = x / 2.0;
        for (int i = 0; i < 20; i++) {
            guess = (guess + x / guess) / 2.0;
        }
        return guess;
    }

public:
    //s trik osn vis
    static double trikutnik(double base, double height) {
        count++;
        return 0.5 * base * height;
    }

    //s trik 3 stor geron formula
    static double trikutnik(double a, double b, double c) {
        count++;
        double p = (a + b + c) / 2.0;
        double s = p * (p - a) * (p - b) * (p - c);
        if (s <= 0) return 0;
        return mySqrt(s);
    }

    //s priam
    static double priamokutnik(double length, double width) {
        count++;
        return length * width;
    }

    //s qvad
    static double kvadrat(double side) {
        count++;
        return side * side;
    }

    //s romb 2 diag
    static double romb(double d1, double d2) {
        count++;
        return (d1 * d2) / 2.0;
    }


    static int getCount() {
        return count;
    }
};


int Geometry::count = 0;

int main() {
    cout << "Trikutnik (osnova, visota): " << Geometry::trikutnik(10, 5) << endl;
    cout << "Trikutnik (storoni): " << Geometry::trikutnik(3, 4, 5) << endl;
    cout << "Priamokutnik: " << Geometry::priamokutnik(4, 6) << endl;
    cout << "Kvadrat: " << Geometry::kvadrat(5) << endl;
    cout << "Romb: " << Geometry::romb(6, 8) << endl;

    cout << "\nTotal calculations: " << Geometry::getCount() << endl;

    return 0;
}
