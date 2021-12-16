#include<stdio.h>
#include<stdlib.h>

typedef struct Hash{
	int ht[1000];
	int sz;
}hash;

void init(hash *h,int x){
	h->sz = x;
	for(int i=0;i<h->sz;i++)h->ht[i]=0;
}

void insert(hash *h,int x){
	int probes=0;
	int si = x%(h->sz);
	int idx=si;
	do{
		if(!h->ht[si]){
			h->ht[si]=x;
			break;
		}
		else{
			si = (si+1)%(h->sz);
			probes++;
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

void find(hash *h,int x){
	int probes=0;
	int si = x%(h->sz);
	int idx=si;
	do{
		if(h->ht[si]==x){
			printf("Element found at index:%d\n",si);
			break;
		}
		else{
			si = (si+1)%(h->sz);
			probes++;
		}
	}while(idx!=si);

	printf("probes:%d\n",probes);
}


int main(void) {
	hash *h;
	h = (hash *)malloc(sizeof(hash));
	init(h,10);
	insert(h,43);
	insert(h,19);
	insert(h,69);
	insert(h,57);
	insert(h,35);
	display(h);
	find(h,69);
}