//Write C code that get array elements from user ,then check the elements whether odd or even , and calculate the summation of odd and even numbers separately.

#include <stdio.h>

void main(void) {
	int n;
	printf("number of elements: ");
	scanf("%d", &n);
	int arr[n];
	int evenSum = 0, oddSum = 0;

	for (int i = 0; i < n; i++) {
		printf("Enter element: ");
		scanf("%d", &arr[i]);

		if (arr[i] % 2 == 0)
			evenSum += arr[i];
		else
			oddSum += arr[i];
	}
	
	printf("Summation of even elements in the given array is %d\n", evenSum);
	printf("Summation of odd elements in the given array is %d\n", oddSum);
}
