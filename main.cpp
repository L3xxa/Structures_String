#include <iostream>
#include <cmath>
using namespace std;

struct point {
private:
    int *_x = nullptr;
    int *_y = nullptr;
public:
    point() = default;

    point(int x, int y) {
        _x = new int(x);
        _y = new int(y);
    }

    ~point() {
        delete _x;
        delete _y;
    }

    int getX() const { // getterX
        return (_x == nullptr) ? 0 : *_x;
    }

    int getY() const { // getterY
        return (_y == nullptr) ? 0 : *_y;
    }

    void setX(int x) { // setterX
        if (_x != nullptr) {
            delete _x;
        }
        _x = new int{x};
    }

    void setY(int y) { // setterY
        if (_y != nullptr) {
            delete _y;
        }
        _y = new int{y};
    }
};

void printPoint(const point &p) {
    int x = p.getX();
    int y = p.getY();

    if (x < 0 || y < 0) {
        cout << "Invalid coordinates. Points must have non-negative values." << endl;
        return;
    }

    for (int i = 0; i <= y; i++) {
        for (int j = 0; j <= x; j++) {
            if (i == y && j == x) {
                cout << "*"; // Малюємо точку
            } else {
                cout << " "; // Пробіли перед точкою
            }
        }
        cout << endl;
    }
    cout << endl;
}

double distance(int Xa, int Ya, int Xb, int Yb) {
    int dx = Xb - Xa;
    int dy = Yb - Ya;

    double AB = sqrt(dx * dx + dy * dy);
    return AB;
}

int main() {
    point a, b;

    // Перша точка
    int Xa;
    cout << "Enter Xa: ";
    cin >> Xa;
    int Ya;
    cout << "Enter Ya: ";
    cin >> Ya;
    a.setX(Xa);
    a.setY(Ya);

    // Друга точка
    int Xb;
    cout << "Enter Xb: ";
    cin >> Xb;
    int Yb;
    cout << "Enter Yb: ";
    cin >> Yb;
    b.setX(Xb);
    b.setY(Yb);

    printPoint(a);
    printPoint(b);

    cout << "Distance between two points: " << distance(Xa, Ya, Xb, Yb) << endl;

    return 0;
}
