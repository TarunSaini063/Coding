#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,long long>
#define ff first
#define ss second
typedef long long ll;
const int mod = 1e9 + 7;
const int nax = 1e5 + 1;
vector<int> solve(vector<int> &A, vector<int> &B)
{
    vector<int> res;
    vector<long long> val(nax, 1);

    for (int i = 2 ; i < nax ; i++ )
    {
        for (int j = i ; j < nax ; j += i)
        {
            val[j] *= i;
            val[j] %= mod;
        }
    }

    stack<int> fw, bw;
    int n = (int)(A.size());
    vector<int> a(n), b(n);
    for (int i = 0 ; i < n ; i++ )
    {
        a[i] = 0;
        while (!fw.empty() && A[fw.top()] <= A[i])
            fw.pop();
        if (!fw.empty()) a[i] = fw.top() + 1;
        fw.push(i);
        //cout << a[i] << " " ;
    }
    //cout << "\n";
    for (int i = n - 1 ; i >= 0 ; i-- )
    {
        b[i] = n - 1;
        while (!bw.empty() && A[bw.top()] < A[i])
            bw.pop();
        if (!bw.empty()) b[i] = bw.top() - 1;
        bw.push(i);
        //cout << b[i] << " " ;
    }
    //cout << "\n";
    for (int i = 0; i < n; i++) cout << b[i] << " " << a[i] << "\n";
    vector<pii> has;

    for (int i = 0 ; i < n ; i++ ) has.push_back({val[A[i]] , (long long)((b[i] - i + 1) * (i - a[i] + 1))});
    sort(has.begin() , has.end() , greater<pii>() );

    for (int i = 1 ; i < n ; i++ ) has[i].ss += has[i - 1].ss;
    // for (auto i : has) cout << i.ff << " " << i.ss << '\n';
    //cout << has[n-1].ss << "\n";
    for (auto i : B)
    {
        int l = 0;
        int h = n - 1;
        int cur = -1;
        while (l <= h)
        {
            int m = (l + h) >> 1;
            if (i - 1 >= has[m].ss)
            {
                cur = m;
                l = m + 1;
            }
            else
                h = m - 1;
        }
        res.push_back(has[cur + 1].ff);
    }

    return res;

}
ll mxn = 1e5;
vector<int> solve1(vector<int> &A, vector<int> &B) {
    vector<ll> prime(mxn + 1, 1);
    for (int i = 2; i <= mxn; i++) {
        for (int j = i; j <= mxn; j += i) {
            prime[j] = (prime[j] * i) % mod;
        }
    }
    int n = A.size(), i = 0;
    stack<ll> r, l;
    vector<int> rid(n), lid(n);
    while (i < n) {
        lid[i] = 0;
        while (!l.empty() && A[l.top()] <= A[i])
            l.pop();
        if (!l.empty()) lid[i] = l.top() + 1;
        l.push(i++);
    }
    i = n - 1;
    while (i >= 0) {
        rid[i] = n - 1;
        while (!r.empty() && A[r.top()] < A[i]) r.pop();
        if (!r.empty()) rid[i] = r.top() - 1;
        r.push(i--);
    }
    cout << "\nsec\n";
    for (int i = 0; i < n; i++) cout << rid[i] << " " << lid[i] << '\n';
    vector<pair<ll, ll>> g;
    for (int i = 0; i < n; i++) {
        g.push_back(make_pair(prime[A[i]], (i - lid[i] + 1) * (rid[i] - i + 1)));
    }
    sort(g.begin(), g.end(), greater<pair<ll, ll>>());
    ll ans = 0;
    vector<int> res;
    // for (int i = 1; i < n; i++) g[i].second += g[i - 1].second;
    // cout << "\n sec \n";
    for (auto i : g) cout << i.ff << " " << i.ss << '\n';
    for (int i : B) {
        ll l = 0, r = n - 1, ans = -1;
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (g[mid].second <= i - 1) {
                l = mid + 1;
                ans = mid;
            }
            else {
                r = mid - 1;
            }
        }
        res.push_back((int)g[ans + 1].first);
    }
    return res;
}
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<int>arr(n), brr(m);
    for (auto &i : arr) cin >> i;
    for (auto &i : brr)cin >> i;
    vector<int> tmp = solve(arr, brr);
    vector<int> tmp1 = solve1(arr, brr);
    // for (auto i : tmp) cout << i << " ";
    // cout << "\n";
    // for (auto i : tmp1) cout << i << " ";
    return 0;
}
