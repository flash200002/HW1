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
        if (head == nullptr) throw runtime_error("Error: la lista está vacía.");
        Nodo<T>* temp = head;
        T valor = temp->dato;
        head = head->next;
        delete temp;
        return valor;
    }

    // Elimina y devuelve el último elemento
    T pop_back() {
        if (head == nullptr) throw runtime_error("Error: la lista está vacía.");
        if (head->next == nullptr) {
            T valor = head->dato;
            delete head;
            head = nullptr;
            return valor;
        }
        Nodo<T>* actual = head;
        while (actual->next->next != nullptr) {
            actual = actual->next;
        }
        T valor = actual->next->dato;
        delete actual->next;
        actual->next = nullptr;
        return valor;
    }

    // Operador [] (acceso por índice)
    T& operator[](int index) {
        if (index < 0) throw out_of_range("Índice negativo no válido.");
        Nodo<T>* actual = head;
        int contador = 0;
        while (actual != nullptr) {
            if (contador == index) {
                return actual->dato;
            }
            actual = actual->next;
            contador++;
        }
        throw out_of_range("Índice fuera de rango.");
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

    cout << "Lista: ";
    lista.mostrar();  // 10 -> 20 -> 30 -> NULL

    cout << "\nAccediendo con operator[]:\n";
    cout << "lista[0] = " << lista[0] << endl;  // 10
    cout << "lista[1] = " << lista[1] << endl;  // 20
    cout << "lista[2] = " << lista[2] << endl;  // 30

    cout << "\nModificando lista[1] = 99\n";
    lista[1] = 99;  // modifica el nodo en la posición 1
    lista.mostrar();  // 10 -> 99 -> 30 -> NULL

    return 0;
}
