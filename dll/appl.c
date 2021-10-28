#include <stdio.h>
#include <stdlib.h>
#include "impl.h"

int main(void) {
    struct listAdt *head = NULL;
    int t,choice,x,k;
    t=1;
    char c,d,temp;
    printf("1.InsertFront\n2.InsertEnd\n3.InsertMiddle\n4.Display\n5.Search\n6.Delete\n7.Palindrome\n8.Seperation\n9.Swap\n");
    while(t){
        printf("Enter the choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                scanf("%c",&temp);
                printf("Character(if):");
                scanf("%c",&c);
                head = insertFront(head,c);
                break;
            case 2:
                scanf("%c",&temp);
                printf("Character:");
                scanf("%c",&c);
                insertEnd(head,c);
                break;
            case 3:
                scanf("%c",&temp);
                printf("Characters:");
                scanf("%c %c",&c,&d);
                insertMiddle(head,c,d);
                break;
            case 4:
                printf("\n=>");
                display(head);
                break;
            case 5:
                scanf("%c",&temp);
                printf("Enter Character to be searched:");
                scanf("%c",&c);
                x = searchItem(head,c);
                printf("Count:%d\n",x);
                break;
            case 6:
                scanf("%c",&temp);
                printf("Enter Character to be deleted:");
                scanf("%c",&c);
                deleteItem(&head,c);
                break;
            case 7:
                isPalindrome(head);
                break;
            case 8:
                sep(head);
                break;
            case 9:
                scanf("%d",&k);
                swaps(head,k);
                display(head);
                break;
            default:
                printf("Wrong choice\n");
                break;
        }
        printf("Wanna continue?:");
        scanf("%d",&t);
    }
    return 0;
}