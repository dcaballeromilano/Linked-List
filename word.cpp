#include <iostream>
#include <string>
#include "word.h"

using namespace std;
/*
int WORD::Length() const

This function determines the length of the current word
*/
int WORD::Length() const
{
	string s;
	//in>>s;

	if (front == 0)
	{
		return 0;
	}
	else
	{
		character *p = front;
		int count = 0;

		while (p != 0)
		{
			count++;
			p = p->next;
		}
		return count;
	}
}
/*
ostream & operator<<(ostream & out, const WORD & w)

This function overloads the insertion operator in order to print a word
*/
ostream & operator<<(ostream & out, const WORD & org)
{
	character *temp = new character();
	temp = org.front;

	while (temp != 0)
	{
		out << temp->symbol;
		temp = temp->next;
	}
	return out;
}
/*
void WORD::operator=(const string & s)

This function overloads the assignment operator in order to take a string and assign
its value to the current object
*/
void WORD::operator=(const string & s)
{
	if (s.length() != 0)
	{
		this->front = new character();
		this->back = this->front;

		for (int i = 0; i < (s.length() - 1); i++)
		{
			this->back->symbol = s[i];
			this->back->next = new character();
			this->back = this->back->next;
		}
		this->back->symbol = s[s.length() - 1];
		this->back->next = 0;
	}
	else
		this->front = this->back = 0;
}
/*
WORD & WORD::operator=(const WORD & w)

This function overloads the assignment operator with chaining in order to take an object word
as an argument and assign its value to the current object.
*/
WORD & WORD::operator=(const WORD & org)
{
	WORD k;
	if (!org.IsEmpty())
	{
		k.front = new character();
		k.back = k.front;
		character *temp = org.front;

		while (temp != org.back)
		{
			k.back->symbol = temp->symbol;
			k.back->next = new character();
			k.back = k.back->next;
			temp = temp->next;
		}
		k.back->symbol = temp->symbol;
		k.back->next = 0;
	}

	return k;
}
/*
void WORD::operator+(const WORD & B)

This function overloads the "+" operator without chaining in order to add the word in the argument
to the back of the current object
*/
void WORD::operator+(const WORD & B)
{
	if (this->IsEmpty() && !B.IsEmpty())
	{
		this->front = B.front;
		this->back = B.back;
	}
	else if (!B.IsEmpty())
	{
		this->back->next = B.front;
		this->back = B.back;
	}
}
/*
WORD::WORD(const string & s)

this is the explicit value constructor, it takes a string and converts it to a word
*/
WORD::WORD(const string & s)
{
	if (s.length() != 0)
	{
		this->front = new character();
		this->back = this->front;

		for (int i = 0; i < (s.length() - 1); i++)
		{
			this->back->symbol = s[i];
			this->back->next = new character();
			this->back = this->back->next;
		}
		this->back->symbol = s[s.length() - 1];
		this->back->next = 0;
	}
	else
		this->front = this->back = 0;
}
/*
WORD::WORD(const WORD & org)

This is the copy constructor, it is used during a call by value, return, or initialization
or declaration of a word object
*/
WORD::WORD(const WORD & org)
{
	if (!org.IsEmpty())
	{
		this->front = new character();
		this->back = this->front;
		character *temp = org.front;

		while (temp != org.back)
		{
			this->back->symbol = temp->symbol;
			this->back->next = new character();
			this->back = this->back->next;
			temp = temp->next;
		}
		this->back->symbol = temp->symbol;
		this->back->next = 0;
	}
	else
		this->front = this->back = 0;
}
/*
WORD::~WORD()

This is the destructor which de allocates memory allocated to a word
*/
WORD::~WORD()
{
	cout << "destructor called\n";
	while (this->front != 0)
	{
		character *temp = this->front->next;
		delete(this->front);
		this->front = temp;
	}
	this->back = 0;
}
/*
bool WORD::IsEqual(const WORD & B)

This checks if two word objects are equal
*/
bool WORD::IsEqual(const WORD & B)
{
	if (this->Length() != B.Length() || this->front->symbol != B.front->symbol || this->back->symbol != B.back->symbol)
		return false;
	character *temp1 = this->front;
	character *temp2 = B.front;

	while (temp1 != 0 || temp2 != 0)
	{
		if ((temp1->symbol != temp2->symbol))
			return false;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return true;
}
