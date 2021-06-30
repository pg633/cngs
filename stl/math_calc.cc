#include <bits/stdc++.h>
using namespace std;

#define _SIZE 8
int round_up(int x)
{
    return (x + _SIZE - 1) & ~(_SIZE - 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif //
    cout << round_up(3) << endl;
    cout << round_up(8) << endl;
    cout << round_up(15) << endl;
    return 0;
}
// g++ a.cc -std=c++11 -o app && ./app