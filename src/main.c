#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <limits.h>
#include <fcntl.h>
#include <string.h>

int main(){
  char *path = (char *)malloc(PATH_MAX);
  int length = 0;

  printf("\nFile opener and writer.\n\n");
  printf("Enter path: ");
  
  for(int i = 0; i < PATH_MAX - 1; i++){
    if (scanf("%c", &path[i]) != 1) break; 
        
    if (path[i] == '\n') {
      path[i] = '\0'; 
      break;
    }
    length++;
  }



  int child = fork();

  if(child < 0){
    abort();
  }else if(child == 0){
    int fd = open(path, O_RDWR | O_TRUNC | O_CREAT, 0644);

    if(fd == -1){
      abort();
    }
    
    


    char raw_of_file[80] = {0};
    printf("Enter raw of the file(79 symbols maximum): ");
    
    for(int i = 0;i < 80 - 1;i++){
      if (scanf("%c", &raw_of_file[i]) != 1) break;

      if(raw_of_file[i] == '\n'){
        raw_of_file[i] = '\0';
        break;
      }
    }

    write(fd, raw_of_file, strlen(raw_of_file));
    close(fd);

    char *args[3];

    args[0] = strdup("cat");
    args[1] = strdup(path);
    args[2] = NULL;

    execvp(args[0], args);

    printf("\n");

  }else{
    wait(NULL);

    free(path);
  }

  return 0;
  
}
