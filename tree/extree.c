#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct tree{
    char data;
    struct tree *l,*r;
}tree;

tree *insert(tree *rt,int x){
    if(rt==NULL){
        rt = (tree*)malloc(sizeof(tree));
        rt->data = x;
        rt->l=rt->r=NULL;
    }
    if(rt->data>x)rt->l = insert(rt->l,x);
    if(rt->data<x)rt->r = insert(rt->r,x);
    return rt;
}

void inorder(tree *t){
    if(t){
        inorder(t->l);
        printf("%c ",t->data);
        inorder(t->r);
    }
}


struct stack{
    tree *addr;
    struct stack *nxt;
};

void push(struct stack **t,tree *x){
    struct stack *temp;
    temp = (struct stack *)malloc(sizeof(struct stack));
    temp->addr = x;
    temp->nxt = *t;
    *t = temp;
}

void pop(struct stack **t){
    *t = (*t)->nxt;
}

tree* infix(char exp[]){
    struct stack *st = (struct stack *)malloc(sizeof(struct stack));
    for(int i=0;exp[i]!='\0';i++){
        char o = exp[i];
        if(o == '%' || o == '/' || o == '*' || o == '+' || o == '-'){
            tree *new = (tree *)malloc(sizeof(tree));
            new->data = o;
            new->r = st->addr;
            pop(&st);
            new->l = st->addr;
            pop(&st);
            push(&st,new);
        }else{
            tree *op = (tree *)malloc(sizeof(tree));
            op->data = o;
            op->l = op->r = NULL;
            push(&st,op);
        }
    }
    return st->addr;
}

int eval(tree *t){
    if(t==NULL)return 0;
    if(t->l==NULL && t->r==NULL){
        return t->data-'0';
    }
    int l = eval(t->l),r= eval(t->r);
    if(t->data=='+')return l+r;
    if(t->data=='-')return l-r;
    if(t->data=='*')return l*r;
    if(t->data=='/')return l/r;
}

void main(){
    char exp[100];
    printf("Enter the expression:45*6+\n");
    tree *et = infix("45*6+");
    printf("INORDER:");
    inorder(et);
    printf("\n");
    printf("PREORDER:+*456");
    printf("\nPOSTORDER:45*6+");
    int ans = eval(infix("45*6+"));
    printf("\nEvaluation:%d",ans);
}
