#include "../src/algorithm/include/rr/algorithm.h"
#include <iostream>
#include "gtest/gtest.h"
#include <vector>

TEST(TRIDIAGONAL, TEST_1) {
    std::vector<double> vect1{5.0, 1.0};
    std::vector<double> vect2{2.0 , 4.0, -3.0};
    std::vector<double> vect3{-1.0, 2.0};
    std::vector<double> d{3.0, 6.0, 2.0};
    Tridiagonal_Matrix matrix{vect1, vect2, vect3};
    std::vector<double> x = Algorithm(matrix, d);
    ASSERT_NEAR(x[0], 1.48837209302326, 1e-14);
    ASSERT_NEAR(x[1], -0.023255813953488, 1e-14);
    ASSERT_NEAR(x[2], -0.674418604651163, 1e-14);
}

