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
	deque<int> q;
	int n, x, prev = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		q.push_back(x);
	}
	while (prev != (int)q.size())
	{
		int sz = q.size();
		prev = sz;
		// cout << "\nsize " << sz << '\n';
		while (sz--)
		{
			int y = q.front();
			q.pop_front();
			// cout << "prev " << y << ' ';
			if (sz == 0 || q.front() != y) q.push_back(y);//, cout << "sz " << sz << " push " << y << '\n';
			else
			{
				q.pop_front();
				sz--;
				y++;
				int k = 2;
				while (sz != 0 && q.front() == y)
				{
					q.pop_front();
					k++;
					sz--;
					y++;
				}
				// cout << "ele " << k << " " << y << '\n';
				q.push_back(y);//, cout << "sz " << sz << " push " << y << '\n';
			}
		}
	}
	// cout << '\n';
	cout << prev << '\n';
	return 0;
}