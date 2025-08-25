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
  
  while(1){
    int fd = open(path, O_RDONLY);
    read(fd, buffer, 128);
    printf("%s\n",buffer);
    close(fd);
  };
  
  return 0;
}
