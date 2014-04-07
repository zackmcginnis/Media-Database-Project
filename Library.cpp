#include "memoryleakdetect.h"		// needs to be first #include in the .cpp file
#include <algorithm>
#include <set>
#include <vector>
#include <cstdarg>					
#include <iostream>
#include "Library.h"

//constructors/dest/test
Library::Library() : qPtr(&currQuery)
{
	initializeIndexes();
}

Library::Library(const Library*& otherLib) 
{
	
}

Library::~Library()
{
	map<string, ItemPtr>::iterator	deleteIteration;
	Item*							deleteItem;

	for (deleteIteration = itemCollection.begin(); deleteIteration != itemCollection.end(); deleteIteration++) 
	{
		deleteItem = deleteIteration->second.getPtr();	
		delete deleteItem;
		deleteItem = 0;
	}

	if (qPtr != 0) 
	{
		delete qPtr;
		qPtr = 0;
	}
}

void Library::testIndexes(StringSet& testStringSet) 
{
	vector<int> v(10);
	vector<int>::iterator test;
	int first[] = {5, 10, 15, 20, 25};
	int second[] = {50, 40, 30, 20, 10};

	sort (first, first+5);
	sort (second, second+5);

	test = set_intersection(first, first+5, second, second+5, v.begin());
}

// general functions
void Library::addKeywordsForItem(const Item* const item, int nKeywords, ...)
{
	map<string, ItemPtr>::iterator searchIteration;
	map<string, StringSet>::iterator keywordIteration;

	pair<string, StringSet> keywordInsValue;
	va_list					keywords;
	char*					keyword; 
	string					keyString;
	Item*					foundItem; 
	string					searchItem = item->getTitle();

	searchIteration = itemCollection.find(searchItem);

	if (searchIteration != itemCollection.end()) 
	{
		foundItem = searchIteration->second.getPtr();
		va_start(keywords, nKeywords);

		for (int i = 0; i < nKeywords; i++) 
		{
			keyword = va_arg(keywords, char*);
			keyString = string(keyword);
			foundItem->addKeyword(keyString);

			keywordIteration = keywordIndex.find(keyString); 

			if (keywordIteration != keywordIndex.end()) 
			{ 
				keywordIteration->second.insert(foundItem->getTitle());
			} else 
			{
				keywordInsValue = pair<string, StringSet>(keyString, StringSet());
				keywordIndex.insert(keywordInsValue);
				keywordIndex.at(keyString).insert(foundItem->getTitle());
			}				
		}
		va_end(keywords);
	}
}

void Library::testForKeyword(string parameter) 
{
	string keyString = string(parameter);
	map<string, StringSet>::iterator keywordIteration;
	keywordIteration = keywordIndex.find(keyString);
}

const ItemSet* Library::itemsForKeyword(const string& keyword) 
{	
	map<string, StringSet> sIndex1 = keywordIndex;
	return searchIndex1(sIndex1, keyword);
}

Library Library::clone() 
{
	return *this;
}

// book-related functions
const Item* Library::addBook(const string& title, const string& author, const int nPages)
{
	Item* newBook = new Book(title, author, nPages);
	if (itemCollection.count(newBook->getTitle()) == 0) 
	{
		itemCollection.insert(pair<string, ItemPtr>(title, newBook));
	} else 
	{
		return 0;
	}

	if (itemCollection.count(newBook->getTitle()) == 0) 
	{
		return 0;
	} else 
	{
		addMediaIndex(newBook);
		addArtistIndex(newBook);
		return newBook;
	}
}

const ItemSet* Library::booksByAuthor(const string& author) 
{	
	map<string, StringSet> sIndex1 = mediaIndex;
	map<string, StringSet> sIndex2 = artistIndex;

	return searchIndex2(sIndex1, Book::getMediaTypeName(), sIndex2, author);	
}

const ItemSet* Library::books() 
{
	map<string, StringSet>	mIndex = mediaIndex;
	return searchIndex1(mIndex, Book::getMediaTypeName());	
}

// music-related functions
const Item* Library::addMusicAlbum(const string& title, const string& band, const int nSongs)
{
	Item* newAlbum = new MusicAlbum(title, band, nSongs);

	if (itemCollection.count(newAlbum->getTitle()) == 0) 
	{
		itemCollection.insert(pair<string, ItemPtr>(title, newAlbum));
	} else 
	{
		return 0;
	}

	if (itemCollection.count(newAlbum->getTitle()) == 0) 
	{
		return 0;
	} else 
	{
		addMediaIndex(newAlbum);
		addArtistIndex(newAlbum);

		return newAlbum;
	}
}

void Library::addBandMembers(const Item* const musicAlbum, const int nBandMembers, ...)
{
	map<string, ItemPtr>::iterator searchIteration;
	map<string, StringSet>::iterator memberIteration;

	pair<string, StringSet> memberInsValue;
	va_list					memberArgs;
	string					memberArg;
	char*					charArg; 
	string					keyString;
	Item*					foundItem; 
	StringSet				outputMembers;
	string					searchItem = musicAlbum->getTitle();

	searchIteration = itemCollection.find(musicAlbum->getTitle());

	if (searchIteration != itemCollection.end()) 
	{
		foundItem = searchIteration->second.getPtr();
		va_start(memberArgs, nBandMembers);
		for (int i = 0; i < nBandMembers; i++) 
		{
			charArg = va_arg(memberArgs, char*);
			memberArg = string(charArg);
		
			outputMembers.insert(memberArgs);
			memberIteration = memberIndex.find(memberArg);

			if (memberIteration != memberIndex.end()) 
			{ 
				memberIteration->second.insert(foundItem->getTitle());
			} else
			{ 
				memberInsValue = pair<string, StringSet>(memberArg, StringSet());
				memberIndex.insert(memberInsValue);
				memberIndex.at(memberArg).insert(foundItem->getTitle());
			}				
		}
		((MusicAlbum*)foundItem)->setBandMembers(outputMembers);
		va_end(memberArgs);
	}
}

const ItemSet* Library::musicByBand(const string& band) 
{
	map<string, StringSet> sIndex1 = mediaIndex;
	map<string, StringSet> sIndex2 = artistIndex;
	return searchIndex2(sIndex1, MusicAlbum::getMediaTypeName(), sIndex2, band);	
}

const ItemSet* Library::musicByMusician(const string& musician) 
{
	map<string, StringSet> sIndex1 = mediaIndex;
	map<string, StringSet> sIndex2 = memberIndex;
	return searchIndex2(sIndex1, MusicAlbum::getMediaTypeName(), sIndex2, musician);
}

const ItemSet* Library::musicAlbums() 
{
	map<string, StringSet> sIndex1 = mediaIndex;
	return searchIndex1(sIndex1, MusicAlbum::getMediaTypeName());
}

// movie-related functions
const Item* Library::addMovie(const string& title, const string& director, const int nScenes)
{
	Item* newMovie = new Movie(title, director, nScenes);
	if (itemCollection.count(newMovie->getTitle()) == 0) 
	{
		itemCollection.insert(pair<string, ItemPtr>(title, newMovie));
	} else 
	{
		return 0;
	}

	if (itemCollection.count(newMovie->getTitle()) == 0) 
	{
		return 0;
	} else 
	{
		addMediaIndex(newMovie);
		addArtistIndex(newMovie);
		return newMovie;
	}
}

void Library::addCastMembers(const Item* const movie, const int nCastMembers, ...)
{
	map<string, ItemPtr>::iterator searchIteration;
	map<string, StringSet>::iterator memberIteration;

	pair<string, StringSet> memberInsValue;
	va_list					memberArgs;
	string					memberArg;
	char*					charMember; 
	Item*					foundItem; 
	StringSet				outputMembers;
	string					searchItem = movie->getTitle();

	searchIteration = itemCollection.find(movie->getTitle());

	if (searchIteration != itemCollection.end()) 
	{
		foundItem = searchIteration->second.getPtr();
		va_start(memberArgs, nCastMembers);

		for (int i = 0; i < nCastMembers; i++) 
		{
			charMember = va_arg(memberArgs, char*);
			memberArg = string(charMember);			
			outputMembers.insert(memberArg);
			memberIteration = memberIndex.find(memberArg); 

			if (memberIteration != memberIndex.end()) 
			{ 
				memberIteration->second.insert(foundItem->getTitle());
			} else 
			{
				memberInsValue = pair<string, StringSet>(memberArg, StringSet());
				memberIndex.insert(memberInsValue);
				memberIndex.at(memberArg).insert(foundItem->getTitle());
			}				
		}
		((Movie*)foundItem)->setCast(outputMembers);
		va_end(memberArgs);
	}
}

const ItemSet* Library::moviesByDirector(const string& director) 
{
	map<string, StringSet> sIndex1 = mediaIndex;
	map<string, StringSet> sIndex2 = artistIndex;
	return searchIndex2(sIndex1, Movie::getMediaTypeName(), sIndex2, director);
}

const ItemSet* Library::moviesByActor(const string& actor) 
{
	map<string, StringSet> sIndex1 = mediaIndex;
	map<string, StringSet> sIndex2 = memberIndex;
	return searchIndex2(sIndex1, Movie::getMediaTypeName(), sIndex2, actor);
}

const ItemSet* Library::movies() 
{
	map<string, StringSet> sIndex1 = mediaIndex;
	return searchIndex1(sIndex1, Movie::getMediaTypeName());
}

//others
void Library::copyCurrentQuery(const Library*& otherLib) 
{
	this->currQuery.clear();
	this->currQuery.insert(otherLib->currQuery.begin(), otherLib->currQuery.end());
	return;
}

void Library::copyMap(map<string, StringSet*>*& start, map<string, StringSet*>*& end) 
{
	end->clear();	
	map<string, StringSet*>::iterator sIteration;

	end->insert(start->begin(), start->end());
	return;
}

void Library::copyItemColl(const Library*& otherLib) 
{
	this->itemCollection.clear();
	this->itemCollection.insert(otherLib->itemCollection.begin(), otherLib->itemCollection.end());
	return;
}

//search
const ItemSet* Library::searchIndex1(map<string, StringSet>& searchIndex, const string& searchKey) 
{	
	map<string, StringSet>::iterator	searchIteration;
	ItemSet								retValue;
	StringSet							index1Set; 
	ItemSet::iterator					resultIteration;
	StringSet::iterator					index1Iteration;

	currQuery.clear();
	searchIteration = searchIndex.find(searchKey);
	
	if (searchIteration != searchIndex.end()) 
	{
		index1Set = searchIteration->second;
	}

	for (index1Iteration = index1Set.begin(); index1Iteration != index1Set.end(); index1Iteration++) 
	{
		currQuery.insert(itemCollection.at(*index1Iteration));
	}
	return qPtr;
}

const ItemSet* Library::searchIndex2(map<string, StringSet>& index1, const string& searchKey1, map<string, StringSet>& index2, const string& searchKey2) 
{	
	map<string, StringSet>::iterator	searchIteration1;
	map<string, StringSet>::iterator	searchIteration2;
	ItemSet								retValue;
	StringSet							output; 
	insert_iterator<StringSet>			outIteration(output, output.begin());
	StringSet::iterator					outputIteration;
	StringSet::const_iterator		    setIntersection;
	StringSet							index1Set;
	StringSet							index2Set;
	StringSet::iterator					index1IterationA, index1IterationB, index1IterationC;
	StringSet::iterator					index2IterationA, index2IterationB, index2IterationC;

	currQuery.clear();

	searchIteration1 = index1.find(searchKey1);
	searchIteration2 = index2.find(searchKey2);

	if (searchIteration1 != index1.end()) 
	{
		index1Set = searchIteration1->second;
	}

	if (searchIteration2 != index2.end()) 
	{
		index2Set = searchIteration2->second;
	}

	index1IterationA = index1Set.begin();
	index1IterationB = index1Set.end();
	index2IterationA = index2Set.begin();
	index2IterationB = index2Set.end();

	set_intersection(index1Set.begin(), index1Set.end(), index1Set.begin(), index1Set.end(), outIteration); 

	for (outputIteration = output.begin(); outputIteration != output.end(); outputIteration++) 
	{
		currQuery.insert(itemCollection.at(*outputIteration));
	}
	return qPtr;
}

//add items
void Library::addLookupIndex(map<string, StringSet>& placeToAdd, const string& itemTitle, StringSet& inputList) 
{
	pair<string, StringSet>	    insValue;
	StringSet::iterator		    inputIteration;
	string						currInput;
	StringSet					newStringSet;
	
	inputIteration = inputList.begin();

	while (inputIteration != inputList.end()) 
	{
		currInput = *inputIteration;

		if (placeToAdd.count(currInput) == 0) 
		{
			insValue = pair<string, StringSet>(currInput, StringSet());
			placeToAdd.insert(insValue);
		}

		placeToAdd.at(currInput).insert(itemTitle);
		inputIteration++;
	}
	return;
}

void Library::addArtistIndex(Item*& newItem) 
{
	pair<string, StringSet> insValue;

	if (artistIndex.count(newItem->getCreator()) == 0) 
	{ 
		insValue = pair<string, StringSet>(newItem->getCreator(), StringSet());
		artistIndex.insert(insValue);
	}

	artistIndex.at(newItem->getCreator()).insert(newItem->getTitle());
	return;
}

void Library::addKeywordIndex(Item*& newItem) 
{
	StringSet keywordPtr = newItem->getKeywords();
	addLookupIndex(keywordIndex, newItem->getTitle(), keywordPtr);
	return;
}

void Library::addMemberIndex(MusicAlbum*& newAlbum) 
{
	StringSet memberPtr = newAlbum->getBandMembers();
	addLookupIndex(memberIndex, newAlbum->getTitle(), memberPtr);
	return;
}

void Library::addMemberIndex(Movie*& newMovie) 
{
	StringSet castPtr = newMovie->getCast();
	addLookupIndex(memberIndex, newMovie->getTitle(), castPtr);
	return;
}

void Library::addMediaIndex(Item*& newItem)
{
	pair<string, StringSet> insValue;

	if (mediaIndex.count(newItem->getMediaType()) == 0) 
	{ 
		insValue = pair<string, StringSet>(newItem->getMediaType(), StringSet());
		mediaIndex.insert(insValue);
	}

	mediaIndex.at(newItem->getMediaType()).insert(newItem->getTitle());
	return;
}

void Library::initializeIndexes() 
{
	return;
}

static void deleteMapContents(StringToItemSetMap& s2ism)
{

}

static void deleteItemSetContents(ItemSet& itemSet)
{
	
}

bool Library::removeIndexes(Item*& outItem)
{
	bool removeSuccess = false;

	removeSuccess = removeLibraryIndex(artistIndex, outItem);
	removeSuccess = removeLibraryIndex(memberIndex, outItem);
	removeSuccess = removeLibraryIndex(keywordIndex, outItem);
	removeSuccess = removeLibraryIndex(mediaIndex, outItem);
	return removeSuccess;	
}

bool Library::removeLibraryIndex(map<string, StringSet>& libIndex, Item*& outItem) 
{
	map<string, StringSet>::iterator	libIndexIteration;
	pair<string, StringSet>			nextSet;
	bool removeSuccess	=				true;
	
	for (libIndexIteration = libIndex.begin(); libIndexIteration != libIndex.end(); libIndexIteration++) 
	{
		nextSet = *libIndexIteration;
		libIndex.erase(nextSet.first);
	}

	return removeSuccess;
}