#ifndef TESTCOSTFUNCTION_H
#define TESTCOSTFUNCTION_H

#include <vector>
#include "point2.h"

#include <iostream>

class TestCostFunction
{
public:
  TestCostFunction(const std::vector<Point2<float>>& p2d);

  template <typename T>
  bool operator()(T const* const* parameters, T* residuals) const
  {
    std::cout << "Evaluating cost function" << std::endl;
    T m = parameters[0][0];
    T n = parameters[0][1];
    T a = -m;
    T b = T(1);
    T c = -n;

    // For each point compute distance
    for (size_t i = 0; i < m_p2d.size(); i++)
    {
      T x0 = T(m_p2d[i].x());
      T y0 = T(m_p2d[i].y());
      T x = (b * (b * x0 - a * y0) - a * c) / (pow(a, 2) + pow(b, 2));
      T y = (a * (-b * x0 + a * y0) - b * c) / (pow(a, 2) + pow(b, 2));
      residuals[2 * i] = x0 - x;
      residuals[2 * i + 1] = y0 - y;
    }

    // Exit
    return true;
  }

protected:
  std::vector<Point2<float>> m_p2d;
};
#endif
