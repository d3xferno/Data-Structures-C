#include "impl.h"
#include<stdio.h>
#include<stdlib.h>

void main(){
    qll *q;
    q = (qll *)malloc(sizeof(qll));
    q->f = q->r = NULL;
    enq(q,0);
    enq(q,1);
    enq(q,2);
    enq(q,3);
    enq(q,4);
    display(q);
    int k=2,c=4;
    while(c--){
        for(int i=0;i<k;i++){
            enq(q,deq(q));
        }
        printf("\n%d",deq(q));
    }
    printf("\nWinner:%d",deq(q));
}