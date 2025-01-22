#include "Video.h"

Video::Video(std::string name, int year, double time, Country country,
	Genre genre, Language language, double score, std::string story):
	name(name),year(year),time(time),country(country),genre(genre)
	,language(language),score(score), story(story)
{
}
