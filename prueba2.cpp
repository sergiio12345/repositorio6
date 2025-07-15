#include <iostream>
#include <string>
using namespace std;

class CuentaBancaria {
private:
    string titular;
    double saldo;
    int numeroCuenta;
    int transaccionesDelDia;

public:
    // Constructor
    CuentaBancaria(string t, double s, int numCuenta) {
        titular = t;
        saldo = s;
        numeroCuenta = numCuenta;
        transaccionesDelDia = 0;
    }

    // Método para depositar dinero
    void depositar(double monto) {
        if (monto > 0) {
            saldo += monto;
            cout << "Depósito de " << monto << " realizado exitosamente." << endl;
        } else {
            cout << "El monto a depositar debe ser positivo." << endl;
        }
    }

    // Método para retirar dinero
    void retirar(double monto) {
        if (monto > 0 && saldo >= monto && transaccionesDelDia < 3) {
            saldo -= monto;
            transaccionesDelDia++;
            cout << "Retiro de " << monto << " realizado exitosamente." << endl;
        } else if (monto <= 0) {
            cout << "El monto a retirar debe ser positivo." << endl;
        } else if (saldo < monto) {
            cout << "Fondos insuficientes para realizar el retiro." << endl;
        } else if (transaccionesDelDia >= 3) {
            cout << "Ya ha alcanzado el límite de 3 retiros por día." << endl;
        }
    }

    // Método para mostrar los detalles de la cuenta
    void mostrarSaldo() {
        cout << "Resumen de la cuenta:" << endl;
        cout << "Titular: " << titular << endl;
        cout << "Número de cuenta: " << numeroCuenta << endl;
        cout << "Saldo actual: " << saldo << endl;
        cout << "Retiros realizados hoy: " << transaccionesDelDia << " de 3 permitidos" << endl;
    }

    // Método para reiniciar el contador de transacciones del día
    void resetearTransacciones() {
        transaccionesDelDia = 0;
        cout << "Las transacciones del día han sido reiniciadas." << endl;
    }
};

int main() {
    CuentaBancaria cuenta("Carlos García", 500.0, 123456);
    int opcion;
    double monto;

    do {
        // Mostrar menú
        cout << "\nMenú de opciones:\n";
        cout << "1. Depositar\n";
        cout << "2. Retirar\n";
        cout << "3. Mostrar saldo\n";
        cout << "4. Reiniciar transacciones del día\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el monto a depositar: ";
                cin >> monto;
                cuenta.depositar(monto);
                break;
            case 2:
                cout << "Ingrese el monto a retirar: ";
                cin >> monto;
                cuenta.retirar(monto);
                break;
            case 3:
                cuenta.mostrarSaldo();
                break;
            case 4:
                cuenta.resetearTransacciones();
                break;
            case 5:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
        }
    } while (opcion != 5);

    return 0;
}
