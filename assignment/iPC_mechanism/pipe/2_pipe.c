/*
PIPE
2.a)Parent process send one integer value to child process.
   b)child after recieving  integer value from parent ,display the result on screen.
*/
#include"header.h"
int main(){
int p[2];
pipe(p);
if(fork()){
int k;
printf("Enter data in Digit..\n");
scanf("%d",&k);
write(p[1],&k,sizeof(k));
}
else{
int k;
read(p[0],&k,sizeof(k));
printf("Data::%d\n",k);
}
}
