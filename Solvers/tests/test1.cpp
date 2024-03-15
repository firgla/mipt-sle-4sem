#include "../src/fixed_point_it.h"
#include "../src/gauss_seidel.h"
#include "../src/jacobi.h"
#include "../../Dense_CSRMatrix/src/CSRMatrix.h"
#include "gtest/gtest.h"

TEST(fixed_point_it, test_1)
{
    std::vector<double> values1 = {10, 4, 5, 6, 10, 2, 3, 4, 8};
    std::vector<long unsigned int> cols1 = {0, 1, 2, 0, 1, 2, 0, 1, 2};
    std::vector<long unsigned int> rows1 = {0, 3, 6, 9};

    std::vector<double> x = {0, 0, 0};
    std::vector<double> b = {2, 5, 8};

    CSR_Matrix matrix1(values1, cols1, rows1);

    std::vector<double> ans = fixed_point_it(matrix1, b, x, 0.084, 1e-10);
    std::vector<double> true_ans = {-0.4827586206896552, 0.6149425287356322, 0.8735632183908046};
    for(unsigned int i = 0; i < ans.size(); i++)
    {
       ASSERT_NEAR(ans[i], true_ans[i], 1e-8);
    }
}   

TEST(gauss_seidel, test_2)
{
    std::vector<double> values1 = {10, 4, 5, 6, 10, 2, 3, 4, 8};
    std::vector<long unsigned int> cols1 = {0, 1, 2, 0, 1, 2, 0, 1, 2};
    std::vector<long unsigned int> rows1 = {0, 3, 6, 9};

    std::vector<double> x = {0, 0, 0};
    std::vector<double> b = {2, 5, 8};

    CSR_Matrix matrix1(values1, cols1, rows1);

    std::vector<double> ans = gauss_seidel(matrix1, b, x, 1e-10);
    std::vector<double> true_ans = {-0.4827586206896552, 0.6149425287356322, 0.8735632183908046};
    for(unsigned int i = 0; i < ans.size(); i++)
    {
       ASSERT_NEAR(ans[i], true_ans[i], 1e-8);
    }
}  


TEST(jacobi, test_3)
{
    std::vector<double> values1 = {10, 4, 5, 6, 10, 2, 3, 4, 8};
    std::vector<long unsigned int> cols1 = {0, 1, 2, 0, 1, 2, 0, 1, 2};
    std::vector<long unsigned int> rows1 = {0, 3, 6, 9};

    std::vector<double> x = {0, 0, 0};
    std::vector<double> b = {2, 5, 8};

    CSR_Matrix matrix1(values1, cols1, rows1);

    std::vector<double> ans = jacobi(matrix1, b, x, 1e-10);
    std::vector<double> true_ans = {-0.4827586206896552, 0.6149425287356322, 0.8735632183908046};
    for(unsigned int i = 0; i < ans.size(); i++)
    {
       ASSERT_NEAR(ans[i], true_ans[i], 1e-8);
    }
}  