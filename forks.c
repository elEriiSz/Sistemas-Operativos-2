#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
  pid_t b = fork();
  if(b == 0){
    pid_t d = fork();
    pid_t e = fork();
    pid_t f = fork();
    if(d == 0){
      printf("D is my name.\nMy PID:%d\n. My PPID:%d\n\n", getpid(), getppid());
      while(1){
        
      }
    }else if(e == 0){
      printf("E is my name.\nMy PID:%d\n. My PPID:%d\n\n", getpid(), getppid());
      while(1){
        
      }
    }else if(f == 0){
      printf("F is my name.\nMy PID:%d\n. My PPID:%d\n\n", getpid(), getppid());
      while(1){
        
      }
    }else{
      printf("B is my name.\nMy PID:%d\n. My PPID:%d\n\n", getpid(), getppid());
      while(1){
        
      }
    }
    
  }else {
    pid_t c = fork();
    if(c == 0){
      printf("C is my name.\nMy PID:%d\n. My PPID:%d\n\n", getpid(), getppid());
      while(1){
        
      }
    }else {
      printf("A is my name.\nMy PID:%d\n. My PPID:%d\n\n", getpid(), getppid());
      while(1){
        
      }
    }
  }

  return 0;
}
