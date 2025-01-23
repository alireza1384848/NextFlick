#include "DataBase.h"
#include "Video.h"
#include "Serial.h"

#define HashRows 3
DataBase::DataBase() :gener(HashRows /*count of gener in programm*/), language(HashRows), country(HashRows)
{

}

std::vector<Video> DataBase::FilteringMovies(int _gener, int _language, int _country)
{
	std::vector<Video> concate;
	if (_gener > 2 || _gener < 0)
		for (int i = 0; i < HashRows; i++)
			for (int j = 0; j < gener.hashTableSize(i); j++)
				concate.push_back(gener.ReturnVideo(i,j));
	if(_language > 2 || _language < 0)
		for (int i = 0; i < HashRows; i++)
			for (int j = 0; j < language.hashTableSize(i); j++)
				concate.push_back(language.ReturnVideo(i, j));
	if(_country > 2 || _country < 0)
		for (int i = 0; i < HashRows; i++)
			for (int j = 0; j < country.hashTableSize(i); j++)
				concate.push_back(country.ReturnVideo(i, j));

	return std::vector<Video>();
		
}
