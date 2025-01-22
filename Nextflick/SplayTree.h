#pragma once
#include<iostream>
using namespace std;
template<typename T>
class Node
{
public:
	T value;
	Node < T>* left;
	Node < T>* right;
	Node(T value, Node<T>*lft = nullptr, Node<T>*rit = nullptr)
	{
		this->value = value;
		left = lft;
		right = rit;
	}




};

template<typename T>
class SplayTree
{
	Node<T>* root;
	Node <T>* leftrotate(Node<T>* x);
	Node <T>* rightrotate(Node<T>* x);
	Node <T>* insert(Node<T>* root, T value);
	Node <T>* erase(Node<T>* root, T value);
	Node <T>* splay(Node<T>* root, T value);
	//test
	void inorder(Node<T>* root)
	{
		if (root) 
		{
			inorder(root->left);
			cout << root->value;
			inorder(root->right);
		}
	}
public:
	SplayTree() { root = nullptr; }
	void insert(T value) { root = insert(root, value); }
	void erase(T value) { root = erase(root, value); }
	bool search(T value) 
	{
		root = splay(root, value);
		return root && root->value == value;
	}
	T nodeval() { return root->value; }
	void print()
	{
		inorder(root);
		cout << endl;
	}

};

template<typename T>
Node <T>* SplayTree<T>::leftrotate(Node<T>* x)
{
	Node<T>* y = x->right;
	x->right = y->left;
	y->left = x;
	return y;
}

template<typename T>
Node <T>* SplayTree<T>::rightrotate(Node<T>* x)
{
	
	Node<T>* lef = x->left;
	x->left = lef->right;
	lef->right = x;
	return lef;
}

template<typename T>
inline Node<T>* SplayTree<T>::insert(Node<T>* root, T value)
{
	if (root == nullptr) root = new Node<T>(value);
	root = splay(root, value);
	if (root->value == value) return root;

	Node<T>* newnode = new Node<T> (value);
	if(value > root->value)
	{
		newnode->left = root;
		newnode->right = root->right;
		root->right = nullptr;

	}
	else
	{
		newnode->right = root;
		newnode->left = root->left;
		root->left = nullptr;
	}
	return newnode;




}

template<typename T>
Node<T>* SplayTree<T>::erase(Node<T>* root, T value)
{
	if (root == nullptr)return nullptr;
	root = splay(root, value);
	if (root->value != value) return root;
	if(root->left == nullptr)
	{
		Node<T>* temp = root->right;
		delete root;
		return temp;
	}
	else
	{
		Node<T>* temp = root->left;
		temp = splay(temp, value);
		temp->right = root->right;
		delete root;
		return temp;
		
	}

}


template<typename T>
Node<T>* SplayTree<T>::splay(Node<T>* root, T value)
{
	if (root == nullptr || root->value == value)return root;
	//left tree
	if (root->value > value)
	{
		if (root->left == nullptr)return root;

		if(value < root->left->value)
		{
			root->left->left = splay(root->left->left, value);
			root = rightrotate(root);
		}
		else if (value > root->left->value)
		{
			root->left->right = splay(root->left->right, value);
			if(root->left->right != nullptr)
			{
				root->left = leftrotate(root->left);
			}
		}

		if (root->left != nullptr)return rightrotate(root);
		else return root;
	}
	//right tree
	else
	{
		if (root->right == nullptr)return root;
		if(root->right->value < value)
		{
			root->right->right = splay(root->right->right, value);
			root = leftrotate(root);
		}
		else if( root->right->value > root->value)
		{
			root->right->left = splay(root->right->left, value);
			if(root->right->left)
			{
				root->right = rightrotate(root->right);
			}

		}

		if (root->right != nullptr)return leftrotate(root);
		else return root;
	}


}
