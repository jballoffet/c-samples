/*!
 * @file   main.c
 * @brief  22. Estructuras Autorreferenciadas - 03. Estructuras enlazadas
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Dic 28, 2022
 */
#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node* pointer;
} Node;

int main(void)
{
    // Declaro dos variables de tipo "Node".
    Node node1, node2;

    // Cargo los datos de los nodos.
    node1.data = 1;
    node2.data = 2;

    // Asigno la dirección del nodo 2 al nodo 1 y asigno NULL al puntero del
    // nodo 2.
    node1.pointer = &node2;
    node2.pointer = NULL;

    // Imprimo los datos del nodo 1.
    printf("Dato almacenado en el nodo 1: %d\n", node1.data);
    printf("Direccion almacenada en el nodo 1: %p\n", node1.pointer);
    printf("Direccion del nodo 1: %p\n", &node1);

    // Imprimo los datos del nodo 2.
    printf("Dato almacenado en el nodo 2: %d\n", node2.data);
    printf("Direccion almacenada en el nodo 2: %p\n", node2.pointer);
    printf("Dirección del nodo 2: %p\n", &node2);

    // Accedo a los datos del nodo 2 desde el nodo 1.
    printf("Dato almacenado en el nodo 2: %d\n", node1.pointer->data);
    printf("Direccion almacenada en el nodo 2: %p\n", node1.pointer->pointer);

    return 0;
}
