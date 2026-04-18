#include <iostream>
#include <string>

struct DoubleListNode {
    std::string data;
    DoubleListNode* next;
    DoubleListNode* prev;
    DoubleListNode(std::string val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    };
    DoubleListNode() {
        data = "default";
        next = nullptr;
        prev = nullptr;
    }
};

int main() {
    std::string input;
    DoubleListNode* undoRedo = new DoubleListNode();
    DoubleListNode* tail = undoRedo;

    while (true) {
        std::cout << "\n> ";
        std::getline(std::cin, input);

        if (input == "exit") {
            DoubleListNode* printer = undoRedo;
            std::cout << "Valores del historial: ";
            while(printer) {
                std::cout << "\n> " << printer->data;
                printer = printer->next;
            }
            std::cout << std::endl;

            DoubleListNode* current = undoRedo;
            while (current) {
                DoubleListNode* next = current->next;
                delete current;
                current = next;
            }
            break;
        }

        if (input == "u") {
            if (tail->prev == nullptr) {
                std::cout << "No hay mas valor que deshacer" << std::endl;
                continue;
            }
            tail = tail->prev;
        }
        else if (input == "r") {
            if (tail->next == nullptr) {
                std::cout << "No hay mas valor que rehacer" << std::endl;
                continue;
            }
            tail = tail->next;
        }
        else {
            if (input.empty()) {
                std::cout << "No se permite input vacio" << std::endl;
                continue;
            }
            if (tail->next != nullptr) {
                DoubleListNode* current = tail->next;
                while(current) {
                    DoubleListNode* next = current->next;
                    delete current;
                    current = next;
                }
                tail->next = nullptr;
            }
            tail->next = new DoubleListNode(input);
            tail->next->prev = tail;
            tail = tail->next;
        }

        std::cout << "Texto: " << tail->data << std::endl;
    }

    return 0;
}