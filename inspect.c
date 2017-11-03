//Kristin Lin
//Systems pd10
//Work 09: Please follow the DIRections
//2017-11-02

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>


void directories(DIR * curr) {
  printf("directories in dir: \n");
  struct dirent * stats;
  char type;
  stats = readdir(curr);
  while (stats) {
    type = (*stats).d_type;
    if (type == DT_DIR) {
      printf("\t%s\n", (*stats).d_name);
    }
    stats = readdir(curr);
  }
}

void regs(DIR * curr) {
  printf("reg files in dir: \n");
  struct dirent * stats;
  char type;
  stats = readdir(curr);
  while (stats) {
    type = (*stats).d_type;
    if (type == DT_REG) {
      printf("\t%s\n", (*stats).d_name);
    }
    stats = readdir(curr);
  }
}

void scan(char * path) {
  DIR * curr;
  //look for dirs
  curr = opendir(path);
  directories(curr);
  closedir(curr);
  //start at beginning for regs
  curr = opendir(path);
  regs(curr);
  closedir(curr);
}

int main() {
  printf("\nSCANNING CURRENT DIR: \n");
  printf("-------------------------------------\n");
  scan(".");
}
