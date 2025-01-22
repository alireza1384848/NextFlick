#include "signup.h"

void signup::signupGui()
{
	system("cls");
	string input;
	cout << "\t\t\t\t\t Sign up "<<endl;
	cout << "Enter Username : ";
	cin >> input;
	cout<<endl;
	Luser.push_back(input);
	cout << "Enter Password : ";
	cin >> input;
	Lpasswd.push_back(input);
	cout << endl;

	cout << "sign up successfully Done!";

}

bool signup::signinGui()
{
	system("cls");
	string inputusr;
	string inputpass;
	cout << "\t\t\t\t\t Sign in " << endl;
	cout << "Username : ";
	cin >> inputusr;
	cout << endl;
	cout << "Password : ";
	cin >> inputpass;
	Lpasswd.push_back(inputpass);
	cout << endl;
	bool Vp = verifypassword(inputusr, inputpass);
	Vp ? cout << "sign in successfully Done!" : cout << "Username/Password isn't correct!";
	return Vp;
}

bool signup::verifypassword(string username, string password)
{
	for(int i=0;i<Luser.size();i++)
	{
		if (Luser[i] == username && Lpasswd[i] == password)
			return true;
	}
	return false;

}
