#pragma once
#include <iostream>

struct TrieNode {

    TrieNode* childNode[26];
    int wordCount;

    TrieNode()
    {
        wordCount = 0;
        for (int i = 0; i < 26; i++)
            childNode[i] = nullptr;

    }
};

class CompressedTrieTree
{
private:
    TrieNode* root;
public:
    CompressedTrieTree()
    {
        root = new TrieNode();
    }
    
    void insert_key(std::string& key);

    bool search_key(std::string& key);

    bool delete_key(std::string& word);

};

