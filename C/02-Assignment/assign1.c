/* Write C Code that ask user to enter three numbers then
print the greatest number.

*/

#include <stdio.h>

void main(void) {
	
	
	int a,b,c ;
	printf("Enter three numbers : (Don't forget to add spaces between them) : ");
	scanf("%d %d %d" , &a , &b , &c);
	if ( a > b && a > c) printf ("%d is the greatest number of them" , a);
	else if ( b > a && b > c ) printf ("%d is the greatest number of them" , b);
	else printf ("%d is the greatest number of them",c);
}