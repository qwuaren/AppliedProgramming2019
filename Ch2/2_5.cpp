#include <iostream>
#include <cassert>

int main(int argc, char* argv[])
{
  double A[2][2]={{4.0, 10.0},
                  {1.0, 1.0}};

  double determinant=A[0][0]*A[1][1]-A[0][1]*A[1][0];

  assert(determinant != 0);

  double AInv[2][2] = {{A[1][1]*(1/determinant), -A[0][1]*(1/determinant)}, {-A[1][0]*(1/determinant), A[0][0]*(1/determinant)}};

  for (int i=0; i<2; i++)
  {
    for (int j=0; j<2; j++)
    {
      std::cout << "Det [" << i << "][" << j << "] element i den inverse er = " << AInv[i][j] << "\n";
    }
  }

  return 0;
}
