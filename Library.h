// do not remove any of the function prototypes from this class definition

#pragma once
#include <iterator>
#include <map>
#include <set>
#include <string>
#include "Movie.h"
#include "MusicAlbum.h"
#include "Book.h"
#include "Item.h"

using namespace std;

// C++ Standard Library definitions for containers you may need
typedef set<string>				StringSet;
typedef set<ItemPtr>			ItemSet;				// see comment in Item.h about use of ItemPtr
typedef map<string,ItemSet*>	StringToItemSetMap;

class Library
{
public:
	//const
	Library(); 
	Library(const Library*& otherLib);
	virtual ~Library();
	void testIndexes(StringSet& testStringSet); 

	// general functions
	void addKeywordsForItem(const Item* const item, int nKeywords, ...);
	const ItemSet* itemsForKeyword(const string& keyword);
	Library clone(); //for deep copy
	void testForKeyword(string parameter);	

	// book-related functions
	const ItemSet* booksByAuthor(const string& author) ;
	const ItemSet* books() ;	
	const Item* addBook(const string& title, const string& author, const int nPages);

	// music-related functions
	const ItemSet* musicByBand(const string& band) ;
	const ItemSet* musicByMusician(const string& musician) ;
	const ItemSet* musicAlbums() ;	
	const Item* addMusicAlbum(const string& title, const string& band, const int nSongs);
	void addBandMembers(const Item* const musicCD, int nBandMembers, ...);

	// movie-related functions
	const ItemSet* moviesByDirector(const string& director) ;
	const ItemSet* moviesByActor(const string& actor) ;
	const ItemSet* movies() ;	
	const Item* addMovie(const string& title, const string& director, const int nScenes);
	void addCastMembers(const Item* const movie, const int nCastMembers, ...);

private:
	map<string, StringSet>	artistIndex;
	map<string, StringSet>	memberIndex;
	map<string, StringSet>	keywordIndex;
	map<string, StringSet>	mediaIndex;
	map<string, ItemPtr>	itemCollection;

	void copyMap(map<string, StringSet*>*& source, map<string, StringSet*>*& dest);
	void copyItemColl(const Library*& otherLib);
	void copyCurrentQuery(const Library*& otherLib);

	void addLookupIndex(map<string, StringSet>& placeToAdd, const string& itemTitle, StringSet& inputList); 
	void addKeywordIndex(Item*& newItem);
	void addMemberIndex(MusicAlbum*& newAlbum);
	void addMemberIndex(Movie*& newMovie);
	void addMediaIndex(Item*& newItem);
	void addArtistIndex(Item*& newItem);
	void initializeIndexes();

	const ItemSet*				qPtr;	
	ItemSet					currQuery;
	const ItemSet* searchIndex1(map<string, StringSet>& searchIndex, const string& searchKey) ;
	const ItemSet* searchIndex2(map<string, StringSet>& searchIndex1, const string& searchKey1, map<string, StringSet>& searchIndex2, const string& searchKey2) ;
	Item* addLibItem(const string& title, const string& author, const int& nPages, const int& nArgs, ...);
	//removal 
	bool removeIndexes(Item*& outItem);		
	bool removeLibraryIndex(map<string, StringSet>& libIndex, Item*& outItem);	
};