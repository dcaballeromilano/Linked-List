#pragma once
//////////////////////////////////////////////////////////////////////////////////////////// 
/*Name: Daniel Caballero   Z# : 23439643
Course : Date Structures and Algorithm Analysis(COP3530)
Professor : Dr.Lofton Bullard
Due Date : 06 / 30 / 2018  Due Time : 11 : 59pm
Total Points : 25
Assignment 4 : Word program
Description : This program does a variety of things relating to linked-lists, including convertering a string to linked lists, 
and also verifying that two lists are equal to each other, also it removes certain parts of the lists.
Various operators are overloaded in this program and their functionality is tested as well.
*/////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>

using namespace std;

#ifndef WORD_H
#define WORD_H

class character
{
public:
	char symbol;
	character *next;
};

class WORD
{
public:
	bool IsEmpty() const { return front == 0; }

	int Length() const; //Length: Determines the length of the word A; remember A is the current object;

	friend ostream & operator<<(ostream & out, const WORD & w); //Overload the insertion operator as a friend function with chaining to print a word A;

	void operator=(const string & s);// Overload the assignment operator as a member function to take a
									 //string (C-style or C++ string, just be consistent in your implementation) as an argument and
									 //assigns its value to A, the current object;

	WORD & operator=(const WORD & w); // Overload the assignment operator as a member function with chaining to take a word
									  //object as an argument and assigns its value to A, the current object;

	void operator+(const WORD & B); //Overload the ë+î operator as a member function without chaining to add word B
									//(adds the set of symbols that makep B's linked list to the back of A's linked list) to the back of word A;
									//remember A is the current object;

	WORD() { front = back = 0; }     //The default constructor will initialize your state variables.
									 //The front of the linked list is initially set to NULL or 0; this implies a non-header node
									 //implementation of the link list.

	WORD(const string & s); //Explicit-value constructor: This constructor will have one argument;
							//a C-style string or a C++ string representing the word to be created;

	WORD(const WORD & org);   // Copy Constructor: Used during a call by value, return, or initialization/declaration of a word object;

	~WORD();                   //Destructor: The destructor will de-allocate all memory allocated for the word. Put the message
							   //"destructor called\n" inside the body of the destructor.

	bool IsEqual(const WORD & B); // Returns true if two word objects are equal; otherwise false; remember A is the current

	//void Remove(WORD & Org);//Deletes the first occurrence of word B (removes the first set of characters that makeup B's linked
	//						//list from A's linked list) from word A if it is there; remember A is the current object;

	//void RemoveALL(WORD & Org);//Removes all occurrences of word B (removes each set of characters that makeup B's linked
	//						   //list from A's linked list) from word A if it is there; remember A is the current object;

private:
	character *front, *back;
};

#endif