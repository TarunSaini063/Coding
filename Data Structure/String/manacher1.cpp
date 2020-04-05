#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define all(x) x.begin(), x.end()
ll power(ll a, ll b)
{
    ll res = 1;
    a = a % mod;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}
ll invmod(ll a) { return power(a, mod - 2); }
int main(void)
{
    FIO
        string s;
    cin >> s;
    int n = s.size() * 2 + 1;
    int l[n];
    l[0] = 0;
    l[1] = 1;
    int c = 1, r = 2;
    for (int i = 2; i < n; i++)
    {
        int mir = 2 * c - i;
        l[i] = 0;
        if (i < r)
        {
            l[i] = min(l[mir], r - i);
        }
        while (i + l[i] + 1 <= n && i - l[i] - 1 >= 0 &&
               ((i + l[i] + 1) % 2 == 0 ||
                s[(i + l[i] + 1) / 2] ==
                    s[(i - l[i] - 1) / 2]))
        {
            l[i]++;
        }
        if (r < i + l[i])
        {
            r = i + l[i];
            c = i;
        }
    }

    return 0;
}
for (int i = 2; i < n; i++)
{
    int mir = 2 * c - i;
    l[i] = 0;
    if (i < r)
    {
        l[i] = min(l[mir], r - i);
    }
    while (l[i] + i + 1 <= n && i - l[i] - 1 >= 0 &&
           ((i + l[i] + 1) % 2 == 0 ||
            s[(i + l[i] + 1) / 2] ==
                s[(i - l[i] - 1) / 2]))
    {
        l[i]++;
    }
    if (r < i + l[i])
    {
        r = i + l[i];
        c = i;
    }
}