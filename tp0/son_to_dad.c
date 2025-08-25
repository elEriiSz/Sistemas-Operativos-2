#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
  int fildes[2];
  const int BUFFER_SIZE = 128;
  char buffer[BUFFER_SIZE];
  ssize_t nbytes;

  if(pipe(fildes)==-1){
    printf("Error en la creacion del pipe\n");
    return -1;
  }

  switch (fork()) {
  case -1:
    //Error
    printf("Error en la creacion del hijo\n");
    break;
  case 0:
    //Hijo
    close(fildes[0]);
    write(fildes[1], "Mensaje del hijo\n", 17);
    close(fildes[1]);
    sleep(1);
    exit(0);
    break;
  default:
    //Padre
    close(fildes[1]);
    nbytes = read(fildes[0], buffer, BUFFER_SIZE);
    buffer[nbytes] = '\0';
    printf("%s", buffer);
    close(fildes[0]);
    break;
  }


  return 0;
}
