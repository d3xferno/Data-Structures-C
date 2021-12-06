#include "impl.h"
#include<stdio.h>
#include<stdlib.h>

void path(city *c,char x,char y){
    qll *q = BFS(c,x);
    int f=0;
    while(q->f){
        if((q->f->data)==(y-'A')){
            f=1;
            break;
        }
        q->f = q->f->nxt;
    }
    if(f)printf("\nExists");
    else printf("\nDoesnt Exist");
}

void concomp(city *c){
    int n = c->vtx;
    for(int i=0;i<n;i++){
        qll *q = BFS(c,(char)i+65);
        display(q);
        printf("\n");
    }

}

int main(){
    city *c = (city *)malloc(sizeof(city));
    create(c);
    dis(c);
    //path(c,'F','B');
    //path(c,'A','B');
    printf("\n");
    concomp(c);
    return 0;
}