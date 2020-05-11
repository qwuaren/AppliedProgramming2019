#include <iostream>
// #include "Vector.hpp"
// #include "Matrix.hpp"
#include "SparseVector.hpp"

#define LOG(x) std::cout << x << std::endl;

int main()
{
  SparseVector<double> sVec(4);

  sVec.setValue(0,3.0);
  sVec.setValue(2,7.0);
  sVec.setValue(3,5.0);
  sVec.Print();

  SparseVector<double> Vec2;
  Vec2.setValue(0,1.0);
  Vec2.setValue(1,2.0);
  Vec2.setValue(3,1.0);
  Vec2.Print();
  LOG("");

  sVec -= Vec2;
  sVec.Print();

  sVec += Vec2;
  sVec.Print();
  // 
  // sVec += Vec2;
  // sVec.Print();

  SparseVector<double> Vec3 = sVec+Vec2;
  Vec3.Print();
  // std::cout << std::endl;

  // sVec.DoSomething();

  // Vector<int> MyVec(2);
  //
  // MyVec[0] = 1; MyVec[1] = 2;
  // LOG(MyVec[0]); LOG(MyVec[1]);
  //
  // Vector<int> v = MyVec;
  //
  // LOG(v[0]); LOG(v[1]);
  //
  // LOG(v.CalculateNorm()); LOG("");
  // int num = 5;
  //
  // Vector<int> a(num);
  // Vector<int> b(num);
  //
  // int temp = 5;
  //
  // for (int i=0; i<num; i++)
  // {
  //   a[i] = i+1;
  //   b[i] = temp;
  //
  //   temp--;
  // }
  //
  // LOG("Vector a:")
  // for (int i=0; i<num; i++)
  // {
  //   LOG(a[i]);
  // }
  //
  // LOG("\nVector b:")
  // for (int i=0; i<num; i++)
  // {
  //   LOG(b[i]);
  // }
  //
  // Vector<int> c = b-a;
  //
  // LOG("\nVector c=b-a:")
  // for (int i=0; i<num; i++)
  // {
  //   LOG(c[i]);
  // }
  //
  // Vector<int> d = b+a;
  //
  // LOG("\nVector d=b+a:")
  // for (int i=0; i<num; i++)
  // {
  //   LOG(d[i]);
  // }
  //
  // Vector<int> e = b*2;
  //
  // LOG("\nVector e=b*2:")
  // for (int i=0; i<num; i++)
  // {
  //   LOG(e[i]);
  // }
  //
  // LOG("\nNorm of vector a, b, c, d, e:")
  // LOG(a.CalculateNorm());
  // LOG(b.CalculateNorm());
  // LOG(c.CalculateNorm());
  // LOG(d.CalculateNorm());
  // LOG(e.CalculateNorm());
  //
  //
  //
  //
  //
  // std::cout << std::endl;
  //

  // MATRIX TESTS
  // Matrix<int> mat(2,2);
  //
  // mat(0,0) = 1; mat(1,0) = 2;
  // mat(0,1) = 3; mat(1,1) = 4;
  //
  // LOG(mat(0,0));
  // LOG(mat(1,0));
  // LOG(mat(0,1));
  // LOG(mat(1,1));
  //
  // std::cout << std::endl;
  //
  // Vector<int> vecter(2);
  //
  // vecter[0] = 7;
  // vecter[1] = 3;
  //
  // // Vector<int> vecto = mat * vecter;
  // Vector<int> vecto = vecter * mat;
  //
  // LOG(vecto[0]); LOG(vecto[1]); std::cout << std::endl;
  //
  // Matrix<int> matto = mat * 2;
  //
  // LOG(matto(0,0));
  // LOG(matto(1,0));
  // LOG(matto(0,1));
  // LOG(matto(1,1));
  // LOG("");
  //
  // Matrix<int> mattre = mat - matto;
  //
  // LOG(mattre(0,0));
  // LOG(mattre(1,0));
  // LOG(mattre(0,1));
  // LOG(mattre(1,1));
  return 0;
}
