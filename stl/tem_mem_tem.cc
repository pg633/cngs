#include <bits/stdc++.h>
using namespace std;
class alloc
{
};
template <class T, class Alloc = alloc>
class ver
{
public:
    typedef T value_type;
    typedef value_type *value_ptr;
    template <class I>
    void insert(value_ptr it, I fitst, I second)
    {
        cout << "insert" << endl;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif //
    ver<int> c;
    ver<int>::value_ptr it;
    c.insert(it, 1, 1);
    return 0;
}
// g++ a.cc -std=c++11 -o app && ./app