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
bool fun(ll d, ll ans) {
	ans = (ans + 1) * ans / 2;
	if (ans < d) return false;
	return ans % 2 == d % 2;
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--) {
		ll a, b, ans = 1;
		cin >> a >> b;
		a = abs(a - b);
		if (a == 0) {
			cout << "0\n";
			continue;
		}
		while (!fun(a, ans)) ans++;
		cout << ans << '\n';
	}
	return 0;
}