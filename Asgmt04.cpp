#include "memoryleakdetect.h"		// needs to be first #include in the .cpp file

// make no changes to this code, except to have it
// print out your actual name instead of "I. Forgot"

#include <iostream>
#include "Library.h"

using namespace std;

static Library	*library;

static void printItemSet(ostream& out, const ItemSet *itemSet)
{
    if (itemSet != NULL && itemSet->size() > 0)
		for (ItemSet::const_iterator i = itemSet->begin(); i != itemSet->end(); i++)
			out << i->getPtr();
	else
		out << "none" << endl << endl;
}

int main(int argc, char **argv)
{
    ostream&	out(cout);
    const Item	*item;

    cout << "CS261 - Assignment 4 - Zack McGinnis" << endl << endl;

	// create library instance
	library = new Library();

    // add items to library
    cout << ">>>>>> adding items to library:" << endl << endl;
    item = library->addBook("The Curious Incident of the Dog in the Night-Time", "Mark Haddon", 240);
    if (item != NULL) {
        library->addKeywordsForItem(item, 2, "autism", "Asperger's Syndrome");
		cout << item << endl;
        }
    item = library->addBook("Starship Troopers", "Robert A. Heinlein", 325);
    if (item != NULL) {
        library->addKeywordsForItem(item, 3, "science fiction", "war", "weapons");
		cout << item << endl;
        }
    item = library->addBook("The Moon Is A Harsh Mistress", "Robert A. Heinlein", 389);
    if (item != NULL) {
        library->addKeywordsForItem(item, 3, "science fiction", "moon", "social structures");
		cout << item << endl;
        }
    item = library->addBook("Fear and Loathing in Las Vegas", "Hunter S. Thompson", 224);
    if (item != NULL) {
        library->addKeywordsForItem(item, 3, "sixties", "gonzo", "drugs");
		cout << item << endl;
        }
    item = library->addMusicAlbum("Europe In '72", "Grateful Dead", 12);
    if (item != NULL) {
        library->addKeywordsForItem(item, 4, "acid rock", "sixties", "jam bands", "cosmic");
        library->addBandMembers(item, 7, "Jerry Garcia", "Bill Kreutzman", "Keith Godcheaux",
										 "Donna Godcheaux", "Phil Lesh", "Bob Weir", "Mickey Hart");
		cout << item << endl;
        }
    item = library->addMusicAlbum("Steal Your Face", "Grateful Dead", 12);
    if (item != NULL) {
        library->addKeywordsForItem(item, 4, "acid rock", "sixties", "jam bands", "cosmic");
        library->addBandMembers(item, 7, "Jerry Garcia", "Bill Kreutzman", "Keith Godcheaux",
										 "Donna Godcheaux", "Phil Lesh", "Bob Weir", "Mickey Hart");
		cout << item << endl;
        }
    item = library->addMusicAlbum("From the Mars Hotel", "Grateful Dead", 12);
    if (item != NULL) {
        library->addKeywordsForItem(item, 4, "acid rock", "sixties", "jam bands", "cosmic");
        library->addBandMembers(item, 7, "Jerry Garcia", "Bill Kreutzman", "Keith Godcheaux",
										 "Donna Godcheaux", "Phil Lesh", "Bob Weir", "Mickey Hart");
		cout << item << endl;
        } 
	item = library->addMusicAlbum("Don't Let Go", "Jerry Garcia Band", 15);
    if (item != NULL) {
        library->addKeywordsForItem(item, 2, "acid rock", "jam bands");
        library->addBandMembers(item, 4, "Jerry Garcia", "Keith Godcheaux", "Donna Godcheaux", "John Kahn");
		cout << item << endl;
        }
    item = library->addMusicAlbum("Time Out", "Dave Brubeck Quartet", 7);
    if (item != NULL) {
        library->addKeywordsForItem(item, 3, "jazz", "unusual time signatures", "fifties");
        library->addBandMembers(item, 4, "Dave Brubeck", "Paul Desmond", "Joe Morello", "Eugene Wright");
		cout << item << endl;
        }
    item = library->addMusicAlbum("Newborn Light", "Urszula Dudziak", 7);
    if (item != NULL) {
        library->addKeywordsForItem(item, 3, "jazz", "scat singing", "cosmic");
        library->addBandMembers(item, 2, "Urszula Dudziak", "Adam Makowicz");
		cout << item << endl;
        }
    item = library->addMovie("Lost In Translation", "Sofia Coppola", 14);
    if (item != NULL) {
        library->addKeywordsForItem(item, 3, "Japan", "loneliness", "time");
        library->addCastMembers(item, 2, "Bill Murray", "Scarlett Johansson");
		cout << item << endl;
        }
    item = library->addMovie("Groundhog Day", "Harold Ramis", 14);
    if (item != NULL) {
        library->addKeywordsForItem(item, 3, "newscaster", "groundhog", "time");
        library->addCastMembers(item, 2, "Bill Murray", "Andie MacDowell");
		cout << item << endl;
        }
    item = library->addMovie("Monterey Pop", "D.A. Pennebaker", 14);
    if (item != NULL) {
        library->addKeywordsForItem(item, 3, "sixties", "rock", "concert");
        library->addCastMembers(item, 5, "Jimi Hendrix", "Janis Joplin", "Hugh Masakela",
										 "Jefferson Airplane", "Country Joe and the Fish");
		cout << item << endl;
        }

	cout << ">>>>>> printing items from library" << endl << endl;

    // print books, music albums, movies
    cout << ">>> books:" << endl << endl;
    printItemSet(out, library->books());
    cout << ">>> music albums:" << endl << endl;
    printItemSet(out, library->musicAlbums());
    cout << ">>> movies:" << endl << endl;
    printItemSet(out, library->movies());

    // print items for keyword
    cout << ">>> items for keyword: science fiction" << endl << endl;
    printItemSet(out, library->itemsForKeyword("science fiction"));
    cout << ">>> items for keyword: jazz" << endl << endl;
    printItemSet(out, library->itemsForKeyword("jazz"));
    cout << ">>> items for keyword: cosmic" << endl << endl;
    printItemSet(out, library->itemsForKeyword("cosmic"));
    cout << ">>> items for keyword: autism" << endl << endl;
    printItemSet(out, library->itemsForKeyword("autism"));
    cout << ">>> items for keyword: sixties" << endl << endl;
    printItemSet(out, library->itemsForKeyword("sixties"));
    cout << ">>> items for keyword: time" << endl << endl;
    printItemSet(out, library->itemsForKeyword("time"));
    cout << ">>> items for keyword: fifties" << endl << endl;
    printItemSet(out, library->itemsForKeyword("fifties"));
    cout << ">>> items for keyword: forties" << endl << endl;
    printItemSet(out, library->itemsForKeyword("forties"));
	cout << endl << endl;

    // items for artist
    cout << ">>> books by Robert A. Heinlein:" << endl << endl;
    printItemSet(cout, library->booksByAuthor("Robert A. Heinlein"));
    cout << ">>> books by Mark Haddon:" << endl << endl;
    printItemSet(cout, library->booksByAuthor("Mark Haddon"));
    cout << ">>> music by the Grateful Dead:" << endl << endl;
    printItemSet(out, library->musicByBand("Grateful Dead"));
    cout << ">>> music by Kiss:" << endl << endl;
    printItemSet(out, library->musicByBand("Kiss"));
    cout << ">>> movies by Sofia Coppola:" << endl << endl;
    printItemSet(out, library->moviesByDirector("Sofia Coppola"));
    cout << ">>> music by Jerry Garcia:" << endl << endl;
    printItemSet(out, library->musicByMusician("Jerry Garcia"));
    cout << ">>> movies with Bill Murray:" << endl << endl;
    printItemSet(out, library->moviesByActor("Bill Murray"));
	cout << endl << endl;

	delete library;

	// report on memory leaks in the Output Window
	#ifdef _DEBUG
	if (argc == 2) {
		_CrtSetReportMode( _CRT_WARN , _CRTDBG_MODE_FILE );
		_CrtSetReportFile( _CRT_WARN , _CRTDBG_FILE_STDERR );
		}
	_CrtDumpMemoryLeaks();
	#endif

	return 0;
}
