#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct chips {
    float price;
    char name[256];

    struct chips *next;
};

void print_struct(struct chips x) {
    for (int i = 0; *(x.name + i); i++) {
        printf("%c", *(x.name + i));
    }
    printf(": %f\n", x.price);
    return;
}

struct chips *new_chips(float pr, char *it) {

    struct chips *nu;

    nu = malloc( sizeof(struct chips) );
    strncpy(nu->name, it, sizeof(nu->name)-1);
    nu->price = pr;

    return nu;
}

void change_chips(struct chips *x, char *it, float pr) {
    x -> price = pr;
    strncpy(x->name, it, sizeof(x->name)-1);
}    

void print_list(struct chips *p) {
    if (p == NULL) {
        printf("No chips :(\n");
        return;
    }
    struct chips * curr = p;
    while (curr != NULL) {
        print_struct(*curr);
        curr = curr -> next;
    }
    return;
}

struct chips * insert_front(struct chips *p, char *na, float pr) {
    struct chips *front = new_chips(pr, na);
    front -> next = p;
    return front;
}

struct chips * free_list(struct chips *x) {
    if (x -> next != NULL) {
        free_list(x -> next);
    }
    free(x);
    return NULL;
}

struct chips * remove_node(struct chips *front, char *na, float pr) {
    if (front == NULL) {
        return NULL;
    }
    else if (strcmp(front -> name, na) == 0 && pr == front -> price) {
        struct chips *save = front -> next;
        free(front);
        return front -> next;
    }
    front -> next = remove_node(front -> next, na, pr);
    return front;
}
