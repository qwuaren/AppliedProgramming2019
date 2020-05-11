#ifndef MATRIXHEADERDEF
#define MATRIXHEADERDEF
#include "Vector.hpp"

template <typename T>
class Matrix
{
private:
	std::vector<T> mData;// T** mData; // entries of matrix
	int mNumRows, mNumCols; // dimensions

public:
	//constructor
	Matrix(int numRows, int numCols)
	{
		assert(numRows > 0);
		assert(numCols > 0);

		mNumRows = numRows;
		mNumCols = numCols;

		mData.assign(mNumRows*mNumCols,0);
	}

	//copy constructor
	Matrix(const Matrix& otherMatrix)
	{
		mNumRows = otherMatrix.mNumRows;
		mNumCols = otherMatrix.mNumCols;
		mData = otherMatrix.mData;
	}

	T& operator()(int i, int j)
    {
        assert(i >= 0);
        assert(i < mNumRows);
        assert(j >= 0);
        assert(j < mNumCols);

        return mData[mNumCols*i+j];
    }

	T const& operator()(int i, int j) const
    {
        assert(i >= 0);
        assert(i < mNumRows);
        assert(j >= 0);
        assert(j < mNumCols);

        return mData[mNumCols*i+j];
    }

	int GetNumberOfRows() const
    {
        return mNumRows;
    }

	int GetNumberOfColumns() const
    {
        return mNumCols;
    }


	//overloaded assignment operator
	Matrix& operator=(const Matrix& otherMatrix)
    {
        assert(mNumRows == otherMatrix.mNumRows);
        assert(mNumCols == otherMatrix.mNumCols);

        for (int i = 0; i < mNumRows; i++)
        {
            for (int j = 0; j < mNumCols; j++)
            {
                mData[mNumCols*i+j] = otherMatrix.mData[otherMatrix.mNumCols*i+j];
            }
        }
        return *this;
    }

	//overload unary -
	Matrix operator-() const
    {
        Matrix<T> mat(mNumRows, mNumCols);
        for (int i = 0; i < mNumRows; i++)
        {
            for (int j = 0; j < mNumCols; j++)
            {
                mat(i,j) = -mData[mNumCols*i+j];
            }
        }
        return mat;
    }

	//overload binary +
	Matrix operator+(const Matrix& m1) const
    {
        assert(mNumRows == m1.mNumRows);
        assert(mNumCols == m1.mNumCols);

        Matrix<T> mat(mNumRows, mNumCols);
        for (int i = 0; i < mNumRows; i++)
        {
            for (int j = 0; j < mNumCols; j++)
            {
                mat(i,j) = mData[mNumCols*i+j] + m1.mData[mNumCols*i+j];
            }
        }
        return mat;
    }

	//overload binary -
	Matrix operator-(const Matrix& m1) const
    {
        assert(mNumRows == m1.mNumRows);
        assert(mNumCols == m1.mNumCols);

        Matrix<T> mat(mNumRows, mNumCols);
        for (int i = 0; i < mNumRows; i++)
        {
            for (int j = 0; j < mNumCols; j++)
            {
                mat(i,j) = mData[mNumCols*i+j] - m1.mData[mNumCols*i+j];
            }
        }
        return mat;
    }
//
	// scalar multiplication
	Matrix operator*(double a) const
    {
        Matrix<T> mat(mNumRows, mNumCols);
        for (int i = 0; i < mNumRows; i++)
        {
            for (int j = 0; j < mNumCols; j++)
            {
                mat(i,j) = a*mData[mNumCols*i+j];
            }
        }
        return mat;
    }

	//Mandatory function
	std::vector<T> const& getStorage() const
	{
		return mData;
	}
}; // class Matrix


//matrix-vector multiplications
template <class T>
Vector<T> operator*(Matrix<T> const& m, Vector<T> const& v)
{
    int original_vector_size = v.size();
	assert(m.GetNumberOfColumns() == original_vector_size);

	int new_vector_length = m.GetNumberOfRows();
	Vector<T> new_vector(new_vector_length);

	for (int i = 0; i < new_vector_length; i++)
	{
		for (int j = 0; j < original_vector_size; j++)
		{
			new_vector[i] += m(i,j)*v[j];
		}
	}

	return new_vector;
}

template <class T>
Vector<T> operator*(Vector<T> const& v, Matrix<T> const& m)
{
	int original_vector_size = v.size();
	assert(m.GetNumberOfRows() == original_vector_size);

	int new_vector_length = m.GetNumberOfColumns();
	Vector<T> new_vector(new_vector_length);

	for (int i = 0; i < new_vector_length; i++)
	{
		for (int j = 0; j < original_vector_size; j++)
		{
			new_vector[i] += v[j]*m(j,i);
		}
	}

	return new_vector;
}


#endif
