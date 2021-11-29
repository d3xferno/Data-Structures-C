#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct avl{
    int h;
    char w[100],m[100];
    struct avl *l,*r;
}avl;

int ht(avl *t){
    if(t)return t->h;
    return 0;
}

int max(int x,int y){
    return x>y?x:y;
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

avl *insert(avl *t,char x[],char y[]){
    if(t==NULL){
        avl *nw;
        nw = NULL;
        nw = (avl*)malloc(sizeof(avl));
        strcpy(nw->w,x);
        strcpy(nw->m,y);
        nw->l = nw->r = NULL;
        nw->h = 1;
        return nw;
    }
    if(strcmp(t->w,x)>0){
        t->l = insert(t->l,x,y);
    }
    else if(strcmp(t->w,x)<0){
        t->r = insert(t->r,x,y);
    }
    else return t;

    int bal = ht(t->l)-ht(t->r);
    if(bal>1 && (strcmp(t->l->w,x)>0)){//ll
        return rRotate(t);
    }
    if(bal<-1 && (strcmp(t->r->w,x)<0)){//rr
        return lRotate(t);
    }
    if(bal>1 && (strcmp(t->l->w,x)<0)){//lr
        t->l = lRotate(t->l);
        return rRotate(t);
    }
    if(bal<-1 && (strcmp(t->r->w,x)>0)){//rl
        t->r = rRotate(t->r);
        return lRotate(t);
    }
    return t;
}

void inorder(avl *t){
    if(t){
        inorder(t->l);
        printf("%s-%s\n",t->w,t->m);
        inorder(t->r);
    }
}

void curlvl(avl *t,int lvl){
    if(!t)return;
    if(lvl==1)printf(" %s:%s",t->w,t->m);
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

int height(avl *t){
    if(t==NULL)return 0;

    int lh = height(t->l);
    int rh = height(t->r);

    return lh>rh?lh+1:rh+1;
}


void search(avl *t,char x[]){
    if(t!=NULL){
        if(strcmp(t->w,x)>0)search(t->l,x);
        else if(strcmp(t->w,x)<0)search(t->r,x);
        else if(strcmp(t->w,x)==0)printf("Meaning:%s",t->m);
    }
}

int main(){
    avl *t = NULL;
    t = insert(t,"bisk","soup");
    t = insert(t,"cite","refer");
    t = insert(t,"boom","sound");
    t = insert(t,"able","oppurtunity");
    t = insert(t,"aged","old");
    t = insert(t,"crew","group of people");
    inorder(t);
    printf("\n");
    search(t,"cite");
    //lvlorder(t,height(t));
    return 0;
}
