#pragma once
#include <ostream>
#include "List.h"
#include <iostream>
#include <stdexcept>


template <typename T> 
class ListArray:public List<T>
{
    private:
    T* arr{};
    int max{};
    int n{};
    static const int MINSIZE=2;
    void resize(int new_size)
    {
        T* newArr = new T[new_size];
        for (int i = 0; i < n; ++i) 
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        max = new_size;
    }

    public:

    ListArray()
    {
        arr=new T[MINSIZE];
        max=MINSIZE;
        n=0;
    }

    ~ListArray()
    {
        delete[] arr;
    }

    T operator[](int pos)
    {
        if(pos<0||pos>=n)
        {
            throw std::out_of_range("Index out of range");
        }
        return arr[pos];
    }

    friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list)
    {
        for (int i = 0; i < list.n; ++i)
        {
            out << list.arr[i]<<"\n";
        }
        return out;
    }
};