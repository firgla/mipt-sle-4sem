#pragma once
#include <new>
#include <cstdlib>
#include <iostream>
#include <vector>

template<typename T>
std::vector<T> operator+(const std::vector<T>& vector1, const std::vector<T>& vector2)
{
    std::vector<T> new0;
    
    for(std::size_t i = 0; i < vector1.size(); i++)
    {
        new0.push_back(vector1[i] + vector2[i]);
    }

    return new0;
}

template<typename T>
std::vector<T> operator-(const std::vector<T>& vector1, const std::vector<T>& vector2)
{
    std::vector<T> new0;
    
    for(std::size_t i = 0; i < vector1.size(); i++)
    {
        new0.push_back(vector1[i] - vector2[i]);
    }

    return new0;
}

template<typename T>
std::vector<T> operator*(const std::vector<T>& vector1, T number)
{
    std::vector<T> new0;
    
    for(std::size_t i = 0; i < vector1.size(); i++)
    {
        new0.push_back(vector1[i] * number);
    }

    return new0;
}

template<typename T>
T scalar(const std::vector<T>& vector1, const std::vector<T>& vector2)
{
    T new0 = 0;
    for(std::size_t i = 0; i < vector1.size(); i++)
    {
        new0 += (vector1[i] * vector2[i]);
    }

    return new0;
}


