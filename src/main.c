#include <stdio.h>
#include "../include/liste.h"
#include "../include/pile.h"
#include "../include/hachage.h"

int main(void) {
    printf("========== TEST DES STRUCTURES DE DONNEES ==========\n\n");

    // 1. Test de la Liste Chaînée
    printf("--- 1. Liste Chainee ---\n");
    Node* liste = NULL;
    insert_at_head(&liste, 30);
    insert_at_head(&liste, 20);
    insert_at_head(&liste, 10);
    print_list(liste); // Attendu : 10 -> 20 -> 30 -> NULL
    free_list(liste);
    printf("\n");

    // 2. Test de la Pile (Stack LIFO)
    printf("--- 2. Pile (LIFO) ---\n");
    Node* pile = NULL;
    push(&pile, 100);
    push(&pile, 200);
    push(&pile, 300);
    printf("Sommet (Peek) : %d\n", peek(pile)); // Attendu : 300
    printf("Depilement (Pop) : %d\n", pop(&pile)); // Attendu : 300
    printf("Nouveau sommet (Peek) : %d\n", peek(pile)); // Attendu : 200
    free_list(pile);
    printf("\n");

    // 3. Test de la Table de Hachage
    printf("--- 3. Table de Hachage ---\n");
    HashTable* table = create_table();
    insert_hash(table, 5);
    insert_hash(table, 15); // Va créer une collision avec 5 (15 % 10 = 5)
    insert_hash(table, 42);
    insert_hash(table, 7);
    print_table(table); 
    // Le Bucket 5 doit contenir 15 -> 5 -> NULL
    
    // Libération de la table
    for (int i = 0; i < TABLE_SIZE; i++) {
        free_list(table->buckets[i]);
    }
    free(table);

    printf("\n====================================================\n");
    return 0;
}