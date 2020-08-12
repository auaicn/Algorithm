#include <stdio.h>

int main ()
{
  char str [80];
  int i;

  printf ("Enter your family name: ");
  printf("%d",scanf ("%79s",str)  );
  printf ("Enter your age: ");
  printf("%d",scanf ("%d",&i));
  printf ("Mr. %s , %d years old.\n",str,i);
  printf ("Enter a hexadecimal number: ");
  printf("%d",scanf ("%x",&i));
  printf ("You have entered %#x (%d).\n",i,i);
  
  return 0;
}