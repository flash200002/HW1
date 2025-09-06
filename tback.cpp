#include <iostream>
#include <stdexcept>

template <typename T>
class ListaEnlazada {
private:
    struct Nodo {
        T dato;
        Nodo* siguiente;
        
        Nodo(const T& valor) : dato(valor), siguiente(nullptr) {}
    };
    
    Nodo* cabeza;
    
public:
    // Constructor
    ListaEnlazada() : cabeza(nullptr) {}
    
    // Destructor
    ~ListaEnlazada() {
        while (cabeza != nullptr) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }
    
    // Función back() - devuelve referencia al último elemento
    T& back() {
        if (cabeza == nullptr) {
            throw std::runtime_error("Lista vacía: no se puede acceder al final");
        }
        
        // Recorrer hasta el último nodo
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        
        return actual->dato;
    }
    
    // Versión const de back()
    const T& back() const {
        if (cabeza == nullptr) {
            throw std::runtime_error("Lista vacía: no se puede acceder al final");
        }
        
        // Recorrer hasta el último nodo
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        
        return actual->dato;
    }
    
    // Función front() para comparar
    T& front() {
        if (cabeza == nullptr) {
            throw std::runtime_error("Lista vacía: no se puede acceder al frente");
        }
        return cabeza->dato;
    }
    
    // Insertar al inicio
    void push_front(const T& valor) {
        Nodo* nuevo = new Nodo(valor);
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
    }
    
    // Insertar al final
    void push_back(const T& valor) {
        Nodo* nuevo = new Nodo(valor);
        
        if (cabeza == nullptr) {
            cabeza = nuevo;
            return;
        }
        
        // Buscar el último nodo
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        
        actual->siguiente = nuevo;
    }
    
    // Eliminar el último elemento
    void pop_back() {
        if (cabeza == nullptr) {
            return; // Lista vacía
        }
        
        // Si solo hay un elemento
        if (cabeza->siguiente == nullptr) {
            delete cabeza;
            cabeza = nullptr;
            return;
        }
        
        // Buscar el penúltimo nodo
        Nodo* actual = cabeza;
        while (actual->siguiente->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        
        delete actual->siguiente;
        actual->siguiente = nullptr;
    }
    
    // Verificar si está vacía
    bool empty() const {
        return cabeza == nullptr;
    }
    
    // Contar elementos (para mostrar complejidad)
    int size() const {
        int contador = 0;
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            contador++;
            actual = actual->siguiente;
        }
        return contador;
    }
    
    // Mostrar lista
    void mostrar() const {
        Nodo* actual = cabeza;
        std::cout << "Lista: ";
        while (actual != nullptr) {
            std::cout << actual->dato << " -> ";
            actual = actual->siguiente;
        }
        std::cout << "NULL" << std::endl;
    }
};

int main() {
    ListaEnlazada<int> lista;
    
    std::cout << "=== Ejemplo de back() en Lista Enlazada ===" << std::endl;
    
    // Insertar elementos
    lista.push_back(10);  // Lista: 10
    lista.push_back(20);  // Lista: 10 -> 20
    lista.push_back(30);  // Lista: 10 -> 20 -> 30
    
    lista.mostrar();
    std::cout << "Tamaño de la lista: " << lista.size() << std::endl;
    
    // Usar back() para acceder al último elemento
    std::cout << "Último elemento (back()): " << lista.back() << std::endl;
    std::cout << "Primer elemento (front()): " << lista.front() << std::endl;
    
    // Modificar el último elemento usando back()
    std::cout << "\nModificando último elemento a 99..." << std::endl;
    lista.back() = 99;
    lista.mostrar(); // Lista: 10 -> 20 -> 99 -> NULL
    
    // back() no elimina el elemento
    std::cout << "back() nuevamente: " << lista.back() << std::endl;
    lista.mostrar(); // Lista sigue igual
    
    // Agregar más elementos y usar back()
    lista.push_back(40);
    lista.push_back(50);
    lista.mostrar(); // Lista: 10 -> 20 -> 99 -> 40 -> 50 -> NULL
    std::cout << "Nuevo último elemento: " << lista.back() << std::endl;
    
    // Eliminar último elemento y usar back()
    std::cout << "\nEliminando último elemento..." << std::endl;
    lista.pop_back();
    lista.mostrar(); // Lista: 10 -> 20 -> 99 -> 40 -> NULL
    std::cout << "Nuevo último después de pop_back(): " << lista.back() << std::endl;
    
    
}