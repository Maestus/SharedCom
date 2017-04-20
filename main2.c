#include "conduct.h"
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  struct conduct * conduit = conduct_open("file");
  while(1){
    conduct_write(conduit, "13 caracteres",13);
    conduct_write(conduit, "9 en plus",9);
  }
  return 0;
}
