#include "CompressedTrieTree.h"

void CompressedTrieTree::insert_key(std::string& key)
{
	TrieNode* currentNode = root;

	for (auto c : key)
	{

		if (currentNode->childNode[c - 'a'] == NULL)
		{

			TrieNode* newNode = new TrieNode();

			currentNode->childNode[c - 'a'] = newNode;
		}
		currentNode = currentNode->childNode[c - 'a'];
	}
	currentNode->wordCount++;
}

bool CompressedTrieTree::search_key(std::string& key)
{
	TrieNode* currentNode = root;

	for (auto c : key)
	{

		if (currentNode->childNode[c - 'a'] == NULL)
			return false;

		currentNode = currentNode->childNode[c - 'a'];
	}

	return (currentNode->wordCount > 0);
}

bool CompressedTrieTree::delete_key(std::string& word)
{
	TrieNode* currentNode = root;
	TrieNode* lastBranchNode = NULL;
	char lastBrachChar = 'a';

	for (auto c : word)
	{
		if (currentNode->childNode[c - 'a'] == NULL)
			return false;

		int count = 0;
		for (int i = 0; i < 26; i++)
		{
			if (currentNode->childNode[i] != NULL)
				count++;
		}

		if (count > 1)
		{
			lastBranchNode = currentNode;
			lastBrachChar = c;
		}
		currentNode = currentNode->childNode[c - 'a'];
	}

	int count = 0;
	for (int i = 0; i < 26; i++) 
	{
		if (currentNode->childNode[i] != NULL)
			count++;
	}

	if (count > 0) 
	{
		currentNode->wordCount--;
		return true;
	}

	if (lastBranchNode != NULL)
	{
		lastBranchNode->childNode[lastBrachChar] = NULL;
		return true;
	}

	else 
	{
		root->childNode[word[0]] = NULL;
		return true;
	}
}

