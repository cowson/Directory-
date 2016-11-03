#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>


void printFiles(){
  DIR *dp;
  struct dirent *ep;
  struct stat objStat;
  dp = opendir ("./");
  printf("Files in Current Directory:\n");
  while(ep = readdir(dp)){
    stat(ep->d_name, &objStat);
    if(S_ISREG(objStat.st_mode) != 0){
      printf("\t\t\t\t%s\n", ep->d_name);
    }
  }
  closedir(dp);
}

void printDirector(){
  DIR *dp;
  struct dirent *ep;
  struct stat objStat;
  dp = opendir ("./");
  printf("Directories in Current Directory:\n");
  while(ep = readdir(dp)){
    stat(ep->d_name, &objStat);
    if(S_ISDIR(objStat.st_mode) != 0){
      printf("\t\t\t\t%s\n", ep->d_name);
    }
  }
  closedir(dp);
  }

  int getSize(){
    DIR *dp;
    struct dirent *ep;
    struct stat objStat;
    dp = opendir ("./");
    int size = 0;
    while(ep = readdir(dp)){
      stat(ep->d_name, &objStat);
      if(S_ISREG(objStat.st_mode) != 0){
        size+= objStat.st_size;
      }
    }
    return size;
  }


int main(){
  printf("Statistics for directory:\n");
  printf("Total Diectory Size: %d bytes \n", getSize());
  printDirector();
  printFiles();
  return 0;
}
