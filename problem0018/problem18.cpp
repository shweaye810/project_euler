#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

template<typename T>
void print(T v)
{
    cout << setw(3) << v;
}
int main()
{
    ifstream fin("file.txt");
    if (!fin) {
        cout << "no such file.\n";
        return -1;
    }
    string s;
    vector< vector<int> > vtr;
    vector<int> *vptr;
    int n = 0, i = 0;
    while (getline(fin, s)) {
        stringstream sstrm(s);
        vtr.push_back(vector<int>());
        vptr = &vtr.back();
        while (sstrm >> n) {
            vptr->push_back(n);
        }
    }
    
    for (int i = 0; i < vtr.size(); i++) {
        vptr = &vtr[i];
        for (int k = vtr.size() - i - 1; k > 0; k--)
            cout << " ";
        for (int j = 0; j < vptr->size(); j++) {
            if ((*vptr)[j] > 70)
                print((*vptr)[j]);
            else
                print("__");
        }
        cout << endl;
    }
            
    return 0;
}
