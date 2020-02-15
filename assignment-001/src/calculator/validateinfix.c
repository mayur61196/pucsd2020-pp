#include "../../include/calculator.h"
#include<string.h>
#include<ctype.h>

int
validateinfix (char infix[])
{
  int i;
  int parancount = 0;
  int expflag = 1;
  for (i = 0; i < strlen (infix); i++)
    {
      if (infix[i] == ' ')
	continue;
      if (isdigit (infix[i]))
	{
          int deccount=0;
	  while (isdigit (infix[i]) && i < strlen (infix) || infix[i] == '.')
	    {
	      if (infix[i] == '.')
		{
		  if (infix[i - 1] == '.')
		    return 0;
		  else
		    deccount += 1;
		}
	      i++;
	    }
	  i--;
	  if (deccount > 1)
	    return 0;
	  if (expflag == 1)
	    expflag = 0;
	  else
	    return -1;
	}
      else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*'
	       || infix[i] == '/')
	{
	  if (expflag == 0)
	    expflag = 1;
	  else
	    return 0;
	}
      else if (infix[i] == '(')
	parancount++;
      else if (infix[i] == ')')
	{
	  parancount--;
	  if (parancount < 0)
	    return 0;
	}
      else
	return 0;

    }
  if (expflag == 1 || parancount != 0)
    {
      return 0;
    }
  return 1;

}
