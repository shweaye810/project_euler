#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    ifstream fin("names.txt");
    if (!fin) {
        cout << "No such file.\n";
        return -1;
    }
    string s;
    getline(fin, s);

    char *pch, str[s.size()];
    strcpy(str, s.c_str());
    pch = strtok(str, ",\"");
    vector<string> list;
    while (pch != NULL) {
        list.push_back(pch);
        pch = strtok(NULL, ",\"");
    }
    sort(list.begin(), list.end());

    int ttl = 0, crnt = 0;
    for (int j = 0; j < list.size(); j++) {
        crnt = 0;
        int k = j + 1;
        for (int i = 0; i < list[j].size(); i++) {
            crnt += list[j][i] - 'A' + 1;
        }
        crnt *= k;
        ttl += crnt;
    }
    cout << "total is " << ttl << endl;
    return 0;
}
