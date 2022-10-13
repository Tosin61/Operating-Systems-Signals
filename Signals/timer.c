/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>


int c = 0;
int secs = 0;
bool t = true;

void handler(int signum){
  printf("Hello World!\n");
  printf("Turing was right!\n");
  alarm(1);
}

void sigHandler(int signum){
  signal(SIGINT, sigHandler);
  printf("\n %d no of alarms occured for %d seconds\n", c,secs);
  t = false;
}

int main(int argc, char * argv[]){
  while(t){
    signal(SIGALRM,handler); //register handler to handle SIGALRM
    alarm(1); //Schedule a SIGALRM for 1 second
    sleep(1);
    signal(SIGINT, sigHandler);
    c++;
    secs++;
  }
  
  return 0; //never reached
}