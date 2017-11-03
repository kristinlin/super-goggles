//Kristin Lin
//Systems pd10
//Work 09: Please follow the DIRections
//2017-11-02

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>


//traverse through dir's contents with readdir, print if it's type dir
//-------------------------------------------------------
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

//traverse through dir's contents with readdir, print if it's type reg
//add file's size using stat(char *, struct stat *) 
//-------------------------------------------------------
void regs(DIR * curr) {
  printf("reg files in dir: \n");

  struct dirent * stats;
  struct stat sb;
  char type;
  char * name;
  int size;
  
  stats = readdir(curr);
  while (stats) {
    type = (*stats).d_type;
    if (type == DT_REG) {
      name = (*stats).d_name;
      printf("\t%s\n", name);
      stat(name, &sb);
      size += sb.st_size;
    }
    stats = readdir(curr);
  }
  printf("Size of regular files: %d B\n\n", size);
}


//open and close dirs with path
//-------------------------------------------------------
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
