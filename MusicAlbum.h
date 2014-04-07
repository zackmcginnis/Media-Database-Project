#pragma once

#include "item.h"

class MusicAlbum :
	public Item
{
public:

	MusicAlbum(void);
	MusicAlbum(const string& newTitle);
	MusicAlbum(const string& newTitle, const string& newCreator, const int& newDivisions);
	~MusicAlbum(void);

	static string getMediaTypeName();
	
	string toString() const;	
	string getCreatorType() const;
	string getMemberType() const;
	string getMediaType() const;
	string getDivisionType() const;
	
	bool hasBandMember(const string& hasTheMember) const;
	string getBand() const;
	void setBand(const string& newBand);
	set<string> getBandMembers() const;
	void addBandMembers(const int& nArgs, ...);	
	void setBandMembers(const set<string>& newBandMembers);

private:
	static const string CREATOR_TYPE;
	static const string MEMBERS;
	static const string MEDIA_TYPE;
	static const string DIVISION_TYPE;
	
	set<string> bandMembers;
	void initializeMembers();
	string printMembers() const;

};


