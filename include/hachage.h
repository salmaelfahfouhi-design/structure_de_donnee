#ifndef HACHAGE_H
#define HACHAGE_H

#include "liste.h"

#define TABLE_SIZE 10 // Taille fixe du tableau pour cet exemple

// La table de hachage contient un tableau de pointeurs vers des nœuds (les listes)
typedef struct HashTable {
    Node* buckets[TABLE_SIZE]; 
} HashTable;

// Prototypes des fonctions
HashTable* create_table();
int hash_function(int key);
void insert_hash(HashTable* table, int key);
void print_table(HashTable* table);

#endif