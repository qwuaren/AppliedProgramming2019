#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{
  int day1, day2, day3, day4, day5;
  std::cout << "Provide number of cars per day for five days. Follow each number by hitting RETURN\n";
  std::cin >> day1 >> day2 >> day3 >> day4 >> day5;

  int car_arr[5] = {day1, day2, day3, day4, day5};

  double average_cars;

  average_cars = (((double)(day1)) + ((double)(day2)) + ((double)(day3)) + ((double)(day4)) + ((double)(day5))) / 5;

  std::cout << "The average number of cars is then " << average_cars << "\n";

  return 0;
}
