#pragma once
#include <new>
#include <cstdlib>
#include <iostream>
#include <vector>

template<typename T>
class Dense_Matrix
{
private:
    std::size_t height, width;
    std::vector<T> elements;

public:
    Dense_Matrix(const std::size_t height, const std::size_t width, const std::vector<T>& elements)
        : height(height)
        , width(width)
        , elements(elements)
    {}

    const T operator()(std::size_t i, std::size_t j) const           {return elements[i * width + j];}

    const std::size_t get_width() const                              {return width;}

    const std::size_t get_height() const                             {return height;}

    Dense_Matrix<T> operator+(const Dense_Matrix<T>& matrix2)
    {
        std::vector<T> elements3;
        std::size_t value;

        for (std::size_t i = 0; i < elements.size(); i++)
        {
            value = elements[i] + matrix2.elements[i];
            elements3.push_back(value);
        }
        
        Dense_Matrix<T> matrix3(height, width, elements3);

        return matrix3;
    }

    std::vector<T> operator*(const std::vector<T>& vector) 
    {
        std::vector<T> vector1(height, 0);

        for (std::size_t i = 0; i < height; i++) 
        {
            for (std::size_t j = 0; j < width; j++)
            {
                vector1[i] = vector1[i] + elements[i * width + j] * vector[j];
            }
        }
    
        return vector1;
    }

};


