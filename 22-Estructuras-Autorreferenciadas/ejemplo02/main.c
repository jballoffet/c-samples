/*!
 * @file   main.c
 * @brief  22. Estructuras Autorreferenciadas - 02. Uso de Typedef
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Dic 28, 2022
 */
#include <stdio.h>

// Defino un tipo de datos llamado "Node" a partir del tipo "struct Node".
typedef struct Node
{
    int data;
    struct Node* pointer;
} Node;

int main(void)
{
    // Declaro una variable de tipo "Node".
    Node node;

    // Cargo los datos del nodo (asignando la propia dirección del nodo al
    // puntero incluído).
    node.data = 1;
    node.pointer = &node;

    // Imprimo los datos del nodo.
    printf("Dato almacenado en el nodo: %d\n", node.data);
    printf("Direccion almacenada en el nodo: %p\n", node.pointer);
    printf("Direccion del nodo: %p\n", &node);

    return 0;
}
