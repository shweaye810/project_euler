#ifndef NUMBER_H
#define NUMBER_H

class Number
{
private:
	bool is_prime;
public:
	Number()
	{
		is_prime = false;
	}
	void make_prime();
	bool get_prime() const;
};

bool Number::get_prime() const
{
	return is_prime;
}
void Number::make_prime()
{
	is_prime = true;
}
#endif
