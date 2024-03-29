#pragma once
#include "../../Dense_CSRMatrix/src/CSRMatrix.h"
#include "../../Dense_CSRMatrix/src/vector.h"

template<typename T>
std::vector<double> simm_gauss_seidel(CSR_Matrix<T>& matrix, const std::vector<T>& b,  const std::vector<T>& x_0, long double wanted_residual)
{
    std::size_t n = x_0.size();
    double residual = 1e8;

    std::vector<double> err(n);
    std::vector<double> x_0_new(n);

    std::copy(x_0.begin(), x_0.end(), x_0_new.begin());

    while(residual > wanted_residual)
    {
        for(std::size_t i = 0; i < x_0_new.size(); i++)
        {
            std::size_t k = x_0_new.size() - i - 1;
            double tmp = 0;
            for(std::size_t j = matrix.get_rows()[k]; j < matrix.get_rows()[k+1]; j++)
            {
                if(matrix.get_cols()[j] != k)
                {
                    tmp += matrix.get_values()[j] * x_0_new[matrix.get_cols()[j]];
                }
            }

            x_0_new[k] = (b[k] - tmp) / matrix(k,k);
        }

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

            x_0_new[i] = (b[i] - tmp) / matrix(i,i);
        }

        err = matrix * x_0_new - b;
        residual = std::sqrt(scalar(err, err));
    }

    return x_0_new;
}