#pragma once
#include "../../Dense_CSRMatrix/src/CSRMatrix.h"
#include "../../Dense_CSRMatrix/src/vector.h"


template<typename T>
std::vector<double> chebyshev(CSR_Matrix<T>& matrix, const std::vector<T>& b, const std::vector<T>& x_0, long double wanted_residual, int r, double lambda_min, double lambda_max)
{
    //1. нахождение корней полинома Чебышева


    size_t n = static_cast<size_t>(std::pow(2, r));
    std::vector<double> polynoms(n);

    
    for(size_t i = 0; i < n; i++)
    {
        polynoms[i] = 1 / ((lambda_min + lambda_max) / 2 + ((lambda_min + lambda_max) / 2) * (std::cos((3.1415926535 * (2 * i + 1) ) / (2 * n))));
    }

    //2.Ищем устойчивую последовательность индексов шагов

    std::vector<size_t> indexes(n);
    indexes[static_cast<size_t>(std::pow(2, r - 1))] = 1;
    size_t step = 0;
    for (int i = 2; i <= r; i++) 
    {
        step = static_cast<size_t>(std::pow(2, r - i));
        for (size_t j = 0; j < n; j += 2 * step) 
        {
            indexes[j + step] = static_cast<size_t>(std::pow(2, i)) - indexes[j] - 1;
        }
    }
    



    //3.Собираем все

    double residual = 1;
    std::vector<double> x(x_0.size());
    std::vector<double> err(x_0.size());
    std::vector<double> x_0_new(x_0.size());

    std::copy(x_0.begin(), x_0.end(), x_0_new.begin());

    while(residual > wanted_residual)
    {
        for(size_t i = 0; i < indexes.size(); i++)
        {
            err = matrix * x_0_new - b;
            x = x_0_new - err * polynoms[indexes[i]];

            std::copy(x.begin(), x.end(), x_0_new.begin());

            residual = std::sqrt(scalar(err, err));
            if (residual < wanted_residual)
            {
                break;
            }
        }

        residual = std::sqrt(scalar(err, err));
    }

    return x_0_new;

}

