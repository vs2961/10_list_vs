struct chips {
    float price;
    char name[256];
};

void print_struct(struct chips x);
struct chips *new_chips(float pr, char *it);
void change_chips(struct chips *x, char *it, float pr);
void print_list(struct chips *p);
struct chips * insert_front(struct chips *p, char *na, float pr);
struct chips * free_list(struct chips *x);
struct chips * remove_node(struct chips *front, char *na, float pr);
