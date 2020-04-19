#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{
  double mat1[2][2] = {{1.0, 2.0}, {3.0, 4.0}};
  double mat2[2][2] = {{5.0, 6.0}, {7.0, 8.0}};

  double mat3[2][2], mat4[2][2];

  mat3[0][0] = mat1[0][0] + mat2[0][0];
  mat3[0][1] = mat1[0][1] + mat2[0][1];
  mat3[1][0] = mat1[1][0] + mat2[1][0];
  mat3[1][1] = mat1[1][1] + mat2[1][1];

  std::cout << "Matrix C is thus {" << mat3[0][0] << ", " << mat3[0][1] << ", " << mat3[1][0] << ", " << mat3[1][1] << "\n";

  mat4[0][0] = mat1[0][0] * mat2[0][0];
  mat4[0][1] = mat1[0][1] * mat2[0][1];
  mat4[1][0] = mat1[1][0] * mat2[1][0];
  mat4[1][1] = mat1[1][1] * mat2[1][1];

  std::cout << "\n\nMatrix D is thus {" << mat4[0][0] << ", " << mat4[0][1] << ", " << mat4[1][0] << ", " << mat4[1][1] << "\n";

  return 0;
}
