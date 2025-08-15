/*Write a C code that defines a function which takes an array as input 
argument and apply the bubble sorting algorithm on it, 
then print the result.
*/

#include <stdio.h>

void bubbleSort(int arr[],int size) {
	int flag;
	for(int i = 0 ; i < size ; i++ ) {
		flag =  0;
		for(int j = 0 ; j < size - i -1 ; j++) {
			
			if(arr[j+1] < arr[j]) {
				int temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j]   = temp;
				flag = 1;
			}
		}
		if(flag == 0) {
				break;
			}
	}
}

void main(void) {
	int n;
	printf("Number of elements: ");
	scanf("%d", &n);
	int arr[n];

	for(int i = 0; i < n; i++) {
		printf("Enter element %d: ",i);
		scanf("%d", &arr[i]);
	}
	
	bubbleSort(arr,n);
	
	for(int i = 0; i < n; i++) {
		printf("%d ",arr[i]);
	}	
}
