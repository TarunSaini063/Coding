#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
ll invmod(ll a) {return power(a, mod - 2);}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int n, dif = 0, i1 = -1, j1 = -1;
		cin >> n;
		string a, b;
		cin >> a >> b;
		for (int i = 0; i < n; i++)
		{
			if (a[i] != b[i])
			{
				dif++;
				if (i1 == -1) i1 = i;
				else if (j1 == -1) j1 = i;
			}
		}
		if (dif > 2) cout << "NO" << '\n';
		else {
			if (a[i1] != a[j1] || b[j1] != b[i1]) cout << "NO" << '\n';
			else cout << "YES" << '\n';
		}

	}
	return 0;
}