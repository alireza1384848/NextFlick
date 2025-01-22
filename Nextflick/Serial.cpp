#include "Serial.h"

Serial::Serial
(std::string name, int year, double time, Country country,
	Genre genre, Language language, double score,
	std::string story, int countOfSeasons, int countOfParts) :
	Video(name, year, time, country, genre, language, score, story)
	, countOfParts(countOfParts), countOfSeasons(countOfSeasons)
{
}

int Serial::getcountOfSeasons()
{
	return countOfSeasons;
}

int Serial::getcountOfParts()
{
	return countOfParts;
}
