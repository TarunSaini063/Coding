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
vector< pair<int, int> > final;
int main(void)
{
	FIO
	int i, j, t1, t, n, k, pos;
	string s1, s2;
	cin >> t;
	while (t--) {
		final.clear();
		cin >> n >> k >> s1;
		s2 = "";
		for (i = 0; i < k - 1; i++) {
			s2 += "()";
		}
		t1 = (n - k - k + 2) / 2;
		for (i = 0; i < t1; i++) {
			s2 += '(';
		}
		for (i = 0; i < t1; i++) {
			s2 += ')';
		}
		for (i = 0; i < n; i++) {
			if (s1[i] != s2[i]) {
				for (j = i + 1; j < n; j++) {
					if (s1[j] != s1[i]) {
						pos = j;
						break;
					}
				}
				reverse(s1.begin() + i, s1.begin() + pos + 1);
				final.push_back(make_pair(i + 1, pos + 1));
			}
		}
		cout << (int)final.size() << endl;
		for (auto it : final) {
			cout << it.ff << " " << it.ss << endl;
		}
	}
	return 0;
}