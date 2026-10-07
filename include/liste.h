#ifndef LISTE_H
#define LISTE_H

#include <stdio.h>
#include <stdlib.h>

// Définition d'un nœud de la liste chaînée
typedef struct Node {
    int data;          // La valeur stockée
    struct Node* next; // Le pointeur vers le prochain nœud
} Node;

// Prototypes des fonctions
Node* create_node(int data);
void insert_at_head(Node** head, int data);
void print_list(Node* head);
void free_list(Node* head);

#endif