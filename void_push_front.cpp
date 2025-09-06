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

    // Inserta un elemento al inicio de la lista
    void push_front(int valor) {
        Nodo* nuevo = new Nodo(valor);
        nuevo->next = head; // El nuevo apunta al primero actual
        head = nuevo;       // Ahora head es el nuevo nodo
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

    lista.push_front(10);
    lista.push_front(20);
    lista.push_front(30);

    cout << "Lista después de insertar con push_front:\n";
    lista.mostrar();  // Debe mostrar: 30 -> 20 -> 10 -> NULL

    return 0;
}
