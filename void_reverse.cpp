#include <iostream>
using namespace std;

template <typename T>
struct Nodo {
    T dato;
    Nodo* next;

    Nodo(T valor) {
        dato = valor;
        next = nullptr;
    }
};

template <typename T>
class Lista {
private:
    Nodo<T>* head;

public:
    Lista() {
        head = nullptr;
    }

    // Inserta al frente
    void push_front(T valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor);
        nuevo->next = head;
        head = nuevo;
    }

    // Inserta al final
    void push_back(T valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor);
        if (head == nullptr) {
            head = nuevo;
        } else {
            Nodo<T>* actual = head;
            while (actual->next != nullptr) {
                actual = actual->next;
            }
            actual->next = nuevo;
        }
    }

    // Verifica si la lista está vacía
    bool empty() {
        return head == nullptr;
    }

    // Invierte la lista
    void reverse() {
        Nodo<T>* prev = nullptr;
        Nodo<T>* actual = head;
        Nodo<T>* siguiente = nullptr;

        while (actual != nullptr) {
            siguiente = actual->next;  // Guardar el siguiente nodo
            actual->next = prev;       // Invertir enlace
            prev = actual;             // Avanzar prev
            actual = siguiente;        // Avanzar actual
        }
        head = prev; // Nuevo head es el último nodo
    }

    // Muestra la lista
    void mostrar() {
        if (empty()) {
            cout << "Lista vacía\n";
            return;
        }
        Nodo<T>* actual = head;
        while (actual != nullptr) {
            cout << actual->dato << " -> ";
            actual = actual->next;
        }
        cout << "NULL\n";
    }

    // Vacía la lista
    void clear() {
        while (head != nullptr) {
            Nodo<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    ~Lista() {
        clear();
    }
};

int main() {
    Lista<int> lista;

    lista.push_back(10);
    lista.push_back(20);
    lista.push_back(30);
    lista.push_back(40);

    cout << "Lista original:\n";
    lista.mostrar();   // 10 -> 20 -> 30 -> 40 -> NULL

    cout << "\nInvirtiendo con reverse()...\n";
    lista.reverse();

    lista.mostrar();   // 40 -> 30 -> 20 -> 10 -> NULL

    return 0;
}
