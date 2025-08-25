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
  mkfifo(path,0666);  
  return 0;
}
