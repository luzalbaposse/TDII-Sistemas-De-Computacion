void pointer_to_int(int);
void sizes();

struct node {
  int data;
  struct node *next;
};

void printList(struct node *, char *);
struct node *insert_at_beginning(struct node *, int);
struct node *delete_node(struct node *, int);
struct node *reverse_list(struct node *);
struct node *arrayToList(int *, int);

void pp_insert_at_beginning(struct node **, int);
void pp_delete_node(struct node **, int);
void pp_reverse_list(struct node **);
void pp_delete_node_elegant(struct node **, int);
