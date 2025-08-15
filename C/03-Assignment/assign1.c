/*
Write C Code that simulate an alarm system that ask the
user to enter the result of certain mathematical example ,
the system must keep asking the user to enter the result
till reach the correct result.
*/

#include <stdio.h>

void main(void) {
	printf("What is 1 + 2 ? ");
	int num;
	scanf("%d",&num);
	while (num != 3 ) {
		printf("Still Alarming!! Try again:\n");
		scanf("%d",&num);
	}
	printf("Alarm stopped!!");
}