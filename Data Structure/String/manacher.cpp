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
    int n = s.size();
    n = 2 * n + 1;
    int l[n];
    l[0] = 0;
    l[1] = 1;
    int c = 1, r = 2, id = 0, ans = 1;
    // cout<<l[0]<<" "<<l[1]<<endl;
    for (int i = 2; i < n; i++)
    {
        int mir = 2 * c - i;
        l[i] = 0;
        if (i < r)
        {
            l[i] = min(l[mir], r - i);
            // cout<<"inside min "<<i<<"\n";
        }
        while (i - l[i] - 1 >= 0 && i + l[i] + 1 < n && ((i + l[i] + 1) % 2 == 0 || s[(i + l[i] + 1) / 2] == s[(i - l[i] - 1) / 2]))
        {

            // cout<<(i + l[i] + 1) <<" "<<(i - l[i] - 1) <<" "<<l[i]<<" "<<i<<" "<<endl;
            l[i]++;
        }
        if (ans < l[i]) {
            ans = l[i];
            id = i;
        }
        if (i + l[i] > r)
        {
            r = i + l[i];
            c = i;
        }
    }
    for (int i = 0; i < n; i++) cout << l[i] << " ";
    cout << endl;
    cout << s.substr((id - ans) / 2, ans) << '\n';
    return 0;
}