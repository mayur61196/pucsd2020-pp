#include "include/calculator.h"
#include "include/arithmetic.h"
#include<stdio.h>
#include<string.h>
#define SIZE 50
#include <ctype.h>

void
main ()
{
  char infx[SIZE];
  printf ("\nInput: ");
  scanf ("%[^\n]%*c", infx);
  int check = validateinfix (infx);
  if (check == -1)
    printf ("\n%s\n", infx);
  else if (check == 1)
    printf ("\n-> %f\n", eval_infix (infx));
  else
    printf ("\nInvalid expression\n");
}
