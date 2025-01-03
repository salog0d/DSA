#include <iostream>
using namespace std;

// Definición de la clase Node
// Representa un nodo de la lista enlazada
class Node {
public:
    int data;   // Dato que almacena el nodo
    Node *next; // Puntero al siguiente nodo
};

// Definición de la clase LinkedList
// Implementa la lista enlazada y sus operaciones
class LinkedList {
private:
    Node *first; // Puntero al primer nodo de la lista
public:
    LinkedList() { first = NULL; } // Constructor por defecto, inicializa la lista como vacía
    LinkedList(int A[], int n);    // Constructor parametrizado para inicializar con un arreglo
    ~LinkedList();                 // Destructor para liberar memoria

    void Display();                // Método para mostrar los elementos de la lista
    void Insert(int index, int x); // Método para insertar un elemento en una posición específica
    int Delete(int index);         // Método para eliminar un elemento en una posición específica
    int Length();                  // Método para calcular la longitud de la lista
};

// Constructor parametrizado
// Recibe un arreglo `A` y su tamaño `n`, construyendo una lista enlazada con los elementos del arreglo
LinkedList::LinkedList(int A[], int n) {
    Node *last, *t; // `last` mantiene el último nodo creado, `t` es un nodo temporal
    int i = 0;

    // Creación del primer nodo
    first = new Node;        // Reservar memoria para el primer nodo
    first->data = A[0];      // Asignar el primer elemento del arreglo
    first->next = NULL;      // Inicializar `next` como NULL
    last = first;            // `last` apunta al primer nodo

    // Crear el resto de los nodos a partir del arreglo
    for (i = 1; i < n; i++) {
        t = new Node;        // Reservar memoria para un nuevo nodo
        t->data = A[i];      // Asignar el valor del arreglo al nodo
        t->next = NULL;      // Inicializar `next` como NULL
        last->next = t;      // Enlazar el último nodo con el nuevo nodo
        last = t;            // Actualizar `last` para que apunte al nuevo nodo
    }
}

// Destructor
// Libera toda la memoria asignada a los nodos de la lista
LinkedList::~LinkedList() {
    Node *p = first;         // `p` apunta al primer nodo
    while (first) {          // Mientras haya nodos en la lista
        first = first->next; // Mover `first` al siguiente nodo
        delete p;            // Liberar el nodo actual
        p = first;           // Actualizar `p` para que apunte al siguiente nodo
    }
}

// Mostrar los elementos de la lista
void LinkedList::Display() {
    Node *p = first;         // `p` comienza en el primer nodo

    // Recorrer todos los nodos y mostrar sus valores
    while (p) {
        cout << p->data << " "; // Imprimir el dato del nodo actual
        p = p->next;            // Mover `p` al siguiente nodo
    }
    cout << endl;             // Nueva línea al final
}

// Calcular la longitud de la lista
int LinkedList::Length() {
    Node *p = first;         // `p` comienza en el primer nodo
    int len = 0;             // Inicializar el contador de longitud

    // Recorrer todos los nodos y contar
    while (p) {
        len++;               // Incrementar el contador
        p = p->next;         // Mover `p` al siguiente nodo
    }
    return len;              // Devolver la longitud total
}

// Insertar un elemento en una posición específica
void LinkedList::Insert(int index, int x) {
    Node *t, *p = first;     // `t` es el nodo a insertar, `p` es para recorrer la lista

    // Validar índice
    if (index < 0 || index > Length())
        return;

    t = new Node;            // Reservar memoria para el nuevo nodo
    t->data = x;             // Asignar el valor al nuevo nodo
    t->next = NULL;          // Inicializar `next` como NULL

    // Si se inserta en la posición 0 (al principio)
    if (index == 0) {
        t->next = first;     // El nuevo nodo apunta al primer nodo
        first = t;           // `first` ahora apunta al nuevo nodo
    } else {                 // Si se inserta en cualquier otra posición
        for (int i = 0; i < index - 1; i++)
            p = p->next;     // Mover `p` al nodo anterior a la posición deseada
        t->next = p->next;   // El nuevo nodo apunta al siguiente nodo
        p->next = t;         // El nodo anterior apunta al nuevo nodo
    }
}

// Eliminar un elemento en una posición específica
int LinkedList::Delete(int index) {
    Node *p, *q = NULL;      // `p` apunta al nodo a eliminar, `q` es el nodo anterior
    int x = -1;              // Almacena el dato del nodo eliminado

    // Validar índice
    if (index < 1 || index > Length())
        return -1;

    // Si se elimina el primer nodo
    if (index == 1) {
        p = first;           // `p` apunta al primer nodo
        first = first->next; // `first` apunta al siguiente nodo
        x = p->data;         // Almacenar el dato eliminado
        delete p;            // Liberar memoria del nodo
    } else {                 // Si se elimina cualquier otro nodo
        p = first;
        for (int i = 0; i < index - 1; i++) {
            q = p;           // Mover `q` a `p`
            p = p->next;     // Mover `p` al siguiente nodo
        }
        q->next = p->next;   // Saltar el nodo a eliminar
        x = p->data;         // Almacenar el dato eliminado
        delete p;            // Liberar memoria del nodo
    }
    return x;                // Devolver el dato eliminado
}

// Función principal
int main() {
    int A[] = {1, 2, 3, 4, 5}; // Arreglo inicial para construir la lista
    LinkedList l(A, 5);        // Crear una lista enlazada con los elementos de `A`

    l.Insert(3, 10);           // Insertar 10 en la posición 3
    l.Display();               // Mostrar los elementos de la lista

    return 0;                  // Fin del programa
}
