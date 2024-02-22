#pragma once
#include <new>
#include <cstdlib>
#include <iostream>
#include <vector>

template<typename T>
std::vector<T> operator+(const std::vector<T>& vector1, const std::vector<T>& vector2)
{
    std::vector<T> new;
    
    for(std::size_t i = 0; i < vector1.size(); i++)
    {
        new.push_back(vector1[i] + vector2[i]);
    }

    return new;
}

template<typename T>
std::vector<T> operator*(const std::vector<T>& vector1, T number)
{
    std::vector<T> new;
    
    for(std::size_t i = 0; i < vector1.size(); i++)
    {
        new.push_back(vector1[i] * number);
    }

    return new;
}

template<typename T>
T scalar(const std::vector<T>& vector1, const std::vector<T>& vector2)
{
    T new = 0;
    for(std::size_t i = 0; i < vector1.size(); i++)
    {
        new += (vector1[i] * vector2[i]);
    }

    return new;
}


