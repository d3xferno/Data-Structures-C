#include <stdio.h>

int shellSort(int arr[], int n)
{
	for (int gap = n/2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i += 1)
		{
			int temp = arr[i];
			int j;		
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];
			arr[j] = temp;
		}
	}
	return 0;
}


int main()
{
	int arr[] = {12, 34, 54, 2, 3}, i;
	int n = sizeof(arr)/sizeof(arr[0]);
	shellSort(arr,n);
	for(int i=0;i<n;i++)printf("%d ",arr[i]);
	return 0;
}
