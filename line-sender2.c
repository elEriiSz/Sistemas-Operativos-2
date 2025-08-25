#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
  char buffer[128];
  char* path = "./cola";
  
  int fd = open(path, O_WRONLY);
  char* mensaje = "enviando dato2 al servidor!";
  write(fd, mensaje, 27);
  close(fd);
  
  return 0;
}
