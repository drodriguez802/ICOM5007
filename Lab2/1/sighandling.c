/* Sample program to handle system signals */
#include <signal.h>
#include <stdio.h>
void * myhandler(int myint)
{
if(myint==2){
printf("It was a Ctrl+C signal\n");
}
else if(myint==15){
printf("Signal is kill!\n");
}
exit(0);
}
int main()
{
signal( SIGINT, (void *) myhandler );
signal( SIGTERM, (void *) myhandler );
while(1) {
printf("Doing Nothing...\n");
sleep(1);
}
}
