#include"header.h"
main(){
int p[2];
pipe(p);
printf("p[0]:Read end::%d\n",p[0]);
printf("p[1]:Write end::%d\n",p[1]);
if(fork()){
char s[20];
printf("Enter Data::");
scanf("%s",s);
write(p[1],s,strlen(s)+1);
}
else{
char s1[20];
printf("Before Read..\n");
read(p[0],s1,sizeof(s1));
printf("After Read..%s\n",s1);
}
}

