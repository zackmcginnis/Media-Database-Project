#pragma once

#include <iostream>
#include <ostream>
#include <set>
#include <string>
#include <iomanip>
#include <stdarg.h>
#include <sstream>
#include <iostream>

using namespace std;

class Item
{
protected:
	bool hasCreator(const string& creatorName) const; 
	bool hasKeyword(const string& keyWord) const; 
	
	string printKeywords() const;
	string getTitleKeywords() const;	
	string getEntryRow(string hColumn, string& cColumn) const;
	int	getContentDivisions() const;

	virtual string getCreatorAndDivisions() const;	
	virtual string getClassHeader() const;	

	void setCreator(const string& newCreator);	
	void setTitle(const string& newTitle);		
	void setKeywords(const set<string>& newKeywords);	
	void setContentDivisions(const int& newContentDivisions);		

public:
	virtual string getCreatorType() const = 0;
	virtual string getMediaType() const = 0;			
	virtual string getDivisionType() const = 0;	
	virtual string toString() const = 0; 

	string getCreator() const;	
	string getTitle() const;
	static string getMediaTypeName();

	set<string>		getKeywords() const;	
	void addKeyword(const string& wordToAdd);			
	void addKeywords(const set<string>& wordsToAdd);	
	Item(const string& title, const string& artist);
	Item();
	Item(const string& newTitle);
	Item(const string& newTitle, const string& newCreator, const int& newDivisions);
	Item(const string& newTitle, const string& newCreator, const int& newDivisions, const int& nKeywords, ...); 
	virtual ~Item();
				
private:
	static const string TITLE;
	static const string KEYWORDS;
	static string classMediaType; 
	static const int FORMAT_SPACES = 10;
	
	int				contentDivisions;
	string			creator;
	string			title;
	set<string>		keyWords;
	
};

//ptr class
class ItemPtr
{
public:
	ItemPtr(Item *ptr) : 
	  ptr(ptr) 
	  { 
	  }

	Item* getPtr() const 
	{ 
		return ptr; 
	}

private:
	Item	*ptr;
};

//compare
ostream& operator<<(ostream& out, const Item* const item);
bool operator<(const Item& item1, const Item& item2);
bool operator<(const ItemPtr& itemptr1, const ItemPtr& itemptr2);



