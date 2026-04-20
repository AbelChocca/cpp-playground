
struct Node {
    int val;
    Node* next;
    Node(int data) {
        val = data;
        next = nullptr;
    };
    Node() {
        val = 0;
        next = nullptr;
    };
};

class Lista {
    public:
        Node* head;

    int longitud() {
        int longitud = 0;
        Node* current = this->head;
        while (current != nullptr) {
            longitud++;
            current = current->next;
        }
        return longitud; 
    }

    bool esVacia() {
        
    }
}

int main() {
    Node* head = 
}