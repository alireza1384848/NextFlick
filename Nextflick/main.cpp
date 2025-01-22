#include"signup.h"
#include "HashTable.h"
#include"Video.h"
#include "Serial.h"
//void func(Video v)
//{
//	std::vector<std::vector<Video>> a(3);
//	for (int i = 0; i < 3; i++)
//	{
//		a[i].resize(10);
//	}
//	a[0].push_back(v);
//}
int main(){
	Serial act("a", 1399, 215, Iran, Action, Persian, 9, "jjhdbd",18,12);
	HashTable<Video> action(100);
	action.insertToHashTable(act, Comedy);
	/*HashTable<int> myHashTable(10);
	myHashTable.insertToHashTable(act, 3);*/
	//func(act);
}