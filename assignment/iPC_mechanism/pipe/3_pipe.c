/*
PIPE
3.a)Parent process send one Character to child process.
   b)child recieve the Character  from parent and  display recevied character on screen
*/
#include"header.h"
int main(){
int p[2];
pipe(p);
if(fork()){
char c;
printf("Enter the character..\n");
scanf("%c",&c);
write(p[1],&c,sizeof(c));
}
else{
char c;
read(p[0],&c,sizeof(c));
printf("Data::%c\n",c);
}
}

