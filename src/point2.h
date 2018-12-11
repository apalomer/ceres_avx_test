#ifndef POINT2_H
#define POINT2_H

template <typename T>
class Point2
{
public:
  Point2()
  {
    data_ = new T[2];
  }

  Point2(T x, T y) : Point2()
  {
    data_[0] = x;
    data_[1] = y;
  }

  Point2(const Point2& other) : Point2(other.x(), other.y())
  {
  }

  ~Point2()
  {
    delete[] data_;
  }

  T x() const
  {
    return data_[0];
  }

  T y() const
  {
    return data_[1];
  }

protected:
  T* data_;
};

template <typename T>
Point2<T> operator+(const Point2<T>& lhs, const Point2<T>& rhs)
{
  return Point2<T>(lhs.x() + rhs.x(), lhs.y() + rhs.y());
}

template <typename T>
Point2<T> operator*(const T& lhs, const Point2<T>& rhs)
{
  return Point2<T>(lhs * rhs.x(), lhs * rhs.y());
}

#endif  // POINT2_H
