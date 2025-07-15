#include <iostream>

class ResistenciaElectrica {
private:
    double valor;

public:
    ResistenciaElectrica(double v) : valor(v) {}

    double getValor() const {
        return valor;
    }

    ResistenciaElectrica sumaSerie(const ResistenciaElectrica& otraResistencia) const {
        return ResistenciaElectrica(valor + otraResistencia.valor);
    }

    ResistenciaElectrica sumaParalelo(const ResistenciaElectrica& otraResistencia) const {
        if (valor == 0 && otraResistencia.valor == 0) {
            return ResistenciaElectrica(0); // Handle the case where both are 0 to avoid division by zero
        }
        if (valor == 0) {
            return otraResistencia; // If one is 0, the parallel resistance is the other
        }
        if (otraResistencia.valor == 0) {
            return *this; // If one is 0, the parallel resistance is the other
        }
        return ResistenciaElectrica(1.0 / (1.0 / valor + 1.0 / otraResistencia.valor));
    }
};

int main() {
    double val1, val2;

    std::cout << "Ingrese el valor de la primera resistencia (en ohmios): ";
    std::cin >> val1;

    std::cout << "Ingrese el valor de la segunda resistencia (en ohmios): ";
    std::cin >> val2;

    ResistenciaElectrica r1(val1);
    ResistenciaElectrica r2(val2);

    ResistenciaElectrica serie = r1.sumaSerie(r2);
    ResistenciaElectrica paralelo = r1.sumaParalelo(r2);

    std::cout << "Resistencia en serie: " << serie.getValor() << " ohmios" << std::endl;
    std::cout << "Resistencia en paralelo: " << paralelo.getValor() << " ohmios" << std::endl;

    std::cout << "Presione una tecla para continuar . . ." << std::endl;
    std::cin.ignore(); // Consume the newline character left by previous std::cin
    std::cin.get();    // Wait for a key press

    return 0;
}