#include <stdint.h>
#if (!defined(_GCOV_EXE_))
#include <8051.h>
#endif
#include <values.h>

typedef int8_t TARGET_TYPE;
typedef uint8_t TARGET_INDEX;

#ifndef RES
#define RES
TARGET_TYPE res[size][size];
#endif

	TARGET_INDEX i, j, k, tot = 0; 

#if (!defined(_GCOV_EXE_))
void resetValues()
{
	P0 = 0;
	P1 = 0;
	P2 = 0;
	P3 = 0;
}
#endif

void matrix_mul()
{
	/* 
	 * If the number of columns of A is different from the b's rows number then 
	 * the multiplication can't be done 
	 
	/* Iterates through the rows of A */
	for(i = 0; i < size; i++)
	{
		/* Iterates through the columns of B */
		for(k = 0; k < size; k++)
		{
			/* 
			 * Iterates through the columns of A. We need of the "tot" variable to remember 
			 * the value of an element in res array
			 */

			for(tot = 0, j = 0; j < size; j++)
				tot += (a[i][j] * b[j][k]);

			res[i][k] = tot;
		}
	}
}

void main()
{
	matrix_mul();
	#if (!defined(_GCOV_EXE_))
	resetValues();
	#endif
}
