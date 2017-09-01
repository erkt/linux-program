#include"header.h"
main()
{
char *ch[]={"ls","-l","-i",NULL};
execvp(ch[0],ch);
}
