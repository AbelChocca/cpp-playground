#include <iostream>
#include <string>
#include <vector>
#include <cctype>

std::string trim(const std::string& str) {
    std::vector<char> chars(str.begin(), str.end());

    int left = 0;
    int right = chars.size() - 1;

    // avanzar desde la izquierda
    while (left <= right && isspace(chars[left])) {
        left++;
    }

    // retroceder desde la derecha
    while (right >= left && isspace(chars[right])) {
        right--;
    }

    // construir resultado
    std::string resultado = "";
    for (int i = left; i <= right; i++) {
        resultado += chars[i];
    }

    return resultado;
}

class Song{
public:
    std::string nombre;
    int duracionSeg;
    std::string nombreArtista;
    std::string sku;

    Song(
        std::string nombre,
        int duracionSeg,
        std::string nombreArtista
    ) {
        this->nombre = nombre;
        this->duracionSeg = duracionSeg;
        this->nombreArtista = nombreArtista;
        this->sku = this->generarSku();
    }

    ~Song() {
        this->nombre = "";
        this->duracionSeg = 0;
        this->nombreArtista = "";
        this->sku = "";
    }
private:

    std::string generarSku() {
        std::vector<std::string> cadenas;
        std::string nombreTrim = trim(this->nombre);
        std::string cadena = "";
        for (auto& c : nombreTrim) {
            if (c == ' '){
                cadenas.push_back(cadena);
                cadena = "";
                continue;
            }
            cadena += c;
        };
        std::string nuevoSku = "";
        for (auto& c : cadenas) {
            nuevoSku += toupper(c[0]);
            
        }
        nuevoSku += char(this->duracionSeg);

        return nuevoSku;
    };
};

struct ListaSong {
    Song* value;
    ListaSong* next;
    ListaSong* prev;

    ListaSong(Song* value) {
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }

    ~ListaSong() {
        delete this->value;
        this->value = nullptr;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class Album{
public:
    std::string nombre;
    std::string nombre
}

int main() {


    return 0;
}