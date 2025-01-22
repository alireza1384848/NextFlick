#pragma once
#include "CompressedTrieTree.h"
#include "HashTable.h"
#include "Video.h"
class DataBase
{
private:
	CompressedTrieTree trieTree;
	HashTable<int> gener;
	HashTable<Video> country;
	HashTable<Video> language;
public:
	DataBase();
	std::vector<Video> FilteringMovies(int _gener,int _language,int _country);
};

