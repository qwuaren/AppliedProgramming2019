#include <iostream>

#define LOG(x) std::cout << x << std::endl

//Both functions should swap the values of
//two numbers, so that the changes is visible
//in the code that has called this function:
void swap_pointer(double *a, double *b);
void swap_ref(double &a, double &b);

int main()
{
  double* p_i;
  double* p_j;

  double i = 2.00, j = 4.00;

  p_i = &i;
  p_j = &j;

  //check result - should print 2.00, 4.00
  LOG(i);
  LOG(j);

  swap_pointer(p_i, p_j);

  //check result - should print 4.00, 2.00
  LOG(i);
  LOG(j);

  swap_ref(i, j);

  //check result - should print 2.00, 4.00
  LOG(i);
  LOG(j);

  return 0;
  
}

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
