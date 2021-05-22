#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		ll mod, fact[250005], n;
		fact[0] = 1;
		cin >> n >> mod;
		for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % mod;
		ll ret = 0;
		for (int i = 1; i <= n; i++) {
			ret += (n - i + 1) * (fact[i] * fact[n - i + 1] % mod);
			ret %= mod;
		}
		cout << ret << endl;
	}
	return 0;
}