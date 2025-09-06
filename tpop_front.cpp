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

    // Elimina y devuelve el primer elemento
    T pop_front() {
        if (head == nullptr) {
            throw runtime_error("Error: la lista está vacía.");
        }
        Nodo<T>* temp = head;
        T valor = temp->dato;
        head = head->next;   // mover head al siguiente
        delete temp;         // liberar memoria
        return valor;        // devolver el valor eliminado
    }

    // Muestra la lista
    void mostrar() {
        Nodo<T>* actual = head;
        while (actual != nullptr) {
            cout << actual->dato << " -> ";
            actual = actual->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    Lista<int> lista;

    lista.push_back(10);
    lista.push_back(20);
    lista.push_back(30);

    cout << "Lista inicial:\n";
    lista.mostrar();   // 10 -> 20 -> 30 -> NULL

    cout << "\nElemento eliminado con pop_front(): " << lista.pop_front() << endl;  
    lista.mostrar();   // 20 -> 30 -> NULL

    cout << "\nElemento eliminado con pop_front(): " << lista.pop_front() << endl;  
    lista.mostrar();   // 30 -> NULL

    return 0;
}
