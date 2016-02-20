#ifndef BIG_INT
#define BIG_INT

#include <string>
#include <iosfwd>

const long int ARY_SIZE = 10;

class Big_Int {
public:
    Big_Int();
    Big_Int(const std::string &s);
    Big_Int(const Big_Int &other);
    Big_Int operator+(const Big_Int &o);
    Big_Int operator+=(const Big_Int &o);
    friend std::ostream& operator<<(std::ostream &out, const Big_Int &o);
    int size() const;
private:
    long long num[10];
    int sz;
};

#endif
