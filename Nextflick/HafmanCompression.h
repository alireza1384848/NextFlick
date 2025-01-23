#pragma once
#include <bitset>
#include <unordered_map>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
struct minheapnode
{
	char ch;
	unsigned int freq;
	minheapnode* left;
	minheapnode* right;
	minheapnode(char c, unsigned int frq) { ch = c; freq = frq; left = nullptr; right = nullptr; }

};
struct compair
{
	bool operator()(minheapnode* l, minheapnode* r) { return l->freq > r->freq; }
};

class HafmanCompression
{
	unordered_map<char, string> codemap;
	unordered_map<char, int> frequency;
	minheapnode* root;
	string bits;
public:
	HafmanCompression(string bits);
	minheapnode* buildtree();
	void buildcodemap(minheapnode* root, string code);
	string incode();
	string decode(const string& coded);

};

