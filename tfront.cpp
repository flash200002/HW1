#include <iostream>
using namespace std;

// Nodo de lista simplemente enlazada
template <typename T>
struct Nodo {
    T dato;
    Nodo* siguiente;
    Nodo(T v) : dato(v), siguiente(nullptr) {}
};

// Lista simplemente enlazada
template <typename T>
class Lista {
private:
    Nodo<T>* cabeza;

public:
    Lista() : cabeza(nullptr) {}

    // Insertar al inicio
    void push_front(T valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor);
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
    }

    // Insertar al final
    void push_back(T valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor);
        if (!cabeza) {
            cabeza = nuevo;
        } else {
            Nodo<T>* temp = cabeza;
            while (temp->siguiente) temp = temp->siguiente;
            temp->siguiente = nuevo;
        }
    }

    // Retornar el primer elemento
    T front() {
        if (!cabeza) throw runtime_error("La lista está vacía");
        return cabeza->dato;
    }

    // Mostrar lista
    void mostrar() {
        Nodo<T>* temp = cabeza;
        while (temp) {
            cout << temp->dato << " -> ";
            temp = temp->siguiente;
        }
        cout << "NULL\n";
    }

    ~Lista() {
        while (cabeza) {
            Nodo<T>* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }
};

// Ejemplo de uso
int main() {
    Lista<int> miLista;

    miLista.push_back(10);
    miLista.push_back(20);
    miLista.push_front(5);

    cout << "Contenido de la lista: ";
    miLista.mostrar();

    cout << "El primer elemento (front) es: " << miLista.front() << endl;

    return 0;
}
