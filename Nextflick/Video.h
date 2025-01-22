#pragma once
#include <iostream>

enum Country
{
	American,France,Iran
};
enum Genre
{
	Action,Comedy,Drama
};
enum Language
{
	English,French,Persian
};

class Video
{
private:
	std::string name;
	int year;
	double time;
	Country country;
	Genre genre;
	Language language;
	double score;
	std::string story;
public:
	Video(std::string name, int year, double time, Country country, 
		Genre genre,Language language,double score,std::string story
	);
};

