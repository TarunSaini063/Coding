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
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int x, n, ans = 0;
		cin >> x >> n;
		set<int> s;
		multiset<int> s1;
		s.insert(0);
		s.insert(x);
		s1.insert(x);
		for (int i = 0; i < n; i++) {
			cin >> x;
			auto it = s.upper_bound(x);
			int r = *it;
			it--;
			int l = *it;
			s.insert(x);
			int last = r - l;
			if (s1.find(last) != s1.end()) {
				s1.erase(s1.find(last));
			}
			s1.insert(r - x);
			s1.insert(x - l);
			it = s1.end();
			it--;
			cout << *it << " ";
		}
	}
	return 0;
}