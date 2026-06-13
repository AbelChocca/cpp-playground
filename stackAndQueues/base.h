#pragma once
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int x) {
        Node* newNode = new Node(x);

        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "La Pila esta vacia." << std::endl;
            return;
        }
        // IDEA:
        // 1. verificar si está vacío
        // 2. guardar nodo top en temp
        // 3. mover top al siguiente
        // 4. liberar memoria
        Node* temp = top;

        top = top->next;

        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void display() {
        Node* curr = top;
        std::cout << "Stack (top -> head): ";
        while (curr) {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        // TODO:
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int x) {
        // IDEA:
        // 1. crear nuevo nodo
        // 2. si está vacía:
        //      front = rear = nuevo nodo
        // 3. si no:
        //      rear->next = nuevo nodo
        //      mover rear
        Node* newNode = new Node(x);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = rear->next;
        }
    }

    void dequeue() {
        // IDEA:
        // 1. verificar si está vacía
        // 2. guardar front en temp
        // 3. mover front
        // 4. si front es nullptr → rear también nullptr
        // 5. liberar temp  
        if (isEmpty()) return;

        Node* temp = front;

        front = front->next;

        if (front == nullptr) rear = nullptr;
        delete temp;
    }

    int getFront() {
        // IDEA:
        // return front->data
        if (isEmpty()) {
            throw std::runtime_error("Queue vacía");
        }
        return front->data;
    }

    bool isEmpty() {
        // front == nullptr
        return front == nullptr;
    }
    void display() {
        Node* curr = front;
        std::cout << "Queue (front -> rear): ";
        while (curr) {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
};