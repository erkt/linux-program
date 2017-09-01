#include"header.h"
main(int argc,char **argv)
{
if(argc!=2){
printf("Usage: ./raise signal_number.\n");
return;
}
else{
int i;
printf("This is working?????\n");
i=raise(atoi(argv[1]));

printf("%d\n",i);
}
}
