#include <iostream>

int main(int argc, char* argv[])
{
  double u[3] = {1.0, 2.0, 3.0};
  double v[3] = {6.0, 5.0, 4.0};
  double A[3][3] = {{1.0, 5.0, 0.0},
                    {7.0, 1.0, 2.0},
                    {0.0, 0.0, 1.0}};

  double B[3][3] = {{-2.0, 0.0, 1.0},
                    {1.0, 0.0, 0.0},
                    {4.0, 1.0, 0.0}};

  double w[3];

  for (int i=0; i<3; i++)
  {
    w[i] = u[i] - 3.0 * v[i];
  }

  /* Calculate x=u-v */
  double x[3];

  std::cout << "\n\n";

  for (int i=0; i<3; i++)
  {
    x[i] = u[i] - v[i];
    std::cout << "Det " << i << "'te element i x er = " << x[i] << "\n";
  }

  std::cout << "\n\n";

  /* Calculate y=Au */
  double y[3];

  for (int i=0; i<3; i++)
  {
    for (int j=0; j<3; j++)
    {
      y[i] += A[i][j]*u[j];
      // std::cout << "y[" << i << "] er nu = " << y[i] << "\n";
      // std::cout << A[i][j] << "  " << u[j] << "\n";
    }

    std::cout << "Det " << i << "'te element i y er = " << y[i] << "\n";
  }

  /* Calculate z=Au-v */

  double z[3];

  std::cout << "\n\n";

  for (int i=0; i<3; i++)
  {
    z[i] = y[i] - v[i];

    std::cout << "Det " << i << "'te element i z er = " << z[i] << "\n";
  }

  /* Calculate C=4A-3B */
  double C[3][3];

  std::cout << "\n\n";

  for (int i=0; i<3; i++)
  {
    for (int j=0; j<3; j++)
    {
      C[i][j]=4*A[i][j]-3*B[i][j];

      std::cout << "Det [" << i << "][" << j <<"] element i C er = " << C[i][j] << "\n";
    }
  }

  /* Calculate D=AB */
  double D[3][3];

  std::cout << "\n\n";

  for (int i=0; i<3; i++)
  {
    for (int j=0; j<3; j++)
    {
      for (int k=0; k<3; k++)
      {
        D[i][j] += A[j][k] * B[k][i];
      }

      std::cout << "Det [" << i << "][" << j << "] element i D er = " << D[i][j] << "\n";
    }
  }

  return 0;
}
