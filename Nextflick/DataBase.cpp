#include "DataBase.h"
#define HashRows 3
DataBase::DataBase() :gener(HashRows /*count of gener in programm*/), language(HashRows), country(HashRows)
{

}

std::vector<Video> DataBase::FilteringMovies(int _gener, int _language, int _country)
{
	std::vector<Video> concate;
	if (_gener > 2 || _gener < 0)

		for (int i = 0; i < HashRows; i++)
			for (int j=0;j<gener.hashTableSize(i);j++)

			

			
		
}
