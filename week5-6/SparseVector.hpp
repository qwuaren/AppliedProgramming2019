#ifndef SPARSE_VECTOR_HPP
#define SPARSE_VECTOR_HPP

#include "Vector.hpp"
#include "Matrix.hpp"

// #include <iostream>

template<class T> class SparseVector{
private:
	//Add your data members here!
	int mDim; //dimensionality
	std::vector<int> mIndices;
	std::vector<T> mValues;

public:
	//creates an empty vector of dimensionality 0.
	SparseVector()
	{
		mDim = 0;
	}

	// Creates a vector of dimensionality dim. It starts with 0 nonzero elements
	// which need to be set using setValue
	SparseVector(unsigned int dim)
	{
		mDim = dim;
	}

	//attempted copy constructor
	// SparseVector(const SparseVector& otherVector)
	// {
	// 	mDim = otherVector.mDim;
	// 	mIndices = otherVector.mIndices;
	// 	mValues = otherVector.mValues;
	// }

	// assignment operators and copy constructor should be automatically
	// generated by the compiler when using a std::vector for internal storing.
	// However, test that assignment works! - it does on my computer, but not in codechecker.

	//sets the value v_i of the vector. if it does not exist it is added
	void setValue(unsigned int index, T value)
	{
		// assert(index < mDim);

		auto idx = std::lower_bound(mIndices.begin(), mIndices.end(), index);
		if (idx == mIndices.end())
		{
			//iterator reaches end of mIndices without finding index
			mIndices.push_back(index);
			mValues.push_back(value);
			// mDim++;
		}
		else if (*idx == index)
		{
			//index already exists in mIndices
			int dist = std::distance(mIndices.begin(),idx);
			// mValues[*(mValues.begin()+dist)] = value;
			mValues[dist] = value;
		}
		else
		{
			//index fits in somewhere
			int dist = std::distance(mIndices.begin(),idx);
			mIndices.insert(idx,index);
			mValues.insert((mValues.begin()+dist),value);
			// mDim++;
		}
	}

	//returns the value v_i of the vector. Returns 0 if the value is not stored
	T getValue(unsigned int index) const
	{
		// assert(index < mDim);

		auto idx = std::lower_bound(mIndices.begin(), mIndices.end(), index);
		if (*idx == index)
		{
			//iterator finds index in mIndices
			int dist = std::distance(mIndices.begin(),idx);
			return mValues[dist];
		}
		else
		{
			return 0;
		}
	}

	//returns the dimensionality of the vector
	unsigned int size() const
	{
		return mDim;
	}

	// returns the number stored elements
	unsigned int nonZeroes() const
	{
		return mIndices.size();
	}
	//returns the index of the ith stored nonzero entry (in increasing order)
	unsigned int indexNonZero(unsigned int i) const
	{
		return mIndices[i];
	}

	//returns the value of the ith stored nonzero entry (in increasing order)
	T valueNonZero(unsigned int i) const
	{
		assert(i<mValues.size());

		return mValues[i];
	}

	//adds x too the current vector
	SparseVector<T>& operator+= (SparseVector<T> const& x)
	{
		// for all in x
		for(int i = 0; i < x.mIndices.size(); i++)
		{
			this -> setValue(x.mIndices[i],(getValue(x.mIndices[i])+x.getValue(x.mIndices[i])));
		}

		return *this;
	}

	//subtracts x from the current vector
	SparseVector<T>& operator-= (SparseVector<T> const& x)
	{
		for(int i = 0; i < x.mIndices.size(); i++)
		{
			this -> setValue(x.mIndices[i],(getValue(x.mIndices[i])-x.getValue(x.mIndices[i])));
		}
		return *this;
	}

	//PRINT FUNKTION
	// 	void Print()
	// 	{
	// 		std::cout << "\nindices: ";
	// 		for (int i=0; i<mIndices.size(); i++)
	// 		{
	// 			std::cout << mIndices[i] << " ";
	// 		}
	// 		std::cout << std::endl << "values: ";
	// 		for (int i=0; i<mValues.size(); i++)
	// 		{
	// 			std::cout << mValues[i] << " ";
	// 		}
	// 		std::cout << std::endl;
	// 	}
	// };
};


// computes z= x+y, equivalent to z=x, z+=y
template<class T>
SparseVector<T> operator+(SparseVector<T> const& x, SparseVector<T> const& y)
{
	SparseVector<T> res = x;
	res += y;

	return res;
}

// computes z= x-y, equivalent to z=x, z-=y
template<class T>
SparseVector<T> operator-(SparseVector<T> const& x, SparseVector<T> const& y)
{
	SparseVector<T> res = x;
	res -= y;

	return res;
}


// computes the matrix-vector product of a dense matrix and sparse vector z=Ax.
// The result is a dense vector.
template<class T>
Vector<T> operator* (Matrix<T> const& A, SparseVector<T> const& x)
{
	Vector<T> karl(x.size());

	for (int i=0; i<A.GetNumberOfRows(); i++)
	{
		for (int j=0; j<x.size(); j++)
		{
			karl[i] += A(i,j)*x.getValue(j);
		}
	}
	return karl;
}

// computes the matrix-vector product of a dense matrix and sparse vector z=x^TA.
// The result is a dense vector.
template<class T>
Vector<T> operator* (SparseVector<T> const& x, Matrix<T> const& A)
{
	Vector<T> karl(A.GetNumberOfColumns());

	for (int i=0; i<A.GetNumberOfColumns(); i++)
	{
		for (int j=0; j<x.size(); j++)
		{
			karl[i] += x.getValue(j)*A[j,i];
		}
	}

	return karl;
}


#endif
