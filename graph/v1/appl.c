#include "impl.h"
#include<stdio.h>
#include<stdlib.h>

int main(){
    city *c = (city *)malloc(sizeof(city));
    create(c);
    dis(c);
    BFS(c,'F');
    DFS(c,'A');
    return 0;
}