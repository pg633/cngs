#include <iostream>
using namespace std;
namespace sil
{

    template <class T>
    class Plus
    {
    public:
        T operator()(const T &l, const T &r)
        {
            return l + r;
        }
    };

};
int main()
{
    sil::Plus<int> plus;
    cout << plus(1, 2) << endl;

    cout << sil::Plus<int>()(3, 5) << endl;

    // cout << sil::Plus<int>()(1, 2) << endl;
    return 0;
}