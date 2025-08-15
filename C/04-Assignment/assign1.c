// Write C Function  that get The Result of nPr , Note: Use the Factorial function as the base of this function .

#include <stdio.h>
int fact(int num);
int npr(int n , int r);


void main(void) {
	int n,r;
	printf("Enter n: ");
	scanf("%d",&n);
	printf("Enter r: ");
	scanf("%d",&r);
	int result = npr(n,r);
	result == -1 ? printf("Make sure r should be smaller than n and both n,r aren't smaller than zero.") :  printf("The result is %d" , result);
} 

int fact(int num){
	if (num == 0 || num == 1)
		return 1;

	int factorial = num;
	while (--num > 0)
		factorial *= num;
	return factorial;
}

int npr(int n , int r) {
	if(n<r || n < 0 || r < 0)return -1;
	return fact(n)/fact(n-r);
}