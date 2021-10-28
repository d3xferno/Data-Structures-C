#include<stdio.h>

void main(){
    char str[100];
    scanf("%s",str);
    int len=0,flag=1;
    for(;str[len]!='\0';len++);
    for(int i=0;i<len;i++){
        if(str[i]!=str[len-i-1]){
            flag=0;
            break;
        }
    }
    if(flag)printf("Palindrome");
    else printf("Not a Palindrome");
}