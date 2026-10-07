#include <stdio.h>
#include <stdlib.h>
#include "../include/pile.h"

// Vérifier si la pile est vide
int is_empty(Node* top) {
    return top == NULL;
}

// Ajouter un élément au sommet (Push)
void push(Node** top, int data) {
    // Le sommet de la pile correspond à la tête de la liste chaînée
    insert_at_head(top, data);
}

// Retirer un élément du sommet (Pop)
int pop(Node** top) {
    if (is_empty(*top)) {
        fprintf(stderr, "Erreur : La pile est vide.\n");
        exit(1);
    }
    Node* temp = *top;
    int popped_data = temp->data;
    
    *top = (*top)->next; // Le sommet devient l'élément suivant
    free(temp);          // On libère la mémoire de l'ancien sommet
    
    return popped_data;
}

// Consulter le sommet sans le dépiler (Peek)
int peek(Node* top) {
    if (is_empty(top)) {
        fprintf(stderr, "Erreur : La pile est vide.\n");
        exit(1);
    }
    return top->data;
}