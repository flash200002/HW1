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

    // Devuelve el tamaño de la lista
    int size() {
        int contador = 0;
        Nodo<T>* actual = head;
        while (actual != nullptr) {
            contador++;
            actual = actual->next;
        }
        return contador;
    }

    // Ordena la lista (Bubble Sort)
    void sort() {
        if (head == nullptr || head->next == nullptr) return; // Lista vacía o un solo elemento

        bool swapped;
        do {
            swapped = false;
            Nodo<T>* actual = head;
            while (actual->next != nullptr) {
                if (actual->dato > actual->next->dato) {
                    // Intercambiar valores
                    T temp = actual->dato;
                    actual->dato = actual->next->dato;
                    actual->next->dato = temp;
                    swapped = true;
                }
                actual = actual->next;
            }
        } while (swapped);
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

    // Destructor: limpia la lista al destruir el objeto
    ~Lista() {
        clear();
    }
};

int main() {
    Lista<int> lista;

    lista.push_back(30);
    lista.push_back(10);
    lista.push_back(40);
    lista.push_back(20);

    cout << "Lista desordenada:\n";
    lista.mostrar();

    cout << "\nOrdenando con sort()...\n";
    lista.sort();

    lista.mostrar();  // 10 -> 20 -> 30 -> 40 -> NULL

    return 0;
}
