#include "memoryleakdetect.h"		// needs to be first #include in the .cpp file
#include "Book.h"

//static members
const string Book::CREATOR_TYPE = "author";
const string Book::MEDIA_TYPE = "Book";
const string Book::DIVISION_TYPE = "pages";

string Book::getMediaTypeName() 
{
	return MEDIA_TYPE;
}

Book::Book(void) 
{

}

Book::Book(const string& newTitle) : 
Item(newTitle)
{

}

Book::Book(const string& newTitle, const string& newCreator, const int& newDivisions) : 
Item(newTitle, newCreator, newDivisions)
{

}

Book::Book(const string& newTitle, const string& newCreator, const int& newDivisions, const int& nKeywords, ... ) 
{

}

Book::~Book(void) 
{

}

string Book::toString() const 
{
	string retValue = this->getClassHeader() + "\n";
	retValue += this->getCreatorAndDivisions() + "\n";
	retValue += this->getTitleKeywords();
	return retValue;
}

string Book::getCreatorType() const 
{
	return CREATOR_TYPE;
}

string Book::getMediaType() const 
{
	return MEDIA_TYPE;
}

string Book::getDivisionType() const 
{
	return DIVISION_TYPE;
}

bool Book::hasAuthor(const string& authorName) const 
{
	return hasCreator(authorName);
}

string Book::getAuthor() const 
{
	return getCreator();
}

void Book::setAuthor(const string& newAuthor) 
{
	setCreator(newAuthor);
}