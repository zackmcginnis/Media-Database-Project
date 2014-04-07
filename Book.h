#pragma once

#include "item.h"

class Book :
	public Item
{
public:
	
	static string getMediaTypeName();
	Book(void);
	Book(const string& newTitle);
	Book(const string& newTitle, const string& newCreator, const int& newDivisions);
	Book(const string& newTitle, const string& newCreator, const int& newDivisions, const int& nKeywords, ...);
	~Book(void);

	string toString() const; 
	string getCreatorType() const;
	string getMediaType() const;
	string getDivisionType() const;
	bool hasAuthor(const string& authorName) const; 
	string getAuthor() const;
	void setAuthor(const string& newAuthor);

private:
	static const string CREATOR_TYPE;
	static const string MEDIA_TYPE;
	static const string DIVISION_TYPE;
	
};

