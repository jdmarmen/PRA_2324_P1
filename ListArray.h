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
    int n{}; //number of elements stored
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
            throw std::out_of_range("Index out of range");

        return arr[pos];
    }

    friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list)
    {
        for (int i = 0; i < list.n; ++i)
            out << list.arr[i]<<"\n";

        return out;
    }

    void insert (int pos, T e) override
    {
        if(pos<0 || pos>n)
            throw std::out_of_range("Index out of range!\n");
        
        if(n==max)
            resize(max*2);
        
        for(int i=n; i>pos; i--)
            arr[i]=arr[i-1];

        arr[pos]=e;
        n++;                    
    }

    void append(T e) override
    {
        if(n==max)
            resize(max*2);

        arr[n]=e;
        n++;
    }

    void prepend(T e) override
    {
        insert(0,e);
    }

    T remove(int pos) override
    {
        if(pos<0 || pos>=n)
            throw std::out_of_range("Index out of range!\n");

        T removed_element=arr[pos];

        for(int i=pos; i<(n-1);i++)
            arr[i]=arr[i+1];

        n--;

        return removed_element;
    }

    T get(int pos) override
    {
        if(pos<0 || pos>=n)
            throw std::out_of_range("Index out of range!\n");

        return arr[pos];
    }

    int search(T e) override
    {
        int err=-1;
        for(int i=0; i<n;i++)
        {
            if(arr[i]==e)
            {
                err=i;
                break;
            }
        }
        return err;
    }

    bool empty() override
    {
        if(n==0)
            return true;
        else
            return false;
    }

    int size() override
    {
        return n;
    }
};