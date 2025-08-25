#include<stdio.h>
#include<signal.h>

int stop_flag = 0; 

void intHandler(int sig){
  printf("Se lanzo la señal INT\n");
}
void killHandler(int sig){
  printf("Se lanzo la señal KILL\n");
}
void stopHandler(int sig){
  printf("Se lanzo la señal STOP\n");
}
void usr1Handler(int sig){
  printf("Se lanzo la señal USR1\n");
  stop_flag = 1;
}

int main(int argc, char** argv)
{
  signal(SIGINT,intHandler);
  signal(SIGKILL,killHandler);
  signal(SIGSTOP,stopHandler);
  signal(SIGUSR1,usr1Handler);

  while(stop_flag==0){
  ;
  }

  return 0;
}
