#ifndef DIVISOR_H
#define DIVISOR_H

#include <vector>

class Divisor {
public:
    Divisor();
    Divisor(int n);
    int get_amicable_number() const;
    void set_amicable_number(int n);
    bool is_amicable_number() const;
    int sum() const;
private:
    std::vector<int> dvsr;
    bool has_mcbl;
    int num;
    int sm;
    int mcbl_num;
};

#endif
