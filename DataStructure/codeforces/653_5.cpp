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
vector<ll> com;
int main(void)
{
	FIO
	int x, y, z;
	ll ans = 0, n, k;
	cin >> n >> k;
	multiset<ll> s1, s2;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> z;
		if (y && z ) com.pb(x);
		else if (y ) s1.insert(x);
		else if (z ) s2.insert(x);
	}
	while (s1.size() && s2.size()) {
		com.pb(*s1.begin() + *s2.begin());
		s1.erase(s1.begin());
		s2.erase(s2.begin());
	}
	if ((int)com.size() < k) {
		cout << "-1\n";
		return 0;
	}
	sort(all(com));
	for (int i = 0; i < k; i++)ans += com[i];
	cout << ans << "\n";
	return 0;
}