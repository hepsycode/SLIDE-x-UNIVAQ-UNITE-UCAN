#include <stdint.h>
#include <8051.h>
#include <values.h>

typedef long TARGET_TYPE;
typedef uint8_t TARGET_INDEX;

//void prototype(int8_t n);

  TARGET_INDEX i;
  TARGET_TYPE s = 0;

void resetValues()
{
	P0 = 0;
	P1 = 0;
	P2 = 0;
	P3 = 0;
}

TARGET_TYPE fac1 (TARGET_TYPE n)
{
  if (n == 0)
     return 1;
  else
     return (n * fac1 (n-1));
}

void fac(TARGET_TYPE n)
{
  // n = 5;
  for (i = 0;  i <= n; i++)
      s += fac1 (i);
}

void main()
{
	fac(n);
	resetValues();
}