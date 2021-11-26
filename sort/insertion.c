#include<stdio.h>
#include<stdlib.h>

void insertion_sort(int arr[],int n,int g){
    for(int i=1;i<n;i++){
        int j=i-1,k = arr[i];
        while(j>=0 && arr[j]>k){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = k;
    }
}

int main(){
    int arr[] = {5,4,3,2,1};
    insertion_sort(arr,5,1);
    printf("Sorted Array: ");
    for(int i=0;i<5;i++)printf("%d ",arr[i]);
    return 0;
}