#include <stdio.h>

void main(void) 
{
    for (int row = 0; row < 6; row++) {
        for (int column = 0; column < 12; column++) {
            if (column <= 6 + row && column >= 6 - row)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}
