#include "../../include/calculator.h"
#include "../../include/arithmetic.h"
#include<ctype.h>
#include<string.h>
int MAXSIZE = 100;
float
eval_infix (char *infix)
{
  int i;
  float operands[MAXSIZE];
  int operandtop = -1;
  char operators[MAXSIZE];
  int operatortop = -1;

  for (i = 0; i < strlen (infix); i++)
    {
      if (infix[i] == ' ')
	continue;
      else if (infix[i] == '(')
	{
	  operators[++operatortop] = infix[i];
	}

      else if (isdigit (infix[i]))
	{
	  float val = 0;
	  while (i < strlen (infix) && isdigit (infix[i]))
	    {
	      val = (val * 10) + (infix[i] - '0');
	      i++;
	    }
	  if (infix[i] == '.')
	    i++;
	  float fval = 0;
	  float denom = 10;
	  while (i < strlen (infix) && isdigit (infix[i]))
	    {
	      fval += (infix[i] - '0') / denom;
	      denom *= 10;
	      i++;
	    }
	  i--;
	  val += fval;
	  operands[++operandtop] = val;
	}
      else if (infix[i] == ')')
	{
	  while (!(operatortop == -1) && operators[operatortop] != '(')
	    {
	      float secondOperand = operands[operandtop];
	      operandtop--;
	      float firstOperand = operands[operandtop];
	      char operator = operators[operatortop];
	      operatortop--;
	      switch (operator)
		{
		case '+':
		  operands[operandtop] =
		    addition (firstOperand, secondOperand);
		  break;
		case '-':
		  operands[operandtop] =
		    subtraction (firstOperand, secondOperand);
		  break;
		case '*':
		  operands[operandtop] =
		    multiplication (firstOperand, secondOperand);
		  break;
		case '/':
		  operands[operandtop] =
		    division (firstOperand, secondOperand);
		  break;
		}
	    }
	  if (!(operatortop == -1))
	    operatortop--;
	}
      else
	{
	  while (!(operatortop == -1) &&
		 precedence (operators[operatortop]) >= precedence (infix[i]))
	    {
	      float secondOperand = operands[operandtop];
	      operandtop--;
	      float firstOperand = operands[operandtop];
	      char operator = operators[operatortop];
	      operatortop--;
	      switch (operator)
		{
		case '+':
		  operands[operandtop] =
		    addition (firstOperand, secondOperand);
		  break;
		case '-':
		  operands[operandtop] =
		    subtraction (firstOperand, secondOperand);
		  break;
		case '*':
		  operands[operandtop] =
		    multiplication (firstOperand, secondOperand);
		  break;
		case '/':
		  operands[operandtop] =
		    division (firstOperand, secondOperand);
		  break;
		}
	    }
	  operators[++operatortop] = infix[i];
	}
    }
  while (!(operatortop == -1))
    {
      float secondOperand = operands[operandtop];
      operandtop--;
      float firstOperand = operands[operandtop];
      char operator = operators[operatortop];
      operatortop--;
      switch (operator)
	{
	case '+':
	  operands[operandtop] = addition (firstOperand, secondOperand);
	  break;
	case '-':
	  operands[operandtop] = subtraction (firstOperand, secondOperand);
	  break;
	case '*':
	  operands[operandtop] = multiplication (firstOperand, secondOperand);
	  break;
	case '/':
	  operands[operandtop] = division (firstOperand, secondOperand);
	  break;
	}
    }
  return operands[operandtop];
}
