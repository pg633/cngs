#include <bits/stdc++.h>
using namespace std;

template <class T>

class print
{
public:
    void operator()(const T &item)
    {
        cout << item << " ";
    }
};

template <class T1, class T2>
inline void _construct(T1 *p, const T2 &value)
{
    new (p) T1(value); // placement new. invoke ctor of T1
}

class T1
{
private:
    int k;
    int s;

public:
    T1(int n)
    {
        k = s = n;
        cout << "T1" << endl;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif //
    int ia[6] = {0, 1, 2, 3, 4, 5};
    vector<int> iv(ia, ia + 6);

    // print<int>() 是一个匿名对象，不是函数调用
    for_each(iv.begin(), iv.end(), print<int>());

    int k = 109;
    T1 *t = new T1(10);
    _construct(t, k);
    return 0;
}
// g++ a.cc -std=c++11 -o app && ./app