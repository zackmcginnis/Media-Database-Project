#pragma once

#include "item.h"

class Movie :
	public Item
{
public:
	static string getMediaTypeName();
	Movie(void);
	Movie(const string& movieTitle);
	Movie(const string& movieTitle, const string& newDirector, const int& newDivisions);
	Movie(const string& movieTitle, const string& newDirector, const int& newDivisions, const int& nKeywords, ...);
	~Movie(void);

	string toString() const;
	bool hasActor(const string& actorName) const;
	bool hasDirector(const string& directorName) const;
	string getCreatorType() const;
	string getMediaType() const;
	string getDivisionType() const;
	string getCastType() const;
	void addCast(const int& nArgs, ...);	
	set<string> getCast() const;
	void setCast(const set<string>& newCast); 

private:
	static const string CREATOR_TYPE;
	static const string MEDIA_TYPE;
	static const string DIVISION_TYPE;
	static const string CAST_TYPE;

	set<string> cast;
	string printCast() const;

};