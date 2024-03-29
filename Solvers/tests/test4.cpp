#include "../src/simm_gauss_seidel.h"
#include "../../Dense_CSRMatrix/src/CSRMatrix.h"
#include "gtest/gtest.h"

TEST(chebyshev, test_1)
{
    std::vector<double> values1 = {120, 20, 10, 20, 60, 5, 10, 5, 80};
    std::vector<long unsigned int> cols1 = {0, 1, 2, 0, 1, 2, 0, 1, 2};
    std::vector<long unsigned int> rows1 = {0, 3, 6, 9};

    std::vector<double> x = {0, 0, 0};
    std::vector<double> b = {0, 240, 30};

    CSR_Matrix matrix1(values1, cols1, rows1);

    std::vector<double> ans = simm_gauss_seidel(matrix1, b, x, 1e-10);
    std::vector<double> true_ans = {-0.7206703910614525, 4.2234636871508380, 0.2011173184357542};
    for(unsigned int i = 0; i < ans.size(); i++)
    {
       ASSERT_NEAR(ans[i], true_ans[i], 1e-8);
    }

}