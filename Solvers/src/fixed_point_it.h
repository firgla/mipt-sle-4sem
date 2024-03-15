#pragma once
#include "../../Dense_CSRMatrix/src/CSRMatrix.h"
#include "../../Dense_CSRMatrix/src/vector.h"

template<typename T>
std::vector<double> fixed_point_it(CSR_Matrix<T>& matrix, const std::vector<T>& b,  const std::vector<T>& x_0, double tau, long double wanted_residual)
{
    std::size_t n = x_0.size();
    double residual = 1e8;

    std::vector<double> x(n);
    std::vector<double> err(n);
    std::vector<double> x_0_new(n);

    std::copy(x_0.begin(), x_0.end(), x_0_new.begin());

    while(residual > wanted_residual)
    {
        err = matrix * x_0_new - b;
        x = x_0_new - err * tau;

        std::copy(x.begin(), x.end(), x_0_new.begin());

        residual = std::sqrt(scalar(err, err));
    }

    return x_0_new;

}

