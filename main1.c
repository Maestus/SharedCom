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
  struct conduct * conduit = NULL;
  if( (conduit = conduct_create("file", 10, 20)) == NULL){
    return 1;
  }
  sleep(10);
  while(1){
    sleep(1);
    printf("Remplissage = %d\n", conduit->remplissage);
    printf("Lecture = %d\n", conduit->lecture);
    char * buff = malloc(conduit->capacity*sizeof(char));
    conduct_read(conduit, buff, 4);
    printf("[%s]\n", buff);
  }
  return 0;
}
