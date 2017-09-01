#include"header.h"
main()
{
if(fork()==0)
{
printf("in\n");
}
else
printf("out\n");
while(1);
}

