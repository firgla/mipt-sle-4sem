#pragma once
#include <new>
#include <cstdlib>
#include <iostream>
#include <vector>

template<typename T>
class CSR_Matrix
{
private:
    std::vector<T> values;
    std::vector<long unsigned int> cols;
    std::vector<long unsigned int> rows;

public:
    CSR_Matrix(const std::vector<T>& values, const std::vector<long unsigned int>& cols, const std::vector<long unsigned int>& rows)
        : values(values)
        , cols(cols)
        , rows(rows)
    {}

    CSR_Matrix(const long unsigned int height, const long unsigned int width, const std::vector<T>& elements)
    {
        rows.push_back(0);
        long unsigned int row = 0;

        for(long unsigned int i = 0; i < height; i++)
        {
            for(long unsigned int j = 0; j < width; j++)
            {
                if (elements[i * width + j] != 0) 
                {
                    values.push_back(elements[i * width + j]);
                    cols.push_back(j);
                    row++;
                }
            }

            rows.push_back(row);
        }
    }

    const std::vector<long unsigned int> get_cols() const                              {return cols;}
    const std::vector<long unsigned int> get_rows() const                              {return rows;}

    const T operator()(long unsigned int i, long unsigned int j) const     
    {
        for(long unsigned int k = rows[i]; k < rows[i + 1]; k++)
        {
            if(cols[k] == j)
            {
                return values[k];
            }
        }

        return 0;
    }

    CSR_Matrix<T> operator+(CSR_Matrix<T>& left)
    {

        long unsigned int n = std::max((*this).get_rows().size(), left.get_rows().size());
        long unsigned int m = std::max(*std::max_element(left.get_cols().begin(), left.get_cols().end()), *std::max_element((*this).get_cols().begin(),(*this).get_cols().end()));
    
        std::vector<T> new_values;
        std::vector<long unsigned int> new_cols;
        std::vector<long unsigned int> new_rows;
        long unsigned int row = 0;
        new_rows.push_back(row);

        for (long unsigned int i = 0; i < n - 1; i ++)
        {
            for (long unsigned int j = 0; j < m + 1; j++)
            {
                if (((*this)(i,j) + left(i,j)) != 0)
                {
                    new_values.push_back((*this)(i,j) + left(i,j));
                    new_cols.push_back(j);
                    row++;
                }
        
            }
        
            new_rows.push_back(row);
        }

       

        return CSR_Matrix(new_values, new_cols, new_rows);
    }


    std::vector<T> operator*(const std::vector<T>& vector) 
    {
        std::vector<T> vec;
        T elem;

        for (long unsigned int i = 0; i < rows.size() - 1; i++) 
        {
            elem = 0;
            for (long unsigned int j = rows[i]; j < rows[i + 1]; j++) 
            {
                elem += values[j] * vector[cols[j]];
            }
            
            vec.push_back(elem);
        }

        return vec;
    }

};
