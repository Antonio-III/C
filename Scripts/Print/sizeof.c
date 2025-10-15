#include <stdio.h>

int main(int argc, char *argv[])
{
	double A[10];
	char *p = "mary mary quite contrary";
	printf("sizeof(char)   = %2zu\n", sizeof(char));
	printf("sizeof(int)    = %2zu\n", sizeof(int));
	printf("sizeof(float)  = %2zu\n", sizeof(float));
	printf("sizeof(double) = %2zu\n", sizeof(double));
	printf("sizeof(A)      = %2zu\n", sizeof(A));
	printf("sizeof(*A)     = %2zu\n", sizeof(*A));
	printf("sizeof(p)      = %2zu\n", sizeof(p));
	printf("sizeof(*p)     = %2zu\n", sizeof(*p));
	return 0;
}