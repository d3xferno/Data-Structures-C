typedef struct queue{
    int data;
    struct queue *nxt;
}queue;

void push(queue **t,int x);
void pop(queue **t);
void display(queue *t);
int isEmpty(queue *t);
int top(queue *t);
void deq(queue **t);