#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person {
    string name;
    string start;
    string end;
};

int m;
vector<Person> person;

bool judgeTimeEarlier(string t1, string t2)
{

    string t1H = t1.substr(0, 2);
    string t1M = t1.substr(3, 2);
    string t1S = t1.substr(6);

    string t2H = t2.substr(0, 2);
    string t2M = t2.substr(3, 2);
    string t2S = t2.substr(6);

    if (t1H < t2H) return true;
    else if (t1H == t2H)
    {
        if (t1M < t2M) return true;
        else if (t1M == t2M)
        {
            if (t1S < t2S) return true;
            return false;
        }
        return false;
    }
    return false;
}
int main()
{
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        string name, start, end;
        cin >> name >> start >> end;
        person.push_back({name, start, end});
    }

    int minTInx{-1}, maxTInx{-1};
    for (int i = 0; i < person.size(); ++i)
    {
        if (minTInx == -1 || judgeTimeEarlier(person[i].start, person[minTInx].start)) minTInx = i;
        if (maxTInx == -1 || judgeTimeEarlier(person[maxTInx].end, person[i].end)) maxTInx = i;
    }
    
    cout << person[minTInx].name << ' ' << person[maxTInx].name << endl;
    return 0;
}
