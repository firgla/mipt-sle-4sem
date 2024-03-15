#include "../src/CSRMatrix.h"
#include "gtest/gtest.h"



TEST(testCSR, satisfies) 
{
    std::vector<double> values1 = {1. , 2. , 3. , 4. , 5.};
    std::vector<long unsigned int> cols1 = {0, 1, 3, 0, 2};
    std::vector<long unsigned int> rows1 = {0, 2, 3, 4, 5};

    std::vector<double> values2 = {5, 6, 7, 8};

    std::vector<double> values3 = {5. , 6. , 7. , 8. , 9.};
    std::vector<long unsigned int> cols3 = {0, 3, 1, 3, 0};
    std::vector<long unsigned int> rows3 = {0, 2, 3, 4, 5};

    std::vector<double> vec1 = {1. , 2.};

    CSR_Matrix matrix1(values1, cols1, rows1);
    CSR_Matrix matrix2(2, 2, values2);
    CSR_Matrix matrix3(values3, cols3, rows3);

    CSR_Matrix matrix4 = matrix1 + matrix3;
    std::vector<double> vec2 = matrix2 * vec1;

    ASSERT_EQ(matrix1(1,3), 3);
    ASSERT_EQ(matrix4(0,3), 9);
    ASSERT_EQ(vec2[1], 23);

}