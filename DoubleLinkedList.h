//César Antonio Martínez Vilchis. A01236306.
//Ángel Dominguez Faraco. A00835367.
#include <cstddef>
#include <iostream>
#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
using namespace std;

template <typename T>
class Nodo {
public:
    T data;
    Nodo* next;
    Nodo* prev;

    Nodo(const T& value) : data(value), next(nullptr), prev(nullptr) {
    }
};

template <typename T>
class DoubleLinkedList {
private:
    Nodo<T>* head;
    Nodo<T>* tail;
    size_t size;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {
    }

    // Complejidad Temporal: O(n). Recorre y elimina los nodos.
    ~DoubleLinkedList() {
        while (head) {
            Nodo<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    // Complejidad Temporal: O(1)
    size_t getSize() const {
        return size;
    }

    // Complejidad Temporal: En el peor caso O(n)
    void insertAt(size_t index, const T& value) {
        if (index < 0 || index > size) {
            cerr << "Indice fuera de rango." << endl;
            return;
        }

        Nodo<T>* newNode = new Nodo<T>(value);
        if (index == 0) {
            newNode->next = head;
            if (head) {
                head->prev = newNode;
            }
            head = newNode;
            if (!tail) {
                tail = newNode;
            }
        } else if (index == size) {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        } else {
            Nodo<T>* current = head;
            for (size_t i = 0; i < index; ++i) {
                current = current->next;
            }
            newNode->prev = current->prev;
            newNode->next = current;
            current->prev->next = newNode;
            current->prev = newNode;
        }

        size++;
    }

    // Complejidad Temporal: En el peor caso O(n)
    void removeAt(size_t index) {
        if (index < 0 || index >= size) {
            cerr << "Indice fuera de rango." << endl;
            return;
        }

        Nodo<T>* toRemove;
        if (index == 0) {
            toRemove = head;
            head = head->next;
            if (head) {
                head->prev = nullptr;
            }
            delete toRemove;
            if (size == 1) {
                tail = nullptr;
            }
        } else if (index == size - 1) {
            toRemove = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete toRemove;
        } else {
            Nodo<T>* current = head;
            for (size_t i = 0; i < index; ++i) {
                current = current->next;
            }
            toRemove = current;
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete toRemove;
        }

        size--;
    }
    
    // Complejidad Temporal: O(1)
    void pushFront(const T& value) {
        insertAt(0, value);
    }

    // Complejidad Temporal: O(1)
    void pushBack(const T& value) {
        insertAt(size, value);
    }

    // Complejidad Temporal: O(n), porque recorre la lista
    void print() const {
        Nodo<T>* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Complejidad Temporal: O(n)
    Nodo<T>* getNode(size_t index) {
        if (index < 0 || index >= size) {
            // Índice fuera de rango, devuelve nullptr o maneja el error según tu preferencia.
            return nullptr;
        }

        Nodo<T>* currentNode = nullptr;

        // Comienza desde la cabeza si el índice es menor o igual a la mitad del tamaño.
        if (index <= size / 2) {
            currentNode = head;
            for (size_t i = 0; i < index; i++) {
                currentNode = currentNode->next;
            }
        } else {
            // De lo contrario, comienza desde la cola para recorrer hacia atrás.
            currentNode = tail;
            for (size_t i = size - 1; i > index; i--) {
                currentNode = currentNode->prev;
            }
        }

        return currentNode;
    }
};

#endif