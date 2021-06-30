#include <iostream>
using namespace std;
template <class T>
class A
{
public:
    static int _data;
};

template <>
int A<int>::_data = 1;

int main()
{
    cout << A<int>::_data << endl;
    return 0;
}