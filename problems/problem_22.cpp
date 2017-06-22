#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;


int main()
{
    ifstream f("names.txt");
    string str((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());

    f.close();

    int length = str.length();
    const char * c = str.c_str();
    bool incr = true;

    vector<char> vstr;
    set<string> names;

    for(int idx = 0 ; idx < length ; ++idx)
    {
        if(incr && (c[idx] == '"' || c[idx] == ','))
        {
            if(vstr.size() > 0)
            {
                vstr.push_back(0);
                names.insert(&vstr[0]);
                vstr.clear();
            }

            incr = false;
        }
        else if(c[idx] != '"' && c[idx] != ',')
        {
            vstr.push_back(c[idx]);
            incr = true;
        }
    }

    long long sum = 0;
    int pos = 0;

    set<string>::iterator it = names.begin();
    for(; it != names.end() ; ++it)
    {
        ++pos;
        length = it->size();
        c = it->c_str();

        for(int idx = 0 ; idx < length ; ++idx)
        {
            sum += pos * (c[idx] - 64);
        }
    }

    cout << sum << endl;

    return 0;
}
