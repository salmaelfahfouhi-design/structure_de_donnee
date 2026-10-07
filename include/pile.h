#ifndef PILE_H
#define PILE_H

#include "liste.h"

// Prototypes des opérations de la pile
void push(Node** top, int data);
int pop(Node** top);
int peek(Node* top);
int is_empty(Node* top);

#endif