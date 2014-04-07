#include "memoryleakdetect.h"		// needs to be first #include in the .cpp file
#include "MusicAlbum.h"

//static members
const string MusicAlbum::CREATOR_TYPE = "band";
const string MusicAlbum::MEMBERS = "members";
const string MusicAlbum::MEDIA_TYPE = "Music Album";
const string MusicAlbum::DIVISION_TYPE = "songs";

MusicAlbum::MusicAlbum(void) : 
Item()
{

}

MusicAlbum::MusicAlbum(const string& newTitle) : 
Item(newTitle)
{

}

MusicAlbum::MusicAlbum(const string& newTitle, const string& newCreator, const int& newDivisions) : 
Item(newTitle, newCreator, newDivisions)
{

}

MusicAlbum::~MusicAlbum(void)
{

}

string MusicAlbum::toString() const 
{
	string retValue = this->getClassHeader() + "\n";
	retValue += this->getCreatorAndDivisions() + "\n";
	retValue += getEntryRow(getMemberType(), printMembers()) + "\n";
	retValue += this->getTitleKeywords();

	return retValue;
}

string MusicAlbum::getMediaTypeName() 
{
	return MEDIA_TYPE;
}

void MusicAlbum::initializeMembers() 
{

}

string MusicAlbum::getCreatorType() const 
{
	return MusicAlbum::CREATOR_TYPE;
}

string MusicAlbum::getMemberType() const 
{
	return MusicAlbum::MEMBERS;
}

string MusicAlbum::getMediaType() const 
{
	return MusicAlbum::MEDIA_TYPE;
}

string MusicAlbum::getDivisionType() const 
{
	return MusicAlbum::DIVISION_TYPE;
}

bool MusicAlbum::hasBandMember(const string& hasTheMember) const 
{
	set<string>::iterator retValue;
	retValue = bandMembers.find(hasTheMember);

	if (retValue == bandMembers.end()) 
	{
		return false;
	} else 
	{
		return true;
	}
}

string MusicAlbum::getBand() const 
{
	return getCreator();
}

void MusicAlbum::setBand(const string& newBand) 
{
	setCreator(newBand);
}

set<string> MusicAlbum::getBandMembers() const 
{
	return bandMembers;
}

void MusicAlbum::addBandMembers(const int& nArgs, ...) 
{
	va_list varargs;
	va_start(varargs, nArgs);
	string theBandMembers;

	for (int i = 0; i < nArgs; i++) 
	{
		theBandMembers = va_arg(varargs, string);
		bandMembers.insert(theBandMembers);
	}

	va_end(varargs);
}

void MusicAlbum::setBandMembers(const set<string>& newBandMembers) 
{
	this->bandMembers = newBandMembers;
	return;
}

string MusicAlbum::printMembers() const 
{
	set<string>::iterator memberIteration;
	unsigned int count = 0;
	string retValue = "";

	for (memberIteration = bandMembers.begin(); memberIteration != bandMembers.end(); memberIteration++) 
	{
		retValue += *memberIteration;
		count++;
		if (count < bandMembers.size()) 
		{  
			retValue += ", "; 
		}
	}

	return retValue;
}
