#include <iostream>

#define LOG(x) std::cout << x << std::endl

int main()
{
  int i = 5; //integer variable i
  int* p_j = &i; //pointer to i
  *p_j *= 5; //dereference pointer to access value, multiply by 5

  int* p_k = new int; //declare new pointer and allocate memory location

  *p_k = *p_j; //store value at p_j (i.e. i) at p_k

  *p_j = 0; //set value at p_j (i.e. i) to zero

  //check that it worked
  LOG(i);
  LOG(*p_k);

  //every new requires a delete
  delete p_k;

  return 0;
}
