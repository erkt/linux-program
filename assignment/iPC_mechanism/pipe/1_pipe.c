/*
Pipe:
 1.a)Parent process will send one string to child process?
   b)child recieve the string from parent and display recived data on screen  ?
*/
#include"header.h"
main(){
int p[2];
pipe(p);
if(fork()){
char s[20];
printf("Enter data:");
scanf("%s",s);
write(p[1],s,strlen(s)+1);
}
else{
char s[20];
read(p[0],s,sizeof(s));
printf("Data:%s\n",s);
}
}
