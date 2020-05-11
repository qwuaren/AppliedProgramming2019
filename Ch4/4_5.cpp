#include <memory> //requires c++11 or above, compile by writing "g++ -std=c++11 -o file file.cpp"
#include <iostream>

#define LOG(x) std::cout << "p_x use count: " << x.use_count() << std::endl

int main()
{
  std::shared_ptr<int> p_x(new int);

  *p_x = 5;

  std::weak_ptr<int> p_w;
  *p_w = *p_x;

  // std::cout << *p_w << "\n";

  // p_w = p_x;

  LOG(p_x);

  std::shared_ptr<int> p_y = p_x;

  LOG(p_x);

  p_y.reset();

  LOG(p_x);

  p_x.reset();

  LOG(p_w);

  return 0;
}
