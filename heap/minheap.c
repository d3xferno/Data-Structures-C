#include<stdio.h>
#include<stdlib.h>

typedef struct heap{
    int data[101];
    int cur,sz;
}heap;

void init(heap *h,int size){
    h->data[0]=-1;
    h->cur = 0;
    h->sz = size;
}

void insert(heap *h,int x){
    h->data[++(h->cur)] = x;
    int i=h->cur;
    while(i>0 && h->data[i/2]>h->data[i]){
        int tmp;
        tmp = h->data[i/2];
        h->data[i/2] = h->data[i];
        h->data[i] = tmp;
        i/=2;
    }
}

void delete(heap *h){
    int ans = h->data[1];
    int last = h->data[h->cur];
    h->cur--;
    h->data[1] = last;
    int child = 2;
    
    printf("\n%d",ans);
}

void display(heap *h){
    for(int i=1;i<=h->cur;i++){
        printf("%d ",h->data[i]);
    }
}

int main(){
    heap *h = (heap *)malloc(sizeof(heap));
    insert(h,1);
    insert(h,2);
    insert(h,3);
    display(h);
    return 0;
}