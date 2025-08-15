/*
 Write a C code that define 3 int variables x, y and z and 
 3 pointers to int p, q and r. Set x, y, z to three distinct values. 
 Set p, q, r to the addresses of x, y, z respectively. 
 1. Print with labels the values of x, y, z, p, q, r, *p, *q, *r 
 2. Print the message: Swapping pointers.
 3. Execute the swap code: r = p; p = q; q = r;
 4. Print with labels the values of x, y, z, p, q, r, *p, *q, *r
*/
#include <stdio.h>

	void print(int* p,int* q,int* r ,int x,int y,int z) {
	printf("The value of X: %d\n", x);
	printf("The value of Y: %d\n", y);
	printf("The value of Z: %d\n", z);
	printf("The memory address of pointer p: %p\n",p);
	printf("The memory address of pointer q: %p\n",q);
	printf("The memory address of pointer r: %p\n",r);
	printf("The value of x with the pointer p: %d\n",*p);
	printf("The value of x with the pointer q: %d\n",*q);
	printf("The value of x with the pointer r: %d\n",*r);
	}

	void swappingPointers(int** p , int** q, int** r) {
		int* temp_1 = *r;
		*r = *p;
		int* temp_2 = *q;
		*q = temp_1;
		*p = temp_2;
	}

	
void main(void) {
	
	int x=1,y=2,z=3;
	
	int* p = &x, *q = &y,*r = &z;
	
	int* temp_1,temp_2;
	
	print(p,q,r,x,y,z);
	printf("Swapping pointers:\n");
	swappingPointers(&p, &q, &r);
	print(p,q,r,x,y,z);

}

