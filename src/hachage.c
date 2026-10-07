#include <stdio.h>
#include <stdlib.h>
#include "../include/hachage.h"

// Initialiser la table avec des listes vides
HashTable* create_table() {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    if (table == NULL) {
        fprintf(stderr, "Erreur d'allocation memoire\n");
        exit(1);
    }
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->buckets[i] = NULL;
    }
    return table;
}

// Fonction de hachage simple utilisant le modulo[cite: 55]
int hash_function(int key) {
    // Si la clé est négative, on s'assure d'avoir un index positif
    int hash = key % TABLE_SIZE;
    return hash < 0 ? hash + TABLE_SIZE : hash;
}

// Insérer une valeur dans la table de hachage avec gestion des collisions par chaînage[cite: 56]
void insert_hash(HashTable* table, int key) {
    int index = hash_function(key);
    // On réutilise la fonction de notre liste chaînée pour insérer dans le bucket correspondant
    insert_at_head(&(table->buckets[index]), key);
}

// Afficher le contenu complet de la table
void print_table(HashTable* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Bucket %d : ", i);
        Node* current = table->buckets[i];
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}