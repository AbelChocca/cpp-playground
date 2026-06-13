#include "../base.h"
using namespace std;

int main() {
    Stack s;
    Queue q;

    int choice;

    while (true) {
        cout << "\n===== MENU ESTRUCTURAS =====\n";
        cout << "1. Push Stack\n";
        cout << "2. Pop Stack\n";
        cout << "3. Peek Stack\n";
        cout << "4. Mostrar Stack\n";
        cout << "5. Enqueue Queue\n";
        cout << "6. Dequeue Queue\n";
        cout << "7. Front Queue\n";
        cout << "8. Mostrar Queue\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> choice;

        if (choice == 0) break;

        int value;

        switch (choice) {
            case 1:
                cout << "Valor: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                cout << "Top: " << s.peek() << endl;
                break;

            case 4:
                s.display();
                break;

            case 5:
                cout << "Valor: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 6:
                q.dequeue();
                break;

            case 7:
                cout << "Front: " << q.getFront() << endl;
                break;

            case 8:
                q.display();
                break;

            default:
                cout << "Opcion invalida" << endl;
        }
    }

    return 0;
}