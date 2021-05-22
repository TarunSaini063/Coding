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
vector<int> id;
int root(int x)
{
	while (x != id[x]) x = id[x];
	return x;
}

void uni(int p, int q)
{
	id[p] = id[q];
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string s;
		for (int i = 0; i < n; i++) {
			cin >> s;
			st.insert(s);
			for (auto j : s) ch.insert(j);
		}
		id.assign(26, 0);
		for (int i = 0; i < 26; i++) id[i] = i;
		for (auto i : s)
		{
			if (i.size() > 1)
			{
				for (int i1 = 0; i1 < (int)i.size() - 1; i++)
				{
					int p = root(i[i1] - 'a');
					int q = root(i[i1 + 1] - 'a');
					if (p != q) uni(p, q);
				}
			}
		}
		for (auto c : ch)
		{
			ans.pb(id[c - 'a']);
		}
		cout << ans.size() << '\n';
	}
	return 0;
}