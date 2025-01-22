#include "DataBase.h"
#include "Video.h"
#include "Serial.h"

#define HashRows 3
DataBase::DataBase() :gener(HashRows /*count of gener in programm*/), language(HashRows), country(HashRows)
{

}

std::vector<Video> DataBase::FilteringMovies(int _gener, int _language, int _country)
{
	Serial act("a", 1399, 215, Iran, Action, Persian, 9, "jjhdbd", 18, 12);
	std::vector<Video> concate;
	if (_gener > 2 || _gener < 0)
		for (int i = 0; i < HashRows; i++)
			for (int j = 0; j < gener.hashTableSize(i); j++)
				concate.push_back(act);

			

	return std::vector<Video>();
		
}
