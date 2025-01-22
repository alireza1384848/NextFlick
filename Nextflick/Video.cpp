#include "Video.h"

Video::Video(std::string name, int year, double time, Country country,
	Genre genre, Language language, double score, std::string story) :
	name(name), year(year), time(time), country(country), genre(genre)
	, language(language), score(score), story(story)
{
}

Video::Video() {};

std::string Video::getName()
{
	return std::string(name);
}

int Video::getYear()
{
	return year;
}

double Video::getTime()
{
	return time;
}

int Video::getCountry()
{
	return country;
}

int Video::getGenre()
{
	return genre;
}

int Video::getLanguage()
{
	return language;
}

double Video::getScore()
{
	return score;
}

std::string Video::getStory()
{
	return std::string(story);
}
