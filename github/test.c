#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"

int main() {
 
  printf(1, "\n\nbeginning of program test.c\n\n");

  int status = 0;
  int pid = 0;

  printf(1, "about to fork\n");
  pid = fork();
  printf(1, "fork happened\n");

  if (pid != 0) {
    printf(1,"I am the parent\n");
    printf(1, "my (parent) pid is = %d\n", getpid());
    printf(1, "I am the parent of pid = %d\n", pid);
    wait(&status);
    printf(1, "...exiting parent\n");
  }
  else {
    printf(1, "I am the child\n");
    printf(1, "my (child) pid is = %d\n", getpid());
    printf(1, "pid = %d\n", pid);
    printf(1, "...exiting child\n");
    exit(0);
  }
 
  return 0;
  exit(0);
}
