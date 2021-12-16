#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

string isMap[15];

int main()
{
    isMap[0] = "zero"; isMap[1] = "one"; isMap[2] = "two";
    isMap[3] = "three"; isMap[4] = "four"; isMap[5] = "five";
    isMap[6] = "six"; isMap[7] = "seven"; isMap[8] = "eight";
    isMap[9] = "nine";

    string num;
    cin >> num;

    int sum = 0;
    for (int i = 0; i < num.size(); ++i) sum += num[i] - '0';

    stringstream ss;
    ss << sum;
    ss >> num;

    for (int i = 0; i < num.size(); ++i)
        if (i == num.size() - 1) cout << isMap[num[i] - '0'] << endl;
        else cout << isMap[num[i] - '0'] << ' ';

    return 0;
}