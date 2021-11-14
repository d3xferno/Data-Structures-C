#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct avl{
    int data,h;
    struct avl *l,*r;
}avl;

int ht(avl *t){
    if(t)return t->h;
    return 0;
}

int max(int x,int y){
    return (x>y)?x:y;
}

avl *rRotate(avl *t){
    avl *lft = t->l,*lsub = lft->r;
    lft->r = t;
    t->l = lsub;
    t->h = 1+max(ht(t->l),ht(t->r));
    lft->h = 1+max(ht(lft->l),ht(lft->r));
    return t;
}

avl *lRotate(avl *t){
    avl *rgt = t->l,*rsub = rgt->r;
    rgt->l = t;
    t->r = rsub;
    t->h = 1+max(ht(t->l),ht(t->r));
    rgt->h = 1+max(ht(rgt->l),ht(rgt->r));
    return t;
}

avl *insert(avl *t,int x){
    if(t==NULL){
        avl *nw = (avl*)malloc(sizeof(avl));
        nw->data = x;
        nw->l = nw->r = NULL;
        nw->h = 1;
        return nw;
    }
    if(x<t->data){
        t->l = insert(t->l,x);
    }
    else if(x>t->data){
        t->r = insert(t->r,x);
    }
    else return t;

    int bal = ht(t->l)-ht(t->r);
    if(bal>1 && x < t->l->data){//ll
        return rRotate(t);
    }
    if(bal<-1 && x > t->r->data){//rr
        return lRotate(t);
    }
    if(bal>1 && x>t->l->data){//lr
        t->l = lRotate(t->l);
        return rRotate(t);
    }
    if(bal<-1 && x<t->r->data){//rl
        t->r = rRotate(t->r);
        return lRotate(t);
    }
    return t;
}

void inorder(avl *t){
    if(t){
        inorder(t->l);
        printf("%d ",t->data);
        inorder(t->r);
    }
}

void curlvl(avl *t,int lvl){
    if(!t)return;
    if(lvl==1)printf("%d ",t->data);
    else{
        printf("\n");
        curlvl(t->l,lvl-1);
        curlvl(t->r,lvl-1);
    }
}

void lvlorder(avl *t,int h){
    for(int i=1;i<=h;i++){
        curlvl(t,i);
    }
}


int cmp(char x[],char y[]){//ex:badger badge
    int xl = strlen(x),yl = strlen(y);
    int l=0,r=0,f=0;
    while(x[l]!='\0' && y[r]!='\0'){
        if(x[l]>y[r]){
            f=1;
            break;
        }
        l++;
        r++;
    }
    if(f==0 && xl>yl)return 1;
    if(f==0 && xl<=yl)return 0;
    if(f==1)return 1;
}


int height(avl *t){
    if(t==NULL)return 0;

    int lh = height(t->l);
    int rh = height(t->r);

    return lh>rh?lh+1:rh+1;
}

int main(){
    avl *t = NULL;
    t = insert(t,10);
    t = insert(t,15);
    t = insert(t,5);
    inorder(t);
    printf("\n");
    lvlorder(t,height(t));
    return 0;
}
