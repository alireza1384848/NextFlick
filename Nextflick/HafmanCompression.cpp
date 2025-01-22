#include "HafmanCompression.h"
#include "HafmanCompression.h"


HafmanCompression::HafmanCompression(string bits)
{
	for (size_t i = 0; i < bits.size(); i++)
	{
		auto pa = frequency.find(bits[i]);
		if (pa == frequency.end())
		{
			frequency.insert(make_pair(bits[i], 1));
		}
		else pa->second++;
	}
	this->bits = bits;
	//print
	//for (auto a = frequency.begin();a!=frequency.end();a++)
	//{
	//	cout << a->first << ":" << a->second;
	//}
}
minheapnode* HafmanCompression::buildtree()
{
	priority_queue<minheapnode*, vector<minheapnode*>, compair> mintree;

	for (auto a = frequency.begin(); a != frequency.end(); a++)
		mintree.push(new minheapnode(a->first, a->second));

	while (mintree.size() > 1)
	{
		auto first = mintree.top(); mintree.pop();
		auto sec = mintree.top(); mintree.pop();
		minheapnode* merged = new minheapnode('\0', first->freq + sec->freq);
		merged->left = first;
		merged->right = sec;
		mintree.push(merged);
	}
	root = mintree.top();
	return mintree.top();
}

void HafmanCompression::buildcodemap(minheapnode* root, string code)
{
	if (root == nullptr)return;
	if (root->ch != '\0') {
		codemap[root->ch] = code;
	}
	buildcodemap(root->left, code + "0");
	buildcodemap(root->right, code + "1");
}

string HafmanCompression::incode()
{
	string aa;
	buildcodemap(buildtree(), aa);
	string coded = "";
	const char* a = bits.c_str();
	for (auto i = 0; i < bits.size(); i++)
	{
		coded += codemap.find(a[i])->second;
	}
	return coded;
}

string HafmanCompression::decode(const string& coded)
{
	string decode = "";
	auto temp = root;

	for (auto& chr : coded)
	{
		temp = (chr == '0') ? temp->left : temp->right;
		if (temp->ch != '\0')
		{
			decode += temp->ch;
			temp = root;
		}

	}
	return decode;

}



