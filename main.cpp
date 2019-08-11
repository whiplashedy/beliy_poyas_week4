#include <iostream>

using namespace std;
int salam(int num, int den) //algorithm to find Greatest Common Division
{
    int reminder= 0;
    while (num > 0 && den > 0)
    {
        if (num > den)
        {
            num %= den;
        }
        else
        {
            den %= num;
        }

    }
    reminder = num + den;
    return reminder;
}
class Rational
{
public:
    Rational()
    {
        a = 0;
        b = 1;
    }
    Rational(int numerator, int denominator)
    {
        if(denominator <= 0)
        {
            throw invalid_argument("Invalid argument");
        }
        a = numerator / salam(abs(numerator),abs(denominator)); // rational now will be cancelled
        b = denominator / salam(abs(numerator),abs(denominator));
        if(b < 0)
        {
            b *= -1;
            a *= -1;
        }
        if(a == 0)
        {
            b = 1;
        }
    }
    int Numerator() const
    {
        return a;
    }
    int Denominator() const
    {
        return b;
    }
private:
    int a,b;
};

Rational operator+(const Rational &l, const Rational &r)
{

    return Rational(r.Denominator()*l.Numerator() + r.Numerator()*l.Denominator(),l.Denominator()*r.Denominator());
}
Rational operator-(const Rational &l, const Rational &r)
{
    if(r.Numerator()==0)
    {
        throw invalid_argument("Invalid argument");
    }
    return Rational(r.Denominator()*l.Numerator() - r.Numerator()*l.Denominator(),l.Denominator()*r.Denominator());
}

bool operator == (const Rational& l, const Rational &r)
{
    if ((l.Numerator() == r.Numerator()) && (l.Denominator() == r.Denominator()))
    {
        return true;
    }
    return false;
}

//bool operator <(const Rational& l, const Rational& r){
//    return ((l.Numerator() * r.Denominator()) < (r.Numerator() * l.Denominator()));
//}

Rational operator*(const Rational& l, const Rational& r)
{
    return Rational(l.Numerator() * r.Numerator(), l.Denominator() * r.Denominator());
}

Rational operator/(const Rational& l, const Rational& r)
{
    //int z = lhs.Denominator() * rhs.Numerator();
	if (r.Numerator() == 0)
	{
		throw domain_error("Division by zero");
	}
    return Rational(l.Numerator() * r.Denominator(), l.Denominator() * r.Numerator());
}

istream& operator>>(istream& stream, Rational& rational)
{
    int x = rational.Numerator();
    int y = rational.Denominator();
    if(stream.good())
    {
        stream>>x;
        if(stream.peek()!='/'){
			throw invalid_argument("Invalid argument");
		}
        stream.ignore(1);
        stream>>y;
        rational = Rational(x,y);
        return stream;
    }
}
ostream& operator<<(ostream& stream, const Rational& rational)
{
    stream << rational.Numerator()<<"/"<<rational.Denominator();
    return stream;
}

int main()
{
	Rational rational1, rational2;
	char operation;
	try {
			cin >> rational1 >> operation >> rational2;
				if (operation == '+')
				{
					cout << (rational1 + rational2);
				}
				if (operation == '-')
				{
					cout << (rational1 - rational2);
				}
				if (operation == '*')
				{
					cout << (rational1 * rational2);
				}
				if (operation == '/')
				{
					cout << (rational1 / rational2);
				}
	}
	catch (invalid_argument& ex) {
		cout << ex.what();
	}
	catch (domain_error& ex) {
		cout << ex.what();
	}
	return 0;
}

