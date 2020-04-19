#ifndef TICKHEADERDEF
#define TICKHEADERDEF

#include <vector>

template<typename T>
class tick
{
private:
  std::vector<T> mVec;
  int mSize;
public:
  tick(int size)
  : mVec(size)
  {
  }

  T& operator[](int i)
    {
        assert(i >= 0 && i < mSize);
        return mVec[i];
    }

	T const& operator[] (int i)const
    {
        assert(i >= 0 && i < mSize);
        return mVec[i];
    }
};


#endif
