#include "../src/algorithm/algorithm.h"
#include <iostream>
#include "gtest/gtest.h"
#include <vector>

TEST(test1, satisfies) 
{
    std::vector<double> vect1{-1.0, 1.0, -6.0};
    std::vector<double> vect2{6.0 , 5.0, 10.0, 8.0};
    std::vector<double> vect3{5.0, 3.0, 3.0};

    std::vector<double> d{1.0, 6.0, 6.0, 10.0};

    Tridiagonal_Matrix matrix{vect1, vect2, vect3};

    std::vector<double> x = Algorithm(matrix, d);

    ASSERT_NEAR(x[0], -0.6707242848447961, 1e-14);
    ASSERT_NEAR(x[1], 1.0048691418137553, 1e-14);
    ASSERT_NEAR(x[2], 0.1016433353621424, 1e-14);
    ASSERT_NEAR(x[3], 1.3262325015216068, 1e-14);

}

TEST(test2, doesnt_satisfies) 
{
    std::vector<double> vect1{5.0, 3.0, 3.0};
    std::vector<double> vect2{6.0 , 2.0, 10.0, -3.0};
    std::vector<double> vect3{-1.0, 1.0, -6.0};

    std::vector<double> d{1.0, 6.0, 6.0, 10.0};

    Tridiagonal_Matrix matrix{vect1, vect2, vect3};

    std::vector<double> x = Algorithm(matrix, d);

    ASSERT_NE(x[0], 2.5);
    ASSERT_NE(x[1], -2.8);
    ASSERT_NE(x[2], 4.7);
    ASSERT_NE(x[3], -12.7333333);

}

