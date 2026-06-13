#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Reserva {
private:
    string codigoReserva;
    string nombreCliente;
    int diasEstadia;
    float costoTotal;

public:
    Reserva(string codigo, string cliente, int dias, float costo);

    // Getters
    string getCodigoReserva() const;
    string getNombreCliente() const;
    int getDiasEstadia() const;
    float getCostoTotal() const;

    void mostrarReserva() const;
};

Reserva::Reserva(string codigo, string cliente, int dias, float costo) {
    this->codigoReserva = codigo;
    this->nombreCliente = nombreCliente;
    this->diasEstadia = dias;
    this->costoTotal = costoTotal;
}

string Reserva::getCodigoReserva() const {
    return this->codigoReserva;
}

string Reserva::getNombreCliente() const {
    return this->nombreCliente;
}

int Reserva::getDiasEstadia() const {
    return this->diasEstadia;
}

float Reserva::getCostoTotal() const {
    return this->costoTotal;
}

void Reserva::mostrarReserva() const {

    cout << "Codigo: " << codigoReserva << endl;
    cout << "Cliente: " << nombreCliente << endl;
    cout << "Dias: " << diasEstadia << endl;
    cout << "Costo Total: " << costoTotal << endl;
    cout << "------------------------" << endl;
}

void merge(vector<Reserva>& reservas, int izquierda, int medio, int derecha) {
    int sizeIzquierda = medio - izquierda + 1;
    int sizeDerecha = derecha - medio;

    vector<Reserva> left;
    vector<Reserva> right;

    for (int i = 0; i < sizeIzquierda; i++) {
        left.push_back(reservas[izquierda + i]);
    }

    for (int j = 0; j < sizeDerecha; j++) {
        right.push_back(reservas[medio + 1 + j]);
    }

    int i = 0;
    int j = 0;
    int k = izquierda;

    while (i < sizeIzquierda && j < sizeDerecha) {

        if (left[i].getCostoTotal() <= right[j].getCostoTotal()) {
            reservas[k] = left[i];
            i++;
        }
        else {
            reservas[k] = right[j];
            j++;
        }

        k++;
    }

    while (i < sizeIzquierda) {
        reservas[k] = left[i];
        i++;
        k++;
    }

    while (j < sizeDerecha) {
        reservas[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(vector<Reserva>& reservas, int izquierda, int derecha) {

    if (izquierda < derecha) {

        int medio = izquierda + (derecha - izquierda) / 2;

        mergeSort(reservas, izquierda, medio);

        mergeSort(reservas, medio + 1, derecha);

        merge(reservas, izquierda, medio, derecha);
    }
}

void mostrarReservas(const vector<Reserva>& reservas) {
    for (const Reserva& reserva : reservas) {
        reserva.mostrarReserva();
    }
}

int main() {

    vector<Reserva> reservas = {

        Reserva("R001", "Carlos Perez", 3, 450.50),
        Reserva("R002", "Ana Torres", 5, 820.00),
        Reserva("R003", "Luis Mendoza", 2, 300.75),
        Reserva("R004", "Maria Lopez", 7, 1200.40),
        Reserva("R005", "Jose Ramirez", 1, 150.00),

        Reserva("R006", "Sofia Vega", 4, 600.20),
        Reserva("R007", "Diego Castro", 6, 980.10),
        Reserva("R008", "Valeria Ruiz", 2, 275.99),
        Reserva("R009", "Fernando Gil", 8, 1400.00),
        Reserva("R010", "Lucia Flores", 3, 500.00),

        Reserva("R011", "Pedro Silva", 5, 760.45),
        Reserva("R012", "Camila Ortiz", 2, 320.60),
        Reserva("R013", "Miguel Rojas", 4, 680.30),
        Reserva("R014", "Elena Navarro", 1, 180.90),
        Reserva("R015", "Andres Cruz", 9, 1700.80)

    };

    cout << "=== LISTA ANTES DEL ORDENAMIENTO ===" << endl;
    mostrarReservas(reservas);

    mergeSort(reservas, 0, reservas.size() - 1);

    cout << "\n=== LISTA DESPUES DEL ORDENAMIENTO ===" << endl;
    mostrarReservas(reservas);

    return 0;
}