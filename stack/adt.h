struct stack{
    char data;
    struct stack *nxt;
};

void push(struct stack **t,char x);
void pop(struct stack **t);
void display(struct stack *t);
int isEmpty(struct stack *t);
char top(struct stack *t);

void brac(struct stack *t,char *p);