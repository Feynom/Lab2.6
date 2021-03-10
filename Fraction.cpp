#include "Fraction.h"

//Class Pair

int Fraction::Pair::counter = 0;
int Fraction::Pair::getCounter()
{
	return Fraction::Pair::counter;
}

void Fraction::Pair::SetFirst(double value) { first = value; }
void Fraction::Pair::SetSecond(double value) { second = value; }

double Fraction::Pair::GetFirst() const { return first; }
double Fraction::Pair::GetSecond() const { return second; }

Fraction::Pair::Pair() { first = 0, second = 0; Fraction::Pair::counter++; }
Fraction::Pair::Pair(double first = 0, double second = 0)
{
	this->first = first;
	this->second = second;
	Fraction::Pair::counter++;
}
Fraction::Pair::Pair(const Pair& A)
{
	first = A.GetFirst();
	second = A.GetSecond();
	Fraction::Pair::counter++;
}

Fraction::Pair& Fraction::Pair::operator = (const Pair& A)
{
	first = A.first;
	second = A.second;

	return *this;
}
ostream& operator << (ostream& out, const Fraction::Pair& A)
{
	out << string(A);
	return out;
}
istream& operator >> (istream& in, Fraction::Pair& A)
{
	cout << "Enter a first number of pair: "; in >> A.first;
	cout << "Enter a second number of pair: "; in >> A.second;
	return in;
}
Fraction::Pair::operator string() const
{
	stringstream ss;
	ss << "First number of pair is equal to " << first << endl;
	ss << "Second number of pair is equal to " << second << endl;
	return ss.str();
}

Fraction::Pair& Fraction::Pair::operator ++ ()
{
	first++;
	return *this;
}
Fraction::Pair& Fraction::Pair::operator -- ()
{
	first--;
	return *this;
}
Fraction::Pair Fraction::Pair::operator ++ (int)
{
	Pair t(*this);
	second++;
	return t;
}
Fraction::Pair Fraction::Pair::operator -- (int)
{
	Pair t(*this);
	second--;
	return t;
}

//Class Fraction

int Fraction::counter = 0;
int Fraction::getCounter()
{
	return Fraction::counter;
}

void Fraction::SetP(double first, double second) { Pair(first, second); }
Fraction::Fraction(double first = 0, double second = 0)
	: p(first, second)
{
	counter++;
}

bool operator > (const Fraction::Pair p1, const Fraction::Pair p2)
{
	if (p1.GetFirst() > p2.GetFirst() ||
		(p1.GetFirst() == p2.GetFirst() && p1.GetSecond() > p2.GetSecond()))
		return 1;
	else
		return 0;
}
bool operator < (const Fraction::Pair p1, const Fraction::Pair p2)
{
	if (p1.GetFirst() < p2.GetFirst() ||
		(p1.GetFirst() == p2.GetFirst() && p1.GetSecond() < p2.GetSecond()))
		return 1;
	else
		return 0;
}
bool operator == (const Fraction::Pair p1, const Fraction::Pair p2)
{
	if ((p1.GetFirst() == p2.GetFirst()) &&
		(p1.GetSecond() == p2.GetSecond()))
		return 1;
	else
		return 0;
}

int Fraction::ComparePairs(const Pair p1, const Pair p2) const
{
	if (p1 > p2)
		return 1;
	if (p1 < p2)
		return 2;
	if (p1 == p2)
		return 3;
}
void Fraction::ComparePairsResult(int result)
{
	switch (result)
	{
	case 1:
		cout << "\nP1 > P2" << endl;
		break;
	case 2:
		cout << "\nP1 < P2" << endl;
		break;
	case 3:
		cout << "\nP1 = P2" << endl;
		break;
	}
}