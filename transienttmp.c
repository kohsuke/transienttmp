/* Start a shell in a new namespace */
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <sys/mount.h>

int main(int argc, char** argv) {
  // make sure we know what command to run
  if (argc<=1)
    fputs("localtmp COMMAND...\n",stderr);
  else
  // first, create a new namespace
  if (unshare(CLONE_NEWNS) < 0)
    perror("unshare");
  else
  // in this new namespace, mount new /tmp
  if(mount("none","/tmp","tmpfs",0,NULL)<0)
    perror("mount");
  // disable the privilege
  else
  if(setuid(getuid())<0)
    perror("setuid failed");
  else
  if(setgid(getgid())<0)
    perror("setgid failed");
  else
  // then run as the calling user
  if (execvp(argv[1],argv+1)<0)
      perror("cannot exec");
  return -1;
}

