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
		int n, fl = 1;
		cin >> n;
		string s, t;
		cin >> s >> t;
		int arr[26] = {0};
		for (int i = 0; i < n; i++)
		{
			arr[s[i] - 'a']++;
			arr[t[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++)
		{
			if (arr[i] % 2) {
				cout << "NO" << '\n';
				fl = 0;
				break;
			}
		}
		vector<pair<int, int>> v;
		if (fl)
		{
			cout << "YES" << '\n';
			for (int i = 0; i < n; i++)
			{
				if (s[i] != t[i])
				{
					int k = -1;
					for (int j = i + 1; j < n; j++)
					{
						if (t[j] == s[i]) k = j;
					}
					if (k != -1)
					{
						swap(s[k], t[k]);
						swap(t[i], s[k]);
						v.pb(mk(k, k));
						v.pb(mk(k, i));
					}
					else
					{
						for (int j = i + 1; j < n; j++)
						{
							if (s[i] == s[j]) k = j;
						}
						swap(t[i], s[k]);
						v.pb(mk(k, i));
					}
				}
			}
			cout << v.size() << '\n';
			for (auto i : v)
			{
				cout << i.ff + 1 << " " << i.ss + 1 << "\n";
			}
		}
	}
	return 0;
}