#include"header.h"
main()
{
int i=10;
if(fork()==0)
printf("in child=%d\n",i);
else{
i=90;
printf("in parent=%d\n",i);}
}
