// Write C Code that get array numbers from user then sort this array and at final print the minimum and maximum value of the array .

#include <stdio.h>

void main(void) {
	int n;
	printf("number of elements: ");
	scanf("%d", &n);
	int arr[n];

	for(int i = 0; i < n; i++) {
		printf("Enter element: ");
		scanf("%d", &arr[i]);
	}

	for(int i = 1; i < n; i++) {
		int element = arr[i];
		int p = i - 1;

		while(p >= 0 && arr[p] > element) {
			arr[p + 1] = arr[p];
			p--;
		}
		arr[p + 1] = element;
	}

	for(int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	printf("Max element is %d and min element is %d\n", arr[n - 1], arr[0]);
}
