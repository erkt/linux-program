#include"header.h"
void abc(void);
main()
{
atexit(abc);
printf("hello\n");
sleep(10);
printf("come out of sleep\n");
exit(1);
}
void abc(void)
{
printf("-------------------------------------------------\n");
}

