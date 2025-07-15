#include <iostream>
using namespace std;

class Sensor {
private:
    string ID;
    double frecuencia;

public:
    Sensor(string, double);
    virtual void simularLectura() {}
    virtual void mostrarDatos();
};

class SensorTemperatura : public Sensor {
private:
    double lectura;

public:
    SensorTemperatura(string,double,double);
    void mostrarDatos();
};

class SensorDistancia : public Sensor {
private:
    double lectura;

public:
    SensorDistancia(string, double, double);
    void mostrarDatos();
};

class SensorMoviemiento : public Sensor {
private:
    double x, y, z;

public:
    SensorMoviemiento(string, double, double, double, double);
    void simularLectura();
    void mostrarDatos();
};

Sensor::Sensor(string _id, double _frec) {
    ID = _id;
    frecuencia = _frec;
}

void Sensor::mostrarDatos() {
    cout << "ID: " << ID << ", Frecuencia: " << frecuencia << endl;
}

SensorTemperatura::SensorTemperatura(string _id, double _frec, double _lectura)
    : Sensor(_id, _frec), lectura(_lectura) {}

void SensorTemperatura::mostrarDatos() {
    Sensor::mostrarDatos();
    cout << "Lectura temperatura: " << lectura << "°C" << endl;
}

SensorDistancia::SensorDistancia(string _id, double _frec, double _lectura)
    : Sensor(_id, _frec), lectura(_lectura) {}

void SensorDistancia::mostrarDatos() {
    Sensor::mostrarDatos();
    cout << "Lectura distancia: " << lectura << "m" << endl;
}

SensorMoviemiento::SensorMoviemiento(string _id, double _frec, double _x, double _y, double _z)
    : Sensor(_id, _frec), x(_x), y(_y), z(_z) {}

void SensorMoviemiento::simularLectura() {
    x += 0.01;
    y += 0.01;
    z += 0.01;
}

void SensorMoviemiento::mostrarDatos() {
    Sensor::mostrarDatos();
    cout << "Movimiento - x: " << x << ", y: " << y << ", z: " << z << endl;
}

int main() {
    cout << "--------------" << endl;

    Sensor* sensores[4];

    sensores[0] = new SensorTemperatura("T-001", 1.00, 22.8);
    sensores[1] = new SensorDistancia("D-102", 0.50, 5.34);
    sensores[2] = new SensorMoviemiento("M-500", 2.00, 0.12, 0.02, 0.00);
    sensores[3] = new SensorMoviemiento("M-501", 2.00, 0.15, 0.05, 0.01);

    for (int i = 0; i < 4; i++) {
        sensores[i]->mostrarDatos();
        sensores[i]->simularLectura(); // Solo afecta a SensorMovimiento
    }
    sensores[1] -> mostrarDatos();

    for (int i = 0; i < 4; i++) {
        delete sensores[i];
    }

    return 0;
}
