#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

int main()
{
    // ofstream o;
    // o.open("in.txt", ios::out);

    int T, n, m;

    srand(time(0));
    T = rand() % 20 + 1;
    // o << T << endl;
    cout << T << endl;
    
    while (T --)
    {
        n = rand() % 100 + 1;
        // m = rand() % 300000 + 1;
        // if (n != 1 || m != 1)
        //     o << n << ' ' << m << endl;
        // o << n << ' ';
        cout << n << ' ';
    }
    
    // o.close();
    // ofstream out;
    // out.open("in.txt", ios::out);

    // for (int i = 1; i <= 2; ++i) out << 1 << ' '; // 2
    // for (int i = 3; i < 1001; ++i) out << 2 << ' '; // 999
    // for (int i = 4; i <= 2000; i += 2) out << i << ' '; // 999
    // out << endl;
    // out.close();
    return 0;
}