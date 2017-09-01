/*5. Write a program to ignore the termination of process when its terminal will close.     
                  Hint : use   SIGHUP signal & signal().*/
#include"header.h"
int main(){
signal(SIGHUP,SIG_IGN);
while(1);
}
