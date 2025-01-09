#include <iostream>
using namespace std;

struct fraction {
private:
    int *_numerator = nullptr;
    int *_denominator = nullptr;
public:

    // constructor
    fraction(int numerator = 0, int denominator = 1) {
        setNumerator(numerator);
        if (denominator == 0) {
            cout << "Denominator cannot be zero. Setting to 1." << endl;
            denominator = 1;
        }
        setDenominator(denominator);
    }

    // getter
    int getNumerator() const {
        return (_numerator == nullptr) ? 0 : *_numerator;
    }

    // getter
    int getDenominator() const {
        return (_denominator == nullptr) ? 0 : *_denominator;
    }

    // setter
    void setNumerator(int numerator) {
        if (_numerator != nullptr) {
            delete _numerator;
        }
        _numerator = new int{numerator};
    }

    // setter
    void setDenominator(int denominator) {
        if (_denominator != nullptr) {
            delete _denominator;
        }
        _denominator = new int{denominator};
    }

    // destructor
    ~fraction() {
        delete _numerator;
        delete _denominator;
    }
};

// Додавання дробів
fraction add(const fraction &a, const fraction &b) {
    int num1 = a.getNumerator() * b.getDenominator() + b.getNumerator() * a.getDenominator(); // Чисельник результату
    int num2 = a.getDenominator() * b.getDenominator(); // Спільний знаменник

    return fraction(num1, num2);
}

// Віднімання дробів
fraction subtract(const fraction &a, const fraction &b) {
    int num1 = a.getNumerator() * b.getDenominator() - b.getNumerator() * a.getDenominator();
    int num2 = a.getDenominator() * b.getDenominator();

    return fraction(num1, num2);
}

// Множення дробів
fraction multiply(const fraction &a, const fraction &b) {
    int num1 = a.getNumerator() * b.getNumerator();
    int num2 = a.getDenominator() * b.getDenominator();

    return fraction(num1, num2);
}

// Ділення дробів
fraction divide(const fraction &a, const fraction &b) {
    if (b.getNumerator() == 0) {
        cout << "Division by zero is undefined. Returning the first fraction." << endl;
        return a;
    }
    int num1 = a.getNumerator() * b.getDenominator();
    int num2 = a.getDenominator() * b.getNumerator();

    return fraction(num1, num2);
}

// Функція для обчислення НСД
int NCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Скорочення дробу
fraction abbreviation(const fraction &a) {
    int num = a.getNumerator();
    int den = a.getDenominator();
    int g = NCD(abs(num), abs(den)); // Обчислюємо НСД

    return fraction(num / g, den / g);
}


void menu() {
    cout << "\nMenu:\n";
    cout << "1. Add fractions\n";
    cout << "2. Subtract fractions\n";
    cout << "3. Multiply fractions\n";
    cout << "4. Divide fractions\n";
    cout << "5. Abbreviation fraction\n";
    cout << "5. Exit\n";
}

int main() {
    fraction a(1, 4);
    fraction b(2, 8);

    cout << " First fraction: " << a.getNumerator() << " / " << a.getDenominator() << endl;
    cout << " Second fraction: " << b.getNumerator() << " / " << b.getDenominator() << endl;

    while (true) {
        menu();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << a.getNumerator() << " / " << a.getDenominator() << " + ";
                cout << b.getNumerator() << " / " << b.getDenominator() << " = ";
                cout << add(a, b).getNumerator() << " / " << add(a, b).getDenominator() << endl;
                break;
            case 2:
                cout << a.getNumerator() << " / " << a.getDenominator() << " - ";
                cout << b.getNumerator() << " / " << b.getDenominator() << " = ";
                cout << subtract(a, b).getNumerator() << " / " << subtract(a, b).getDenominator() << endl;
                break;
            case 3:
                cout << a.getNumerator() << " / " << a.getDenominator() << " * ";
                cout << b.getNumerator() << " / " << b.getDenominator() << " = ";
                cout << multiply(a, b).getNumerator() << " / " << multiply(a, b).getDenominator() << endl;
                break;
            case 4:
                cout << a.getNumerator() << " / " << a.getDenominator() << " : ";
                cout << b.getNumerator() << " / " << b.getDenominator() << " = ";
                cout << divide(a, b).getNumerator() << " / " << divide(a, b).getDenominator() << endl;
                break;
            case 5:
                cout << abbreviation(a).getNumerator() << " / " << abbreviation(a).getDenominator();
            case 6:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}