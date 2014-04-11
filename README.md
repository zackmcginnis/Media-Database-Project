Media-Database-Project
======================

C++ project for organizing a media library database

Database of Media Items

In this assignment, you will implement a database for a library. This library stores three types of items:

books
music albums
movies
You will start with asgmt04.zip, which contains a Visual Studio 2010 project.

Library.h contains the member functions that are used by Asgmt04.cpp. As provided, Library.cpp contains a stub implementation for each of these functions. (A “stub” is a function definition with no useful code in it.)

Once you have properly implemented the library functionality, your code’s output should be identical to the contents of asgmt04.output.txt (except for your name instead of the instructor’s name). This will require all of your output lists (including keywords, band members, movie casts) to be sorted alphabetically. Lists of Item instances should be sorted by title. (The required output is exactly the same as the required output for Assignment 3.)

Make sure to place all of your printing code in the appropriate class, as defined by object-oriented design in the context of C++. You should accomplish this by using polymorphism combined with overloading operator<<.

You should use the C++ Standard Library where appropriate – do not reinvent that wheel for this assignment.

You should code for “high performance,” meaning fast access. This means that you should choose components of the C++ Standard Library that support the highest possible speed consistent with the tasks your code needs to perform. To put this another way, do not do linear searches when a faster method is available in the C++ Standard Library. For example, the set of items for a particular keyword should not be collected by a linear search through all of the items contained in the library.

The items included in the library database reflect either the instructor’s superior taste, his advanced age, or perhaps both.

Code To Start With
The code for you to start with is provided as a Visual Studio 2010 project. To get this project, download and expand asgmt04.zip. The project can also be used in Visual C++ 2010 Express.

Add code to the definition and implementation files as needed. You can add public and private members, but do not remove any of the public members that are already there. Also, make no changes to Asgmt04.cpp other than to have it print your name instead of the instructor’s name.

Printed Output
Your code’s printed output should be identical to the contents of asgmt04.output.txt, a file that’s provided as part of this lab. “Identical” means the Linux utility diff will find no differences between your code’s output and the provided file when called with flags: -w -B. In other words, the sequence of non-whitespace characters in your output has to be identical to what’s in the provided file, but differences in whitespace will be ignored. You are still required to produce output that lines up with itself properly, as the provided file does.

The required output is exactly the same as the required output for Assignment 3.

Memory Leaks
Your code is required to run in Visual Studio 2010 Express without memory leaks. The starter code for this project includes support for Visual Studio’s memory leak detection feature.

Initialization Lists
The constructors in your code should use initialization lists to the maximum extent possible. Points will be deducted where this is not done.

Here is a class definition:

class SomeClass
{
    ...
private:
    int     dataMember1;
    int     dataMember2;
}
Here is a constructor for this class that does not use initialization lists:

SomeClass::SomeClass(int dataMember1, int dataMember2)
{
    this->dataMember1 = dataMember1;
    this->dataMember2 = dataMember2;
}
And here is one that does use initialization lists:

SomeClass::SomeClass(int dataMember1, int dataMember2) :
    dataMember1(dataMember1), dataMember2(dataMember2)
{
}
An initialization list consists of comma-separated items between the : and the {. Each of these items is of the form:

dataMemberName(value)
Each item sets the named data member to the value in the parentheses. In the SomeClass constructor above, each of the two initialization list items sets its data member to the constructor argument named inside the parentheses. This is weird-looking syntax, but it is standard usage in C++.












