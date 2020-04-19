#include "5_10.h"
#include <iostream>
#include <fstream>
#include <assert.h>
#include <algorithm>


/*
void guassian_elimination(double **A, double *b, double *u, int n);

int main()
{
    int n;
    n=3;

    int rows = n, cols = n;
    
    double **A, *u, *b;
    A = new double * [rows];
    for (int i=0; i<rows; i++)
    {
        A[i] = new double [cols];
    }


    
    b = new double [n];
    
    u = new double [n];


    A[0][0]=5.0;
    A[1][0]=1.0;
    A[2][0]=10.0;
    A[0][1]=2.0;
    A[1][1]=0.0;
    A[2][1]=3.0;
    A[0][2]=4.0;
    A[1][2]=9.0;
    A[2][2]=2.0;
    
    b[0]=5.0;
    b[1]=11.0;
    b[2]=19.0;

    std::cout << "-----------------------------------------------"<< std::endl;
    std::cout << "initial matrix"<< std::endl;
    std::cout << A[0][0] << " " << A[0][1]<< " " << A[0][2] << " " << b[0] << std::endl;
    std::cout << A[1][0] << " " << A[1][1]<< " " << A[1][2] << " " << b[1] << std::endl;
    std::cout << A[2][0] << " " << A[2][1]<< " " << A[2][2] << " " << b[2] << std::endl;
    std::cout << "-----------------------------------------------"<< std::endl;

    guassian_elimination(A, b,u, n);
    
    std::cout << "-----------------------------------------------"<< std::endl;
    std::cout << "Output matrix"<< std::endl;
    std::cout << A[0][0] << " " << A[0][1]<< " " << A[0][2] << " " << b[0] << std::endl;
    std::cout << A[1][0] << " " << A[1][1]<< " " << A[1][2] << " " << b[1] << std::endl;
    std::cout << A[2][0] << " " << A[2][1]<< " " << A[2][2] << " " << b[2] << std::endl;

    //cout << A[0][0] << " " << A[0][1]<< " " << A[0][2] << " " << A[0][3] << " " << b[0] << endl;
    //cout << A[1][0] << " " << A[1][1]<< " " << A[1][2] << " " << A[1][3] << " " << b[1] << endl;
    //cout << A[2][0] << " " << A[2][1]<< " " << A[2][2] << " " << A[2][3] << " " << b[2] << endl;
    //cout << A[3][0] << " " << A[3][1]<< " " << A[3][2] << " " << A[3][3] << " " << b[2] << endl;
    std::cout << "-----------------------------------------------"<< std::endl;

    std::cout << "(" << b[0] << " " << b[1] << " " << b[2] << " )" << std::endl;

    return 0;
}
*/

void guassian_elimination(double **A, double *b, double *u, int n)
{
    int maxindex;
    bool Bswap;
    double factor, maxvalue;

    for(int diag=0; diag<n; diag++)
    {
        maxindex = diag;
        maxvalue = A[diag][diag];
        Bswap = false;
        for(int row=diag+1; row<n; row ++) // Looking through any row for larger value for current diagonal index
        {
            if(A[row][diag] < 0)
            {
                if(maxvalue < -A[row][diag])
                {
                    maxvalue = -A[row][diag];
                    maxindex = row;
                    Bswap = true;
                }
            }
            if(A[row][diag] > 0)
            {
                if(maxvalue < A[row][diag])
                {
                    maxvalue = A[row][diag];
                    maxindex = row;
                    Bswap = true;
                }
            }
        }

        if(Bswap) // swapping row to the larger value
        {
            std::cout << "-----------------------------------------------"<< std::endl;
            std::cout << "True " << diag << " " << maxindex << std::endl;
            std::cout << "-----------------------------------------------"<< std::endl;
            // Kode
            for(int col=0; col<n; col ++)
            {
                std::swap(A[diag][col],A[maxindex][col]);
            }
            std::swap(b[diag],b[maxindex]);
        }

        for(int row=0; row<n; row++) // reducing row;
        {
            if(row!=diag)
            {
                factor = A[row][diag]/A[diag][diag];

                for(int col=0; col<n; col++)
                {
                    A[row][col]-= factor * A[diag][col]; 
                }

                b[row]-= factor * b[diag];
            }
        }
        factor = A[diag][diag];
        for(int col=0; col<n; col++)
        {
            A[diag][col]/=factor;
        }
        b[diag]/=factor;
    }

    for(int row=0; row<n; row++)
    {
        u[row]=b[row];
    }
}