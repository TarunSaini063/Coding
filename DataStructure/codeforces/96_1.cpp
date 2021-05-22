#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb push_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define ar array
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
		int n;
		cin >> n;
		if (n % 3 == 0) cout << n / 3 << " 0 0\n";
		else if (n % 5 == 0) cout << "0 " << n / 5 << " 0\n";
		else if (n % 7 == 0) cout << "0 0 " << n / 7 << '\n';
		else if (n % 3 == 1 && n > 7) cout << n / 3 - 2 << " 0 " << "1\n";
		else if (n % 3 == 2 && n > 5) cout << n / 3 - 1 << " 1 0\n";
		else cout << "-1\n";
	}
	return 0;
}
