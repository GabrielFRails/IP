/* strchr example */
#include <stdio.h>
#include <string.h>

int main (){

  char str[] = "fsociety rules over here";
  char *pch;
  printf ("Looking for the 's' character in \"%s\"...\n",str);
  pch=strchr(str,'s');
  while (pch!=NULL){
    printf ("found at %d\n", (int)pch-str+1);
    pch=strchr(pch+1,'s');
  }
  return 0;
}