#ifndef BIG_INT
#define BIG_INT

#include <string>
#include <iosfwd>

const long int ARY_SIZE = 20;

class Big_Int {
public:
    Big_Int();
    Big_Int(const std::string &s);
    Big_Int(const Big_Int &other);
    const Big_Int &operator+(const Big_Int &o) const;
    const Big_Int &operator+=(const Big_Int &o);
    const Big_Int &operator*(const Big_Int &o) const;
    const Big_Int &operator*=(const Big_Int &o);
    friend std::ostream &operator<<(std::ostream &out, const Big_Int &o);
    const int size() const;
private:
    long long num[ARY_SIZE];
    int sz;
};

#endif
