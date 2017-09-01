#include"header.h"
main(int argc,char **argv)
{
if(argc<2){
printf(" Usage for kill other: kill [-s sigspec | -n signum | -sigspec] pid | jobspec ... or kill -l [sigspec]\n");
printf(" Usage for Raise: [-n signum]\n");
return;
}
else{
int i;
if(argc==2){
printf("Killed it self...\n");
 i=kill(getpid(),atoi(argv[1]));
printf("sgefhjaxdjvhxvdjvjhgsdjvhgsvjhsgfjzhgjsagbhsagvbhs\n");
}
else{
printf("Killed other Process\n");
i=kill(atoi(argv[1]),atoi(argv[2]));
}
}
}
