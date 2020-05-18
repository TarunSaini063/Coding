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
const int mx = 1e6 + 1;
int f[mx];																		//fedwick tree BIT
void update(int id, int val)
{
	while (id < mx)
	{
		f[id] += val;
		id += (id & -id);
	}
}
int sum(int id)
{
	int sm = 0;
	while (id > 0)
	{
		sm += f[id];
		id -= (id & -id);
	}
	return sm;
}
int main(void)
{
	FIO
	int n, q, x, p = 0;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		update(x, 1);
	}
	p = n;
	while (q--)
	{
		cin >> x;
		if (x > 0) update(x, 1), p++;
		else
		{
			x = -x;
			int l = 0;
			int h = 1e6;
			while (l < h)
			{
				int mid = (l + h) / 2;
				if (sum(mid) >= x)
				{
					h = mid;
				}
				else
				{
					l = mid + 1;
				}
			}
			p--;
			update(l, -1);
		}
	}
	if (p == 0) cout << 0 << '\n';
	else {
		p = sum(mx - 1);
		int l = 0;
		int h = 1e6;
		while (l < h)
		{
			int mid = (l + h) / 2;
			if (p <= sum(mid))
			{
				h = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		cout << l << "\n";
	}
	return 0;
}