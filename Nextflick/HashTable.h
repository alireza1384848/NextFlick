#pragma once
#include <iostream>
#include <vector>
#include "Video.h"

template<typename T>
class HashTable
{
public:
    HashTable<T>(int row);
    bool insertToHashTable(T data, int key);
private:
    int row;
    std::vector<std::vector<T>> hashTable;  
};

template <typename T>
HashTable<T>::HashTable<T>(int row) : row(row), hashTable(row)  
{
    for (int i = 0; i < row; ++i)
        hashTable[i] = std::vector<T>();
}

template<typename T>
bool HashTable<T>::insertToHashTable(T data, int key)
{
    if (key < 0 || key >= row)
        return false;
    hashTable[key].push_back(data);
}