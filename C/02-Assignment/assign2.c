/*
Write C Code that take two numbers from user and    
take another number that represents the corresponding operation will be performed to these two numbers for   
 example 1 represents addition, 2 represents subtraction, 
 3 represents multiplication and 4 represents division .
 Use switch case to select user choice then print the Result 
*/

#include <stdio.h>

void main(void) {
	
	
	int a,b,c ;
	printf("Enter two numbers : (Don't forget to add spaces between them) : ");
	scanf("%d %d" , &a , &b );
	
	printf("Enter operation number needed\n1 represents addition,\n2 represents subtraction,\n3 represents multiplication,\n4 represents division : ");
	scanf("%d" ,&c );
	
	printf("\nThe result is ");
	switch (c) {
		case 1 :
		printf("%d" , a + b);
		break;
		case 2 : 
		printf("%d" , a - b);
		break;
		case 3 : 
		printf("%d" , a * b);
		break;
		default : 
		printf("%d" , a / b);
		break;
	}
}