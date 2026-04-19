#include <iostream>
#include <string>
#include <unordered_map>

class Paciente {
public:
    std::string dni;
    std::string nombres;
    std::string apellidos;
    std::string especialidad;
    std::string sede;

    Paciente(std::string dni, std::string nombres, std::string apellidos,
             std::string especialidad, std::string sede) {
        this->dni = dni;
        this->nombres = nombres;
        this->apellidos = apellidos;
        this->especialidad = especialidad;
        this->sede = sede;

        std::cout << "Paciente creado: " << nombres << " " << apellidos << std::endl;
    }

    ~Paciente() {
        std::cout << "Paciente eliminado: " << nombres << " " << apellidos << std::endl;
    }
};

struct ListaPaciente {
    Paciente* paciente;
    ListaPaciente* siguiente;

    ListaPaciente() {
        paciente = nullptr;
        siguiente = nullptr;
    }

    ListaPaciente(std::string dni, std::string nombres, std::string apellidos,
                  std::string especialidad, std::string sede) {
        paciente = new Paciente(dni, nombres, apellidos, especialidad, sede);
        siguiente = nullptr;
    }

    ~ListaPaciente() {
        delete paciente;
    }
};

class GestionadorPacientes {
private:
    ListaPaciente* cabeza;
    ListaPaciente* cola;

public:
    GestionadorPacientes() {
        cabeza = nullptr;
        cola = nullptr;
    }
    GestionadorPacientes(ListaPaciente* cabeza) {
        this->cabeza = cabeza;
        this->cola = this->cabeza;
    }

    ~GestionadorPacientes() {
        ListaPaciente* actual = cabeza;
        while (actual != nullptr) {
            ListaPaciente* temp = actual;
            actual = actual->siguiente;
            delete temp; // libera nodo (y su paciente gracias al destructor del struct)
        }
    }

    void agregarPaciente(
        std::string dni, 
        std::string nombres, 
        std::string apellidos,
        std::string especialidad, 
        std::string sede
    ) {
        ListaPaciente* nuevoPaciente = new ListaPaciente(dni, nombres, apellidos, especialidad, sede);

        if (this->cabeza == nullptr) {
            this->cabeza = nuevoPaciente;
            this->cola = this->cabeza;
        } else {
            this->cola->siguiente = nuevoPaciente;
            this->cola = nuevoPaciente;
        }
    }; 

    void mostrarTodos() {
        ListaPaciente* current = this->cabeza;
        int count = 1;
        std::cout << "\nLista de pacientes" << std::endl;
        while (current != nullptr) {
            Paciente* pacienteActual = current->paciente;
            std::cout << count << ". " << pacienteActual->nombres << " " << pacienteActual->apellidos 
            << " | " << "DNI: " << pacienteActual->dni << " | " << "Especialidad: " << pacienteActual->especialidad 
            << " | " << "Sede: " << pacienteActual->sede << std::endl;

            count++;
            current = current->siguiente;
        }
    }

    void mostrarPorSede(std::string sede) {
        std::cout << "\nPacientes en sede " << sede << std::endl;
        ListaPaciente* current = this->cabeza;
        int count = 1;
        std::cout << "\nLista de pacientes" << std::endl;
        while (current != nullptr) {
            Paciente* pacienteActual = current->paciente;
            if (pacienteActual->sede == sede) {
                std::cout << count << ". " << pacienteActual->nombres << " " << pacienteActual->apellidos 
                << " | " << "DNI: " << pacienteActual->dni << " | " << "Especialidad: " << pacienteActual->especialidad << std::endl;

                count++;
            }
            current = current->siguiente;
        }
    }

    void contarPorEspecialidad() {
        std::unordered_map<std::string, int> conteoPorEspecialidad;
        ListaPaciente* current = cabeza;
        while (current != nullptr) {
            Paciente* pacienteActual = current->paciente;
            conteoPorEspecialidad[pacienteActual->especialidad]++;
            current = current->siguiente;
        }

        std::cout << "\nResumen por especialidad" << std::endl;
        for (auto& par : conteoPorEspecialidad) {
            std::cout << "- " << par.first << ": " << par.second << " paciente(s)" << std::endl;
        }
    }
};

int main() {
    GestionadorPacientes gestionador;

    int opcion;
    std::string input;

    do {
        std::cout << "\n===== MENU DE OPCIONES =====\n";
        std::cout << "1. Ingresar paciente\n";
        std::cout << "2. Mostrar todos los pacientes registrados\n";
        std::cout << "3. Mostrar pacientes por sede\n";
        std::cout << "4. Mostrar numero de pacientes por especialidad\n";
        std::cout << "5. Salir\n";
        std::cout << "Seleccione una opcion: ";

        std::getline(std::cin, input);
        opcion = std::stoi(input);

        switch (opcion) {
            case 1: {
                std::string dni, nombres, apellidos, especialidad, sede;

                std::cout << "DNI: ";
                std::getline(std::cin, dni);

                std::cout << "Nombres: ";
                std::getline(std::cin, nombres);

                std::cout << "Apellidos: ";
                std::getline(std::cin, apellidos);

                std::cout << "Especialidad: ";
                std::getline(std::cin, especialidad);

                std::cout << "Sede: ";
                std::getline(std::cin, sede);

                gestionador.agregarPaciente(dni, nombres, apellidos, especialidad, sede);
                std::cout << "Paciente registrado correctamente.\n";
                break;
            }

            case 2:
                gestionador.mostrarTodos();
                break;

            case 3: {
                std::string sede;
                std::cout << "Ingrese sede a filtrar: ";
                std::getline(std::cin, sede);

                gestionador.mostrarPorSede(sede);
                break;
            }

            case 4:
                gestionador.contarPorEspecialidad();
                break;

            case 5:
                std::cout << "Saliendo del sistema...\n";
                break;

            default:
                std::cout << "Opcion invalida.\n";
        }

    } while (opcion != 5);

    return 0;
}