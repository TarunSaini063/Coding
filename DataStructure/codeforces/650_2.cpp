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
		int n, x, o = 0, e = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			if (i % 2 == 0 && x % 2 == 1) o++;
			else if (i % 2 == 1 && x % 2 == 0) e++;
		}
		if (o != e) cout << "-1\n";
		else cout << o << '\n';
	}
	return 0;
}