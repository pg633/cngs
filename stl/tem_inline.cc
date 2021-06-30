#include <iostream>
using namespace std;
class alloc
{
};
template <class T, class Alloc = alloc>
class ver
{
public:
    void swap(ver<T, Alloc> &b)
    {
        cout << "swap" << endl;
    }
};
template <class T, class Alloc = alloc>
inline void swap(ver<T, Alloc> &a, ver<T, Alloc> &b)
{
    cout << "inline swap" << endl;
    a.swap(b);
}

int main()
{

    ver<int> a, b;
    swap(a, b);
    return 0;
}
// g++ a.cc -std=c++11 -o app && ./app