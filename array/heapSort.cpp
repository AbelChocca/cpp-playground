#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

// Función para intercambiar dos elementos
void intercambiar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Heapify (Sift-Down)
void heapify(vector<int>& arr, int n, int i) {
    int mayor = i;
    int izq = 2 * i + 1;
    int der = 2 * i + 2;

    if (izq < n && arr[izq] > arr[mayor])
        mayor = izq;

    if (der < n && arr[der] > arr[mayor])
        mayor = der;

    if (mayor != i) {
        intercambiar(arr[i], arr[mayor]);
        heapify(arr, n, mayor);
    }
}

// Heap Sort
void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        intercambiar(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Imprimir arreglo
void imprimirArreglo(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << "\n";
}

int main() {
    // Seed con chrono (tiempo actual en nanosegundos)
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    uniform_int_distribution<int> dist(1, 1000);

    // Vector de 300 elementos aleatorios
    vector<int> datos;
    datos.reserve(300);

    for (int i = 0; i < 300; i++) {
        datos.push_back(dist(gen));
    }

    cout << "=== ARREGLO ORIGINAL ===\n";
    imprimirArreglo(datos);

    heapSort(datos);

    cout << "\n=== ARREGLO ORDENADO ===\n";
    imprimirArreglo(datos);

    return 0;
}