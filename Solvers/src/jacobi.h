#pragma once
#include "../../Dense_CSRMatrix/src/CSRMatrix.h"
#include "../../Dense_CSRMatrix/src/vector.h"

template<typename T>
std::vector<double> jacobi(CSR_Matrix<T>& matrix, const std::vector<T>& b,  const std::vector<T>& x_0, long double wanted_residual)
{
    std::size_t n = x_0.size();
    double residual = 1e8;

    std::vector<double> x(n);
    std::vector<double> err(n);
    std::vector<double> x_0_new(n);

    std::copy(x_0.begin(), x_0.end(), x_0_new.begin());

    while(residual > wanted_residual)
    {
        for(std::size_t i = 0; i < x_0_new.size(); i++)
        {
            double tmp = 0;

            for(std::size_t j = matrix.get_rows()[i]; j < matrix.get_rows()[i+1]; j++)
            {
                if(matrix.get_cols()[j] != i)
                {
                    tmp += matrix.get_values()[j] * x_0_new[matrix.get_cols()[j]];
                }
            }

            x[i] = (b[i] - tmp) / matrix(i,i);
        }

        std::copy(x.begin(), x.end(), x_0_new.begin());
        err = matrix * x - b;
        residual = std::sqrt(scalar(err, err));
    }

    return x_0_new;

}