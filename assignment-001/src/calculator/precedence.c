#include "../../include/calculator.h"
int
precedence (char elem)
{
  switch (elem)
    {
    case '#':
      return 0;
    case '(':
      return 1;
    case '+':
    case '-':
      return 2;
    case '*':
    case '/':
      return 3;
    }
}
