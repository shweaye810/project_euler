#include "divisor.h"

using namespace std;

Divisor::Divisor() : has_mcbl(0), num(0), sm(0), mcbl_num(-1)
{
    dvsr.push_back(0);
}

Divisor::Divisor(int n) : has_mcbl(0), num(n), sm(0), mcbl_num(-1)
{
    for (int i = 1; i < num; i++) {
        if (num % i == 0)
            dvsr.push_back(i);
    }
    for (auto itr = dvsr.begin(); itr != dvsr.end(); itr++)
        sm += *itr;
}

int Divisor::sum() const
{
    return sm;
}

int Divisor::get_amicable_number() const
{
    return mcbl_num;
}

void Divisor::set_amicable_number(int n)
{
    mcbl_num = n;
    has_mcbl = true;
}

bool Divisor::is_amicable_number() const
{
    return has_mcbl;
}
