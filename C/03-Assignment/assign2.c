/*
Write C Code that take number from user and get its

multiplication table .

Boundaries: the table start from the entered num * 1

And ends at num * num
*/

#include <stdio.h>

void main(void) {
	printf("Enter a num to print its multiplication table: ");
	int num;
	scanf("%d",&num);
	for(int i = 1; i <= num ; i++ ) {
		printf("%d  X %d = %d\n" , i , num , num * i );
	}
}