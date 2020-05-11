#ifndef H_5_10_H
#define H_5_10_H

void solve3by3(double **A, double *b, double *u);
double CalcDeterminant(double **matrix, int size);
void Multiply(double *res,
              double **A,
              double *B,
              int ARows,
              int ACols,
              int BCols);

#endif
