#pragma once
#include "Video.h"
class Serial :public Video
{
private:
	int countOfSeasons;
	int countOfParts;
public:
	Serial(std::string name, int year, double time, Country country,
		Genre genre, Language language, double score, std::string story
		, int countOfSeasons, int countOfParts
	);
	int getcountOfSeasons();
	int getcountOfParts();
};

