#pragma once
#include<string>
#include<iostream>
#include <cstdlib>

#include<vector>
using namespace std;

class signup
{

	//user
	
	vector<string>Luser;
	vector<string>Lpasswd;
public:
	void signupGui();
	bool signinGui();
	bool verifypassword(string username, string password);


};

