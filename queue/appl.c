#include<stdio.h>
#include<stdlib.h>
#include "impl.h"

void main(){
    queue *t;
    t=NULL;
    push(&t,1);
    push(&t,2);
    push(&t,3);
    display(t);
    deq(&t);
    display(t);
    deq(&t);
    display(t);
}