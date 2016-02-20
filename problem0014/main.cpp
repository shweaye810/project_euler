#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

struct Tnk {
    long chn, num;
    Tnk() : chn{0}, num{0} {};
    Tnk(long f, long s) : num{f}, chn{s} {};
};
int main()
{
    vector<Tnk> list;
    long crn_num = 999999;
///    long crn_num = 837799;
    time_t start = time(NULL), end;
    do {
//        cout << crn_num << endl;
        vector<long> tmp;
        tmp.push_back(crn_num--);
        while (tmp.back() >= 2) {
//            cout << ' ' << tmp.back();
            if (tmp.back() % 2 == 0)
                tmp.push_back(tmp.back() / 2);
            else
                tmp.push_back(tmp.back() * 3 + 1);
        }
        Tnk Tk_tmp(tmp.front(), tmp.size());
        list.push_back(Tk_tmp);
    } while (crn_num > 10000);
    long l = 0, num = 0;
    cout << "itr start.\n";
    for(auto itr = list.begin(); itr != list.end(); itr++) {
//        cout << itr->chn << ' ' << itr->num << endl;
        if (itr->chn > l) {
            l = itr->chn;
            num = itr->num;
        }
    }
    cout << l << ' ' << num << endl;
    end = time(NULL);
    double second = difftime(end, start);
    cout << "program finish in " << second << " seconds\n";
}
    
