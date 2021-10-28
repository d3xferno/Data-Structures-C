typedef struct node{
    int data;
    struct node *nxt;
}node;

typedef struct queue{
    node *f,*r;
}qll;

void enq(qll *q,int x);
int deq(qll *q);
void display(qll *q);