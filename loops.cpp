#include <iostream>

int main(int argc, char* argv[])
{
  /* IF STATEMENTS */
  double x = -2.0;
  if (x < 0.0)
  {
    x = 0.0
  }

  /* IF-ELSE STATEMENTS */
  int i;
  //...
  double y;

  if (i > 0)
  {
    y = 2.0;
  }
  else
  {
    //When i <= 0
    y = 10.0;
  }

  /* MULTIPLE IF STATEMENTS */
  int i;
  //...
  double y;
  if (i > 100)
  {
    y = 2.0;
  }
  else if (i < 0)
  {
    y = 10.0;
  }
  else
  {
    //When 0 <= i <= 100
    y = 5.0;
  }

  /* NESTED IF STATEMENTS */
  double x, z, p, q;
  double y;
  if (x > z)
  {
    if (p > q)
    {
      //Both conditions have been met
      y = 10.0;
    }
  }

  /* BOOLEAN VARIABLES */
  bool flag = true;
  if (flag)
  {
    std::cout << "This will be printed\n";
  }
  else
  {
    //flag is false
    std::cout << "This won't be printed\n";
  }

  /* LOGICAL AND RELATIONAL OPERATORS

    AND             &&
    OR              ||
    NOT             !


    EQUAL TO        ==
    NOT EQUAL TO    !=
    GREATER THAN    >
    LESS THAN       <
    GR. THAN OR EQ  >=
    LE. THAN OR EQ  <=

  */

  double x, z, p, q;
  double y;
  if ((x > z) && (p > q))
  {
    //Both conditions have been met
    y = 10.0;
  }

  double p, q;
  int i;
  double y;
  if ((p > q) || (i != 1))
  {
    //One or both conditions have been met
    y = 10.0;
  }
  else
  {
    //Neither conditions has been met: p <= q and i == 1
    y = -10.0;
  }

  int i;
  bool flag = false;
  if (!flag)
  {
    // !flag is true when flag is false
    i += 2;
  }

  /* WHILE STATEMETNS */
  double x = 10.0;
  int count = 0;
  while (x > 1.0)
  {
    x *= 0.5;

    std::cout << "x = " << x << ", count = "
              << count << "\n";

    count++;

    std::cout << "x = " << x << ", count = "
              << count << "\n";

    std::cout << "Reached bottom of while loop\n";
  }

  std::cout << "count = " << count << "\n";

  /* FOR STATEMENTS */
  for (int i=0; i<10; i++)
  {
    std::cout << i << " ";
  }
  std::cout << "\n";

  /* NESTED FOR LOOPS */
  for (int i=0; i<5; i++)
  {
    for (int j=5; j>i; j--)
    {
      std::cout << "i = " << i
                <<     j = " << j << "\n";
    }
  }

  /* CALCULATING SCALAR PRODUCT WITH FOR LOOP */
  double vec1[2], vec2[2];
  vec1[0] = 0.5; vec1[1] = -2.3;
  vec2[0] = 34.2; vec2[1] = 0.015;

  double dot_prod = 0.0;

  for (int i=0; i<2; i++)
  {
    dot_prod += vec1[i] * vec2[i];
  }

  /* COMP USING SCI. NOTATION */
  double p, q;
  int k;
  if (fabs(p-q) < 1.0e-8)
  {
    k = 0;
  }
}
