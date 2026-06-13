#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    if (value % 3 != 0) return root;

    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int altura(Node* root) {
    if (root == nullptr) return -1;

    int leftNode = altura(root->left);
    int rightNode = altura(root->right);

    return 1 + max(leftNode, rightNode);
}

int cantidadNodos(Node* root) {
    if (root == nullptr) return 0;

    return 1 + cantidadNodos(root->left) + cantidadNodos(root->right); 
}

int main() {
    Node* root = nullptr;

    int num;
    while (cin>> num) {
        root = insert(root, num);
    }

    cout << "EnOrden: ";
    inorder(root);
    cout << endl;
    cout << "Cantidad: " << cantidadNodos(root) << endl;
    cout << "Altura: " << altura(root) << endl;
}