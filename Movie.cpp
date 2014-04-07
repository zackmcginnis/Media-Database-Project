#include "memoryleakdetect.h"		// needs to be first #include in the .cpp file
#include "Movie.h"

//static members
const string Movie::CREATOR_TYPE = "director";
const string Movie::MEDIA_TYPE = "Movie";
const string Movie::DIVISION_TYPE = "scenes";
const string Movie::CAST_TYPE = "cast";

string Movie::getMediaTypeName() 
{
	return MEDIA_TYPE;
}

Movie::Movie(void) : 
Item()
{

}

Movie::Movie(const string& movieTitle) : 
Item(movieTitle)
{

}

Movie::Movie(const string& movieTitle, const string& newDirector, const int& newDivisions) : 
Item(movieTitle, newDirector, newDivisions) 
{

}

Movie::Movie(const string& movieTitle, const string& newDirector, const int& newDivisions, const int& nKeywords, ...) : 
cast()
{
	va_list varargs;
	va_start(varargs, nKeywords);
}

Movie::~Movie(void)
{

}

string Movie::toString() const 
{
	string retValue = this->getClassHeader() + "\n";
	retValue += this->getCreatorAndDivisions() + "\n";
	retValue += this->getEntryRow(getCastType(), printCast()) + "\n";
	retValue += this->getTitleKeywords();

	return retValue;
}

bool Movie::hasActor(const string& actorName) const 
{
	set<string>::iterator locateIteration;
	locateIteration = cast.find(actorName);
	if (locateIteration == cast.end()) 
	{
		return false;
	} else 
	{
		return true;
	}
}

string Movie::getCreatorType() const 
{
	return Movie::CREATOR_TYPE;
}

string Movie::getMediaType() const 
{
	return Movie::MEDIA_TYPE;
}

string Movie::getDivisionType() const 
{
	return Movie::DIVISION_TYPE; 
}

string Movie::getCastType() const 
{
	return Movie::CAST_TYPE;
}

bool Movie::hasDirector(const string& directorName) const 
{
	return hasCreator(directorName);
}

set<string> Movie::getCast() const 
{
	return this->cast;
}

void Movie::addCast(const int& nArgs, ...) 
{
	va_list varargs;
	va_start(varargs, nArgs);
	string nextMember;

	for (int i = 0; i < nArgs; i++) 
	{
		nextMember = va_arg(varargs, string);
		cast.insert(nextMember);
	}
	va_end(varargs);
}

void Movie::setCast(const set<string>& newCast) 
{
	cast = newCast;
	return;
}

string Movie::printCast() const 
{
	set<string>::iterator memberIteration;
	unsigned int count = 0;
	string retValue = "";
	
	for (memberIteration = cast.begin(); memberIteration != cast.end(); memberIteration++) 
	{
		retValue += *memberIteration;
		count++;
		if (count < cast.size()) 
		{ 
			retValue += ", "; 
		}
	}

	return retValue;
}