#include"header.h"
int main(int argc,char**argv){
if(argc!=2){
printf("Usage: ./a.out filename\n");
return;
}

close(1);
int fd=open(argv[1],O_RDWR|O_APPEND|O_CREAT,0644);
perror("open");
fd=dup(fd);
int i,j,k=0,l=0;
char ch[100]={},q[100]={},q1[100]={},op; 
//read(fd,&i,sizeof(int));
read(fd,ch,sizeof(char)*100);
printf("DATA::%s\n",ch);
for(i=0;ch[i];i++)
if(ch[i]>='0'&&ch[i]<='9')
q[k++]=ch[i];
else
break;

printf("%s\n",q);
if(ch[i]==' ')
i++;
if(ch[i]=='+'||ch[i]=='-'||ch[i]=='*'||ch[i]=='/'||ch[i]=='%')
op=ch[i++];

printf("%c\n",op);
for(i;ch[i];i++)
if(ch[i]!=' ')
q1[l++]=ch[i];

printf("%s\n",q1);
int n=atoi(q);
int n1=atoi(q1);
printf("%d + %d =%d\n",n,n1,n+n1);


}
