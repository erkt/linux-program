#include"header.h"
main(int argc,char **argv)
{
if(argc<2){
printf(" Usage: kill [-s sigspec | -n signum | -sigspec] pid | jobspec ... or kill -l [sigspec]\n");
return;
}
else{
int i;
i=kill(atoi(argv[1]),atoi(argv[2]));
}
}

