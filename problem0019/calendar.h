#ifndef CALENDAR_H
#define CALENDAR_H

#include <iosfwd>

const int MONTH_SIZE = 12;
class Year {
public:
    Year(int y);
    friend std::ostream& operator<<(std::ostream &out, const Year &o);
    int get(int n);
private:
    int m[MONTH_SIZE + 1];
    
};

#endif
