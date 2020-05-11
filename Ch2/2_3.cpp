#include <iostream>

int main(int argc, char* argv[])
///* FIRST PART */
// {
//   int num, sum = 0;
//
//   while (num != -1)
//   {
//     std::cin >> num;
//     sum += abs(num);
//   }
//
//   std::cout << "The sum of numbers is = " << sum << "\n";
//
//   return 0;
// }

// /* SECOND PART */
// {
//   int num, sum = 0;
//
//   while (sum<100)
//   {
//     std::cin >> num;
//     sum += abs(num);
//   }
//
//   std::cout << "The sum of numbers is = " << sum << "\n";
//
//   return 0;
// }

/* THIRD PART */
{
  int num, sum;

  while (sum<100)
  {
    std::cin >> num;

    if (num==-2)
    {
      std::cout << "You've reset the sum to 0\n";
      sum = 0;
    }
    else
    {
      //if num is not -2
      sum += abs(num);
    }

    std::cout << "The sum of numbers is = " << sum << "\n";
  }

  return 0;
}
