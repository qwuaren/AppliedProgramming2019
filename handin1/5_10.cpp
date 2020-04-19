#include "5_10.h"
#include <cmath>
#include <algorithm>

void guassian_elimination(double **A, double *b, double *u, int n)
{
  int idx_max;
  bool swap;
  double multiplier, max_value;

  for(int i=0; i<n; i++) //Go across diagonal row wise
  {
      idx_max = i;
      max_value = A[i][i];
      swap = false;

      for(int j=i+1; j<n; j ++)  //compare with other rows
      {
          if(A[j][i] < 0)
          {
              if(max_value < -A[j][i])
              {
                  max_value = -A[j][i];
                  idx_max = j;
                  swap = true;
              }
          }
          if(A[j][i] > 0)
          {
              if(max_value < A[j][i])
              {
                  max_value = A[j][i];
                  idx_max = j;
                  swap = true;
              }
          }
      }

      if(swap) //swap rows elementwise in both matrix and vector
      {
          for(int k=0; k<n; k ++) //Go over cols
          {
              std::swap(A[i][k],A[idx_max][k]);
          }
          std::swap(b[i],b[idx_max]);
      }

      for(int k=0; k<n; k++) //reduce matrix and vector
      {
          if(k!=i)
          {
              multiplier = A[k][i]/A[i][i];

              for(int l=0; l<n; l++)
              {
                  A[k][l]-= multiplier * A[i][l];
              }

              b[k]-= multiplier * b[i];
          }
      }

      multiplier = A[i][i];

      for(int k=0; k<n; k++)
      {
          A[i][k]/=multiplier;
      }

      b[i]/=multiplier;
  }

  //save result
  for(int j=0; j<n; j++)
  {
      u[j]=b[j];
  }
}
