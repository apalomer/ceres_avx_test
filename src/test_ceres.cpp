#include <ceres/ceres.h>
#include "test_cost_function.h"

int main()
{
  // Line model
  // y = model_coefficients[0]*x+model_coefficients[1]
  int model_coefficients_size = 2;
  double* model_coefficients = new double[model_coefficients_size];
  model_coefficients[0] = 0;
  model_coefficients[1] = 0;

  // Line points
  double model_coefficients_gt[] = { 1, 0 };
  std::vector<Point2<float>> p2d;
  for (int i = 0; i < 1000; i++)
  {
    p2d.push_back(Point2<float>(float(i), model_coefficients_gt[0] * float(i) + model_coefficients_gt[1]));
  }

  // Cost function
  TestCostFunction* lbucf = new TestCostFunction(p2d);
  ceres::DynamicAutoDiffCostFunction<TestCostFunction>* cf =
      new ceres::DynamicAutoDiffCostFunction<TestCostFunction>(lbucf);
  cf->AddParameterBlock(model_coefficients_size);
  cf->SetNumResiduals(2 * p2d.size());

  // Create problem
  ceres::Problem problem;
  problem.AddResidualBlock(cf, NULL, model_coefficients);

  // Set options
  ceres::Solver::Options options;
  options.linear_solver_type = ceres::DENSE_QR;
  options.minimizer_progress_to_stdout = true;
  options.update_state_every_iteration = true;
  options.max_num_iterations = 5000;

  // Solve
  ceres::Solver::Summary summary;
  ceres::Solve(options, &problem, &summary);

  // Display results
  std::cout << summary.FullReport() << std::endl;
  std::cout << model_coefficients[0] << "," << model_coefficients[1] << std::endl;
}
