#include<stdio.h>
main()
{
printf("Helloo...pid:%d  ppid:%d\n",getpid(),getppid());
system("ls");
printf("Helloo...pid:%d  ppid:%d\n",getpid(),getppid());
system("pwd");
printf("Helloo...pid:%d  ppid:%d\n",getpid(),getppid());
printf("Haiiiiiii...\n");
printf("Helloo...pid:%d  ppid:%d\n",getpid(),getppid());
}


