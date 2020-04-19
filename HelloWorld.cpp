#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
  /* This is a comment and will be ignored by
  the compiler. Comments are useful to explain
  what the program does. */

  // Print "Hello World" to the screen
  std::cout << "\n\n \a \a \a Hey flotte fyr <3 <3 <3 <3 \n\n";

  /*Formatting commands for console output
  new line    \n
  tab         \t
  '           \'
  "           \"
  ?           \?
  bell sound  \a

  To print something immediately (before buffering
  is complete), write std::cout.flush() after std::cout.

  */

  // Keyboard input with numbers
  int pin;
  std::cout << "Enter a PIN, then hit RETURN\n";
  std::cin >> pin;
  std::cout << "Your PIN is " << pin << "\n";

  int birthdate, pin_num;
  std::cout << "Enter your birthdate\n";
  std::cout << "and then enter a PIN followed by RETURN\n";
  std::cin >> birthdate >> pin_num;
  std::cout << "Your birthdate is: " << birthdate
  << " and your chosen PIN is: " << pin_num << "\n";

  //Keyboard input with strings is slightly different
  std::string name;
  std::cout << "Enter your name and then hit RETURN\n";
  std::getline(std::cin, name);
  std::cout << "Your name is " << name << "\n";

  return 0;
}
