#include<stdio.h>
#include<dlfcn.h>
main()
{
int (*p)(int,int);
void *handler;
int n1,n2,n3,op;
printf("Enter two Number::");
scanf("%d %d",&n1,&n2);
printf("option::");
scanf("%d",&op);
if(op==1)
{
handler=dlopen("./dynamiclib.so",RTLD_LAZY);
if(handler==0){
printf("%s\n",dlerror());
return;
}
p=dlsym(handler,"sum");
if(p==0){
printf("%s\n",dlerror());
return;
}
n3=(*p)(n1,n2);
printf("n3=%d\n",n3);
dlclose(handler);
}
else if(op==2)
{
handler=dlopen("./dynamiclib.so",RTLD_LAZY);
if(handler==0){
printf("%s\n",dlerror());
return;
}
p=dlsym(handler,"sub");
if(p==0){
printf("%s\n",dlerror());
return;
}
n3=(*p)(n1,n2);
printf("n3=%d\n",n3);
dlclose(handler);
}
else if(op==3)
{
handler=dlopen("./dynamiclib.so",RTLD_LAZY);
if(handler==0){
printf("%s\n",dlerror());
return;
}
p=dlsym(handler,"mul");
if(p==0){
printf("%s\n",dlerror());
return;
}
n3=(*p)(n1,n2);
printf("n3=%d\n",n3);
dlclose(handler);
}
else{
printf("Unknown option...\n");
return;
}
}
