#pragma once

#include <sstream>
#include <iostream>
#include <string>

using namespace std;
class Fraction
{
public:

	class Pair
	{
		double first, second;
		static int counter;

	public:
		void SetFirst(double value);
		void SetSecond(double value);

		double GetFirst() const;
		double GetSecond() const;

		Pair();
		Pair(double, double);
		Pair(const Pair&);

		Pair& operator = (const Pair&);
		friend ostream& operator << (ostream&, const Pair&);
		friend istream& operator >> (istream&, Pair&);
		operator string() const;

		Pair& operator ++ ();
		Pair& operator -- ();
		Pair operator ++ (int);
		Pair operator -- (int);

		static int getCounter();
	};
	Fraction(double, double);
	
	void SetP(double first, double second);

	int ComparePairs(const Pair p1, const Pair p2) const;
	void ComparePairsResult(int result);

	friend bool operator > (const Pair p1, const Pair p2);
	friend bool operator < (const Pair p1, const Pair p2);
	friend bool operator == (const Pair p1, const Pair p2);

	static int getCounter();
private:
	Pair p;
	static int counter;
};
