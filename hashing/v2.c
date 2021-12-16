#include<stdio.h>
#include<stdlib.h>

typedef struct Hash{
	int ht[10000];
	int sz;
}hash;

void init(hash *h,int x){
	h->sz = x;
	for(int i=0;i<h->sz;i++)h->ht[i]=0;
}

void insert(hash *h,int x){
	int probes=0;
	int si = x%(h->sz);
	int idx=si,v=si;
	do{
		if(!h->ht[si]){
			h->ht[si]=x;
			break;
		}
		else{
            probes++;
			si = (v+probes*probes)%(h->sz);
		}
	}while(idx!=si);

	printf("probes:%d\n",probes);
}

void display(hash *h){
	for(int i=0;i<h->sz;i++){
		if(h->ht[i]!=0)printf("%d->%d\n",i,h->ht[i]);
		else printf("%d->No element\n",i);
	}
}

int find(hash *h,int x){
	int probes=0;
	int si = x%(h->sz);
	int idx=si;
	do{
		if(h->ht[si]==x){
			return 1;
		}
		else{
			si = (si+1)%(h->sz);
			probes++;
		}
	}while(idx!=si);

    return 0;
}

void range(hash *h,int l,int r){
    int cnt=0;
    for(int i=l;i<=r;i++){
        cnt+=find(h,i);
    }
    printf("\ncnt:%d",cnt);
}


int main(void) {
	hash *h;
	h = (hash *)malloc(sizeof(hash));
	init(h,10);
	insert(h,23);
	insert(h,45);
	insert(h,69);
	insert(h,87);
	insert(h,48);
    insert(h,67);
    insert(h,54);
    insert(h,66);
    insert(h,53);
	display(h);
    range(h,40,60);
}