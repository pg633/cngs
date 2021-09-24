#include <iostream>
#include <iomanip>
using namespace std;
double n, l, r, mid;
bool flag;
double q(double a) { return a * a * a; }
int main()
{
    cin >> n;
    l = -10000, r = 10000;
    while (r - l >= 1e-7)
    {
        mid = (l + r) / 2;
        if (q(mid) >= n)
            r = mid;
        else
            l = mid;
    }
    cout << fixed << setprecision(6) << l;
    return 0;
}
bool check1(int mid)
{
    return a[mid] >= num;
}
int lower_bound(int l, int r)
{
    int mid;
    while (l < r)
    {
        mid = l + (r - l) / 2;
        if (check1(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}
bool check(int mid)
{
    return a[mid] <= num;
}

int upper_bound(int l, int r)
{
    int mid;
    while (l < r)
    {
        mid = l + (r - l + 1) / 2;
        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    return l;
}
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    mt19937 gen;
    uniform_int_distribution<int> dis;
    vector<int> pre;

public:
    Solution(vector<int> &w) : gen(random_device{}()), dis(1, accumulate(w.begin(), w.end(), 0))
    {
        partial_sum(w.begin(), w.end(), back_inserter(pre));
    }

    int pickIndex()
    {
        int x = dis(gen);
        return lower_bound(pre.begin(), pre.end(), x) - pre.begin();
    }
};
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define Mod 9901
int a, b;
int ksm(int a, int b) //快速幂函数
{
    int ans = 1;
    a %= Mod;
    while (b)
    {
        if (b & 1)
            ans = ans % Mod * a;
        a = a % Mod * a % Mod;
        b >>= 1;
    }
    return ans;
}
long long sum(int p, int c)
{
    if (c == 0)
        return 1;
    if (c & 1)
        return (
                   (1 + ksm(p, (c + 1) >> 1)) * sum(p, (c - 1) >> 1)) %
               Mod; //奇数的情况下
    else
        return ((1 + ksm(p, c >> 1)) * sum(p, (c >> 1) - 1) + ksm(p, c)) % Mod; //偶数的情况下
}
int main()
{
    cin >> a >> b;
    int ans = 1;
    for (int i = 2; i <= a; i++)
    {
        int s = 0;
        while (a % i == 0)
        {
            s++;
            a /= i;
        }
        if (s) //这句话剪枝.然后就TLE变成了AC.by POJ
            ans = ans * sum(i, s * b) % Mod;
    }
    if (a == 0)
        cout << 0 << endl; //特判的情况，这里非常的阴毒，出题人用心险恶
    else
        cout << ans << endl;
    return 0;
}
