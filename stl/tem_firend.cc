#include <bits/stdc++.h>
using namespace std;

#define __STL_NULL_TMPL_ARGS <>
#define __STL_TMPL_ARGS(T) <T>

class A
{
private:
    int a;
    int b;
    string name;

public:
    A(int a, int b, string c)
        : a(a), b(b), name(c)
    {
    }
    friend void prit(A &a, const A &b)
    {
        cout << a.name << " " << b.name << endl;
        a.name = b.name;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif //
    A a{2, 2, "456"}, b{1, 1, "123"};
    prit(a, b);
    prit(a, b);
    return 0;
}
// g++ a.cc -std=c++11 -o app && ./app