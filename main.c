#include "construction.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    struct chips *first = NULL;
    printf("Printing empty list...\n");
    print_list(first);
    printf("Adding first brand to the list...\n");
    first = new_chips(10.00, "Pringles");
    print_list(first);
    printf("Adding more brands to the list...\n");
    first = insert_front(first, "Ruffles", 5.98);
    first = insert_front(first, "Lays", 4.99);
    first = insert_front(first, "Cheese Puffs", 1.99);
    print_list(first);
    // printf("Removing Manuel...\n");
    // first = remove_node(first, "Manuel");
    // print_list(first);
    printf("Removing Ruffles...\n");
    first = remove_node(first, "Ruffles", 5.98);
    print_list(first);
    // printf("Removing Chelsea...\n");
    // first = remove_node(first, "Chelsea");
    // print_list(first);
    printf("Removing Cheese Puffs...\n");
    first = remove_node(first, "Cheese Puffs", 1.99);
    print_list(first);
    printf("Freeing list...\n");
    first = free_list(first);
    printf("printing empty list...\n");
    print_list(first);
}

