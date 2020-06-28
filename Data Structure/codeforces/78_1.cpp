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
		string s1, s2;
		cin >> s1 >> s2;
		multiset<char> st1, st2;
		int n = s1.size(), fl = 0;
		for (auto i : s1) st1.insert(i);
		for (int i = 0; i < n; i++) st2.insert(s2[i]);
		if (st1 == st2) {
			fl = 1;
		} else
			for (int i = n; i < (int)s2.size(); i++) {
				st2.erase(st2.find(s2[i - n]));
				st2.insert(s2[i]);
				if (st1 == st2) {
					fl = 1;
					break;
				}
			}
		if (fl) cout << "YES\n";
		else cout << "NO\n";

	}
	return 0;
}