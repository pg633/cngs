#include <iostream>
#include <vector>
using namespace std;
int main()
{
    double m, n;
    n = 0;
    m = 0;

    try
    {
        // set_new_handler();

        cout << "before dividing." << endl;
        if (n == 0)
            throw -1; //抛出int类型异常
        else
            cout << m / n << endl;
        cout << "after dividing." << endl;
    }
    catch (...)
    {
        cout << " into catch "
             << endl;
    }

    cout << "finished" << endl;
    return 0;
}