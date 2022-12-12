/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>


int count = 0;
int seconds = 0;
bool flag = false;

void handler(int signum){
  printf("Hello World!\n");
  flag = true;
}

void sigHandler(int signum){
  printf("\n %d no of alarms occured for %d seconds\n", count,seconds);
  exit(1);
}

int main(int argc, char * argv[]){
  signal(SIGALRM,handler);
  signal(SIGINT, sigHandler);
  alarm(1);
  while(1){
    if (flag){
      printf("Turing was right!\n");
      //Schedule a SIGALRM for 1 second
      flag = false
      alarm(1);
      count++;
      seconds++;
    }
  }
  
  return 0; //never reached
}