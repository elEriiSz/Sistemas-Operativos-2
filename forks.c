#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
  pid_t b = fork();
  if (b == 0) {
    printf("B is my name.\nMy PID:%d\nMy PPID:%d\n\n", getpid(), getppid());
    pid_t d = fork();
    if (d==0) {
      printf("D is my name.\nMy PID:%d\nMy PPID:%d\n\n", getpid(), getppid());
      sleep(10);
      return 0;
    }
    pid_t e = fork();
    if (e==0) {
      printf("E is my name.\nMy PID:%d\nMy PPID:%d\n\n", getpid(), getppid());
      sleep(10);
      return 0;
    }
    pid_t f = fork();
    if (f==0) {
      printf("F is my name.\nMy PID:%d\nMy PPID:%d\n\n", getpid(), getppid());
      sleep(10);
      return 0;
    }
    wait(NULL);
    return 0;
  }

  pid_t c = fork();
  if(c==0){
    printf("C is my name.\nMy PID:%d\nMy PPID:%d\n\n", getpid(), getppid());
    sleep(10);
    return 0;
  }
  printf("A is my name.\nMy PID:%d\nMy PPID:%d\n\n", getpid(), getppid());
  wait(NULL);
  return 0;

}
