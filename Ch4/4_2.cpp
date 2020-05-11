#include <iostream>

#define LOG(x) std::cout << x << std::endl

int main()
{
  //create two integers
  int var1 = 5, var2 = 8;
  LOG(var1);
  LOG(var2);

  //create pointers to integers above
  int* pt1 = &var1;
  int* pt2 = &var2;

  //to swap, I use a temporary pointer and allocate memory for it
  int* temp_ptr = new int;

  //store first int in temporary pointer
  *temp_ptr = *pt1;

  //switch first int to second int value
  *pt1 = *pt2;

  //get first int value from temp pointer
  *pt2 = *temp_ptr;

  //every new requires a delete
  delete temp_ptr;

  LOG(var1);
  LOG(var2);

  return 0;
}
