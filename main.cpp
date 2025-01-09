#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    int length;
    int wheel;
    int year;
    double clearance;
    double weight;
    double max_speed;
    double engine_volume;
    double fuel_consumption;
    double engine_power;
    string engine;
    string color;
    string brand;
    string gearbox;

public:
    // Constructor
    Car(int l, int w, int y, double c, double we, double max_sp,
        double e_vol, double f_c, double e_pow, string eng, string col,
        string br, string gear)
        : length(l), wheel(w), year(y), clearance(c), weight(we),
          max_speed(max_sp), engine_volume(e_vol), fuel_consumption(f_c),
          engine_power(e_pow), engine(eng), color(col), brand(br), gearbox(gear) {}

    // Setters
    void setLength(int l) { length = l; }
    void setWheel(int w) { wheel = w; }
    void setYear(int y) { year = y; }
    void setClearance(double c) { clearance = c; }
    void setWeight(double we) { weight = we; }
    void setMaxSpeed(double max_sp) { max_speed = max_sp; }
    void setEngineVolume(double e_vol) { engine_volume = e_vol; }
    void setFuelConsumption(double f_c) { fuel_consumption = f_c; }
    void setEnginePower(double e_pow) { engine_power = e_pow; }
    void setEngine(string eng) { engine = eng; }
    void setColor(string col) { color = col; }
    void setBrand(string br) { brand = br; }
    void setGearbox(string gear) { gearbox = gear; }

    // Getters
    int getLength() const { return length; }
    int getWheel() const { return wheel; }
    int getYear() const { return year; }
    double getClearance() const { return clearance; }
    double getWeight() const { return weight; }
    double getMaxSpeed() const { return max_speed; }
    double getEngineVolume() const { return engine_volume; }
    double getFuelConsumption() const { return fuel_consumption; }
    double getEnginePower() const { return engine_power; }
    string getEngine() const { return engine; }
    string getColor() const { return color; }
    string getBrand() const { return brand; }
    string getGearbox() const { return gearbox; }

    // Method to display car details
    void display() const {
        cout << "-----------------------------------" << endl;
        cout << "              Car Details           " << endl;
        cout << "-----------------------------------" << endl;
        cout << "Length:          " << length << " mm" << endl;
        cout << "Wheel:           " << wheel << endl;
        cout << "Year:            " << year << endl;
        cout << "Clearance:       " << clearance << " mm" << endl;
        cout << "Weight:          " << weight << " kg" << endl;
        cout << "Max Speed:       " << max_speed << " km/h" << endl;
        cout << "Engine Volume:   " << engine_volume << " L" << endl;
        cout << "Fuel Consumption:" << fuel_consumption << " L/100km" << endl;
        cout << "Engine Power:    " << engine_power << " HP" << endl;
        cout << "Engine:          " << engine << endl;
        cout << "Color:           " << color << endl;
        cout << "Brand:           " << brand << endl;
        cout << "Gearbox:         " << gearbox << endl;
        cout << "-----------------------------------" << endl;
    }
};

int main() {
    Car myCar(4500, 4, 2022, 200, 1500, 220, 2.0, 8.5, 150, "V8", "Red", "Toyota", "Automatic");

    myCar.display();

    // Set new values
    myCar.setLength(4600);
    myCar.setWheel(4);
    myCar.setYear(2023);
    myCar.setClearance(210);
    myCar.setWeight(1600);
    myCar.setMaxSpeed(240);
    myCar.setEngineVolume(2.5);
    myCar.setFuelConsumption(9.0);
    myCar.setEnginePower(180);
    myCar.setEngine("V6");
    myCar.setColor("Blue");
    myCar.setBrand("Honda");
    myCar.setGearbox("Manual");

    // Display updated car details
    myCar.display();

    return 0;
}