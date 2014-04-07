#include "memoryleakdetect.h"		// needs to be first #include in the .cpp file
#include "Item.h"

//static class methods	
const string Item::TITLE = "title";
const string Item::KEYWORDS = "keywords";
string Item::classMediaType = "";

string Item::getMediaTypeName() 
{
	return "";
}

Item::Item(const string& newTitle, const string& newCreator) :
title(newTitle), creator(newCreator)
{

}

Item::Item(const string& newTitle, const string& newCreator, const int& newDivisions) :  
title(newTitle),creator(newCreator),contentDivisions(newDivisions)
{

}

Item::Item(const string& newTitle, const string& newCreator, const int& newDivisions, const int& nKeywords, ...) :
title(newTitle), creator(newCreator),contentDivisions(newDivisions)
{
	va_list varargs;
	va_start(varargs, nKeywords);

	for (int i = 0; i < nKeywords; i++) 
	{
		keyWords.insert(va_arg(varargs, string));	
	}
	va_end(varargs);
}

Item::Item(const string& newTitle) :
title(newTitle)
{

}

Item::Item()
{

}

Item::~Item()
{
	
}

bool Item::hasCreator(const string& creatorName) const 
{
	if (creator == creatorName) 
	{
		return true;
	} else 
	{
		return false;
	}
}

string Item::getCreator() const 
{
	return creator;
}

string Item::getTitle() const 
{
	return this->title;
}

set<string> Item::getKeywords() const 
{
	return this->keyWords;
}

bool Item::hasKeyword(const string& keyWord) const 
{
	set<string>::iterator keyIteration;

	keyIteration = keyWords.find(keyWord); 
	if (keyIteration == keyWords.end()) 
	{ 
		return false;
	} else 
	{
		return true;
	}	
}

string Item::getClassHeader() const 
{
	string retValue = "-" + this->getMediaType() + "-";
	return retValue;
}

string Item::getCreatorAndDivisions() const 
{ 
	char* dChar = new char[10]; 
	string retValue = "";

	_itoa(getContentDivisions(), dChar, 10); 
	retValue += getEntryRow(this->getCreatorType(), getCreator()) + '\n';
	retValue += getEntryRow("# " + this->getDivisionType(), string(dChar));

	delete [] dChar;
	dChar = 0;

	return retValue;
}

int Item::getContentDivisions() const 
{
	return this->contentDivisions;
}

string Item::getTitleKeywords() const 
{
	string retValue = "";
	retValue += getEntryRow(TITLE, getTitle()) + "\n";
	retValue += getEntryRow(KEYWORDS, printKeywords()) + "\n";

	return retValue; 
}

string Item::printKeywords() const 
{
	set<string>::iterator castIteration;
	unsigned int count = 0;
	string retValue = "";

	for (castIteration = keyWords.begin(); castIteration != keyWords.end(); castIteration++) 
	{
		retValue += *castIteration;
		count++;
		if (count < keyWords.size()) 
		{ 
			retValue += ", "; 
		}
	}
	return retValue;
}

string Item::getEntryRow(string hColumn, string& cColumn) const 
{
	string retValue;
	stringstream strStream;
	string endl1 = hColumn + ":";

	strStream << setw(FORMAT_SPACES) << left << endl1;

	retValue = strStream.str();
	retValue += cColumn;

	return retValue;
}

void Item::setCreator(const string& newCreator) 
{
	creator = newCreator;
	return;
}

void Item::setTitle(const string& newTitle)
{
	title = newTitle;
	return;
}

void Item::setKeywords(const set<string>& newKeyWords) 
{
	return;
}

void Item::addKeyword(const string& wordToAdd) 
{
	keyWords.insert(wordToAdd);
	return;
}

void Item::addKeywords(const set<string>& newKeyWords) 
{
	return;
}

//compare
bool operator<(const Item& item1, const Item& item2) 
{
	if (item1.getTitle() < item2.getTitle()) 
	{
		return true;
	} else 
	{
		return false;
	}
}

bool operator<(const ItemPtr& itemptr1, const ItemPtr& itemptr2)
{
	if (itemptr1.getPtr()->getTitle() < itemptr2.getPtr()->getTitle()) 
	{
		return true;
	} else 
	{
		return false;
	}
}

ostream& operator<<(ostream& out, const Item* const item)
{
	string outStr = item->toString();
	out << outStr;
	return out;
}