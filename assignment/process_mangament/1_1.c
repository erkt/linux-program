/*1. Write a program to execute ls , pwd & cal sequentially
a) Using system( )
		Hint : use fork().
*/


#include"header.h"
main()
{
	system("ls");
	printf("\n");
	system("pwd");
	printf("\n");
	system("cal");
	printf("\n");
}
