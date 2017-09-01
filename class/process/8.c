#include"header.h"
main()
{
int i;
/*for(i=0;i<3;i++)
{
if(fork()==0)
printf("Haiiiii..\n");
else
;
}
for(i=0;i<3;i++)
{
if(fork()==0)
printf("Haiiiii..\n");
else
break;
}*/
for(i=0;i<3;i++)
{
if(fork()==0){
printf("Haiiiii..\n");break;}
else
;
}

}
