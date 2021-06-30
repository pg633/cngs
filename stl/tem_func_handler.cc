#include <bits/stdc++.h>
using namespace std;

void print(int x)
{
    cout << x << endl;
}
// void cc(int x, void f(int c))

void cc(int x, void (*f)(int c))
{
    f(x);
}

static void (*__set_malloc_handler(void (*__f)()))(int __value)
{
    return nullptr;
}

static int *(*func_name(int x, int func(int *_func)))(int _func)
{
    int y = func(&x);

    return (int *(*)(int _func))(func + y);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif //
    int x = 1;
    cc(x, print);
    return 0;
}
// g++ a.cc -std=c++11 -o app && ./app