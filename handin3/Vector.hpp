#ifndef VECTORTESTHEADERDEF
#define VECTORTESTHEADERDEF

#include <cassert>
#include <cmath>
#include <vector>

template <typename T>
class Vector
{
private:
	std::vector<T> mData;// T* mData; // data stored in vector
	int mSize; // size of vector

public:
	//constructor
	Vector(int size)
	{
		assert(size>0);
		mSize = size;
		mData.assign(size,0);
	}

	// //copy constructor - works automatically bc of <vector>
	// Vector(const Vector& otherVector)
	// {
		// mSize = otherVector.mSize;
		// mData = otherVector.mData;
	// }

	//access
	T& operator[](int i)
    {
        assert(i >= 0 && i < mSize);
        return mData[i];
    }

	//access
	T const& operator[] (int i)const
    {
        assert(i >= 0 && i < mSize);
        return mData[i];
    }

	//size function - doens't generate automatically
	int size() const
	{
		return mSize;
	}

	// //assignment operator - works automatically bc of <vector>
	// Vector& operator=(const Vector& otherVector)
  //   {
  //       assert(mSize == otherVector.mSize);
	//
  //       for (int i = 0; i < mSize; i++)
  //       {
  //           mData[i] = otherVector.mData[i];
  //       }
  //       return *this;
  //   }

  //overloading the unary - operator
	Vector operator-() const
    {
        Vector<T> v(mSize);
        for (int i = 0; i < mSize; i++)
        {
            v[i] = -mData[i];
        }
        return v;
    }

  //overloading the binary + operator
	Vector operator+(const Vector& v1) const
    {
        assert(mSize == v1.mSize);

        Vector v(mSize);
        for (int i = 0; i < mSize; i++)
        {
            v[i] = mData[i] + v1.mData[i];
        }
        return v;
    }

  //overloading the binary - operator
	Vector operator-(const Vector& v1) const
    {
        assert(mSize == v1.mSize);

        Vector<T> v(mSize);
        for (int i = 0; i < mSize; i++)
        {
            v[i] = mData[i] - v1.mData[i];
        }
        return v;
    }

	//scalar multiplication
	Vector operator*(double a) const
    {
        Vector<T> v(mSize);
        for (int i = 0; i < mSize; i++)
        {
            v[i] = a*mData[i];
        }
        return v;
    }

	//p-norm method
	double CalculateNorm(int p = 2) const
    {
        double sum = 0.0;
        for (int i = 0; i < mSize; i++)
        {
            sum += pow(std::abs((double)(mData[i])), p);
        }
        return pow(sum, 1.0 / ((double)(p)));
	}

	//Mandatory function
	std::vector<T> const& getStorage() const
	{
		return mData;
	}
};

#endif
