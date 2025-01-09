#include <iostream>
#include <iomanip>
using namespace std;

struct rectangle {
private:
    int *_h = nullptr;
    int *_w = nullptr;

public:
    int getH() const { // getter H
        return (_h == nullptr) ? 0 : *_h;
    }

    int getW() const { // getter W
        return (_w == nullptr) ? 0 : *_w;
    }

    void setH(int h) { // setter H
        if (_h != nullptr) {
            delete _h;
        }
        _h = new int{h};
    }

    void setW(int w) { // setter W
        if (_w != nullptr) {
            delete _w;
        }
        _w = new int{w};
    }

    // Деструктор для очищення пам'яті
    ~rectangle() {
        delete _h;
        delete _w;
    }
};

// Функція для малювання прямокутника
void printRectangle(int height, int width) {
    if (height <= 0 || width <= 0) {
        cout << "Invalid input" << endl;
        return;
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                cout << setw(4) << "+";
            } else {
                cout << setw(4) << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

// Функція для переміщення прямокутника
void moving(int x, int y, int height, int width) {
    if (x < 0 || y < 0) {
        cout << "Invalid input" << endl;
        return;
    }

    if (height <= 0 || width <= 0) {
        cout << "First, draw a rectangle\n" << endl;

        return;
    }


    for (int i = 0; i < y; i++) {
        cout << endl;
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < x; j++) {
            cout << " ";
        }
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                cout << setw(4) << "+";
            } else {
                cout << setw(4) << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

// Функція для відображення меню
void menu() {
    cout << "1. Draw rectangle" << endl;
    cout << "2. Move rectangle" << endl;
    cout << "3. Exit" << endl;
}

int main() {
    int height = 0, width = 0;
    rectangle r;

    while (true) {
        menu();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter height: ";
                cin >> height;

                cout << "Enter width: ";
                cin >> width;

                r.setH(height);
                r.setW(width);

                cout << "Rectangle drawn:" << endl;
                printRectangle(height, width);
                break;
            }
            case 2: {
                int x, y;
                cout << "Enter x offset: ";
                cin >> x;
                cout << "Enter y offset: ";
                cin >> y;

                moving(x, y, r.getH(), r.getW());
                break;
            }
            case 3:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}