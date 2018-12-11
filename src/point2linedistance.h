#ifndef POINT2LINEDISTANCE_H
#define POINT2LINEDISTANCE_H

#include "point2.h"

#include <vector>

template <typename T>
std::vector<Point2<T>> closestPoints(const T& m, const T& n, const std::vector<Point2<T>>& points)
{
  // allocate output
  std::vector<Point2<T>> out(points.size());

  // Get equation parameters
  T a = -m;
  T b = T(1);
  T c = -n;

  // Compute
  for (size_t i = 0; i < points.size(); i++)
  {
    T x0 = points[i].x();
    T y0 = points[i].y();
    T x = (b * (b * x0 - a * y0) - a * c) / (pow(a, 2) + pow(b, 2));
    T y = (a * (-b * x0 + a * y0) - b * c) / (pow(a, 2) + pow(b, 2));
    out[i] = Point2<T>(x, y);
  }

  // Exit
  return out;
}

#endif  // POINT2LINEDISTANCE_H
