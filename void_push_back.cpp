#include <iostream>
using namespace std;

// Nodo de la lista
struct Nodo {
    int dato;
    Nodo* next;

    Nodo(int valor) {
        dato = valor;
        next = nullptr;
    }
};

// Lista simplemente enlazada
class Lista {
private:
    Nodo* head;

public:
    Lista() {
        head = nullptr;
    }

    // Inserta un elemento al inicio
    void push_front(int valor) {
        Nodo* nuevo = new Nodo(valor);
        nuevo->next = head;
        head = nuevo;
    }

    // Inserta un elemento al final
    void push_back(int valor) {
        Nodo* nuevo = new Nodo(valor);

        if (head == nullptr) {
            // Si la lista está vacía, el nuevo será el primero
            head = nuevo;
        } else {
            Nodo* actual = head;
            while (actual->next != nullptr) {
                actual = actual->next; // avanzar hasta el último
            }
            actual->next = nuevo; // enlazar el nuevo al final
        }
    }

    // Muestra la lista
    void mostrar() {
        Nodo* actual = head;
        while (actual != nullptr) {
            cout << actual->dato << " -> ";
            actual = actual->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    Lista lista;

    // Insertamos al frente
    lista.push_front(10); // Lista: 10
    lista.push_front(20); // Lista: 20 -> 10
    lista.push_front(30); // Lista: 30 -> 20 -> 10

    // Insertamos al final
    lista.push_back(40);  // Lista: 30 -> 20 -> 10 -> 40
    lista.push_back(50);  // Lista: 30 -> 20 -> 10 -> 40 -> 50

    cout << "Lista final:\n";
    lista.mostrar();

    return 0;
}
