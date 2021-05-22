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
void solve()
{
	int n, x, k = 1;
	set<int> st;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		st.insert(x);
		v.pb(x);
	}
	if ((int)st.size() == 1)
	{
		cout << 1 << "\n";
		for (int i = 1; i <= n; i++) cout << 1 << ' ';
		cout << "\n";
		return;
	}
	else
	{
		if (n % 2 == 0)
		{
			cout << 2 << "\n";
			k = 1;
			for (int i = 0; i < n; i++)
			{
				cout << k % 3 << " ";
				k++;
				if (k == 3) k = 1;
			}
			cout << "\n";
			return;
		}
		for (int i = 0; i < n; i++)
		{

			if (v[i] == v[(i + 1) % n])
			{
				cout << 2 << "\n";
				vector<int> res(n);
				k = 1;
				for (int j = i + 1; j < n; j++)
				{
					res[j] = k % 3;
					k++;
					if (k == 3) k = 1;
				}
				k = 1;
				for (int j = i ; j >= 0; j--)
				{
					res[j] = k % 3;
					k++;
					if (k == 3) k = 1;
				}
				for (auto i : res) cout << i << " ";
				cout << "\n";
				return;
			}
		}
		cout << 3 << "\n";
		for (int i = 0; i < n - 1; ++i) {
			cout << i % 2 + 1 << " ";
		}
		cout << 3 << endl;
	}
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}