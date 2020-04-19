#include "5_3.h"

/* WORKS WITH CODE CHECKER */

void swap_pointer(double *a, double *b)
{
  //Take two pointers and swap contents
  //outside function scope
  double swap_ptr;

  swap_ptr = *a;

  *a = *b;

  *b = swap_ptr;

}

void swap_ref(double &a, double &b)
{
  //Take two references and swap contents
  //outside function scope
  double temp;

  temp = a;

  a = b;

  b = temp;

}
