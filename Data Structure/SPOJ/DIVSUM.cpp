#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
ll invmod(ll a) {return power(a, mod - 2);}
const int mxn = 80000001;
int get( int a,  int x)
{
	int b = a;
	while (x % b == 0)
		b *= a;
	return b;
}
int main(void)
{
	FIO
	int t;
	vector<int>primes(mxn, 0);
	primes[0] = primes[1] = 1;
	for (int i = 2; i <= 500000; i++) {
		if (primes[i] == 0) {
			for (int j = i; j <= mxn; j += i) {
				if (primes[j] == 0) primes[j] = i;
			}
		}
	}
	cin >> t;
	while (t--)
	{
		int x, i, t, result;
		cin >> x;
		t = x;
		result = 1;
		while (t > 1)
		{
			i = primes[t];
			if (x % i != 0) continue;
			int p = get(i, t);
			result *= (p - 1) / (i - 1);
			t /= p / i;
		}
		cout << result - x << '\n';
	}
	return 0;
}