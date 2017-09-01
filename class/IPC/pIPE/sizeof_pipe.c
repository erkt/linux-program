/*#include"header.h"    ///  in that write goes in blocking mode bcoz of pipe is full
main(){
int p[2],c=0;
char ch='a';
pipe(p);
while(write(p[1],&ch,1)!=-1)
printf("Count::%d\n",++c);
printf("Done!!!!\n");
}
*/



#include"header.h"
main(){
int p[2],c=0;
char ch='a';
pipe2(p,O_NONBLOCK);
while(write(p[1],&ch,1)!=-1)
c++;
printf("Count::%d\nDone!!!!\n",c);
}
