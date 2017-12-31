// The access system call determines whether the calling process has access permission to a file. 
// It can check any combination of read, write, and execute permission, and it can also check for a file's existence.




#include <errno.h>
#include <stdio.h>
#include <unistd.h>

int main ()
{
 char path [20];
 gets(path);
 int rval;

 /* Check file existence. */
 rval = access (path, F_OK);
 if (rval == 0) 
  printf ("%s exists\n", path);
 else {
  if (errno == ENOENT) 
   printf ("%s does not exist\n", path);
  else if (errno == EACCES) 
   printf ("%s is not accessible\n", path);
  return 0;
 }

 /* Check read access. */
 rval = access (path, R_OK);
 if (rval == 0)
  printf ("%s is readable\n", path);
 else
  printf ("%s is not readable (access denied)\n", path);

 /* Check write access. */
 rval = access (path, W_OK);
 if (rval == 0)
  printf ("%s is writable\n", path);
 else if (errno == EACCES)
  printf ("%s is not writable (access denied)\n", path);
 else if (errno == EROFS)
  printf ("%s is not writable (read-only filesystem)\n", path);
 return 0;
} 