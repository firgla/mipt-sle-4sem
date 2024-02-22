#include "../src/DenseMatrix.h"
#include "gtest/gtest.h"



TEST(testDense, satisfies) 
{
    std::vector<int> elem = {1, 2, 3, 4};
    std::size_t b = 2;
    std::size_t c = 2;
    Dense_Matrix a(b, c, elem);

    std::vector<int> elem1 = {2, 3, 3, 4};
    std::size_t e = 2;
    std::size_t f = 2;
    Dense_Matrix d(e, f, elem1);

    Dense_Matrix g = a + d;

    std::vector<int> vec = {1, 2};
    std::vector<int> h = a * vec;

    ASSERT_EQ(g(0,0), 3);
    ASSERT_EQ(h[0], 5);

}
