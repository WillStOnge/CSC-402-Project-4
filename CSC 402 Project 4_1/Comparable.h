/*
File Name: Comparable.h
Author: Will St. Onge
Course: CSC 402
Date: 
*/

#pragma once

#include <iostream>

using namespace std;

template<typename T>
class Comparable
{
	/*  Assumptions:
		1. The relational operator T's are the same type.
		2. T has an override for the insertion operator.
		3. T cleans itself up properly (Proper deconstructor).  */
public:
	// Constructors
	explicit Comparable(const T& init = T()) : value(init) { }
	Comparable(const Comparable<T>& init) : value(init.value) { }

	// Destructor
	~Comparable() 
	{ 
		delete value;
	}

	// Copy assignment operator
	Comparable<T>& operator=(const Comparable<T>& rhs)
	{
		value = rhs.value;
		return *this;	
	}
	
	// Helper function for the insertion operator
	void print(ostream& out = cout) const
	{
		out << value;
	}

	// Relational operator implementations
	bool operator==(const Comparable<T>& rhs) const
	{
		return value == rhs.value;
	}

	bool operator<(const Comparable<T>& rhs) const
	{
		return value < rhs.value;
	}

	bool operator>(const Comparable<T>& rhs) const
	{
		return value > rhs.value;
	}

	bool operator!=(const Comparable<T>& rhs) const
	{
		return value != rhs.value;
	}

	bool operator<=(const Comparable<T>& rhs) const
	{
		return value <= rhs.value;
	}

	bool operator>=(const Comparable<T>& rhs) const
	{
		return value >= rhs.value;
	}

private:
	T value;
};

// Non member insertion operator override
template<typename T>
ostream& operator<<(ostream& out, const Comparable<T>& rhs)
{
	rhs.print(out);
	return out;
}