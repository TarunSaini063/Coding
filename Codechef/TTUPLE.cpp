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
vector<pair<ll, ll>> v;
vector<pair<string, vector<pair<ll, ll>>>> pr;
int ans, x1;
ll num, din, x, y, a[3], b[3];
struct cmp {
	bool operator()(const pair<ll, ll>& a, const pair<ll, ll>& b) const {
		if (a.ff == b.ff) return a.ss < b.ss;
		return a.ff < b.ff;
	}
};
bool solution(int i, int j)
{
	num = b[i] - b[j];
	din = a[i] - a[j];
	// cout << "num " << num << " din " << din << '\n';
	if (din == 0) return num == 0;
	if (num % din != 0) return false;
	x = num / din;
	// cout << "x " << num << '\n';
	return true;
}
bool solve(int id, int op, vector<pair<ll, ll>> arr)
{
	// cout << "id= " << id << ' ' << " op= " << op << '\n';
	// for (auto i : arr)
	// {
	// 	cout << i.ff << ' ' << i.ss << " ,";
	// }
	// cout << '\n';
	if (id == (int)arr.size()) {
		// cout << "id= " << id << ' ' << " op= " << op << '\n';
		ans = min(ans, op);
		// cout << "id= " << id << ' ' << " op= " << op << ' ';
		// for (auto i : arr)
		// {
		// 	cout << i.ff << ' ' << i.ss << " ,";
		// }
		// cout << '\n';
		if (x1 == 0 && op == 2) {
			x1 = 1;
			return true;
		}
		return false;
	}
	bool res = false;
	if (arr[id].ff == arr[id].ss) {
		res |= solve(id + 1, op, arr);
		// cout << "in " << to_string(id) + "-" + to_string(op ) << " " << arr[id].ff << '\n';
		if (res) pr.pb(mk(to_string(id) + "-" + to_string(op ), arr));
		return res;
	}
	if (id == (int)arr.size() - 1)
	{
		arr[id].ff = arr[id].ss;
		res |= solve(id + 1, op + 1, arr);
		if (res) {pr.pb(mk(to_string(id) + "-" + to_string(op), arr)); return res;}
		return res;
	}
	ll add = arr[id].ss - arr[id].ff;
	auto tp = arr;
	tp[id].ff = tp[id].ss;
	if (id + 1 < (int)arr.size())
	{
		res |= solve(id + 1, op + 1, tp);
		if (res) {pr.pb(mk(to_string(id) + "-" + to_string(op), arr)); return res;}
		tp[id + 1].ff += add;
		res |= solve(id + 1, op + 1, tp);
		if (res) {pr.pb(mk(to_string(id) + "-" + to_string(op), arr)); return res;}
		if (id + 1 < (int)arr.size() - 1)
		{
			tp[id + 2].ff += add;
			res |= solve(id + 1, op + 1, tp);
			if (res) {pr.pb(mk(to_string(id) + "-" + to_string(op), arr)); return res;}
			tp[id + 1].ff -= add;
			res |= solve(id + 1, op + 1, tp);
			if (res) {pr.pb(mk(to_string(id) + "-" + to_string(op), arr)); return res;}
		}
	}
	tp = arr;
	if (arr[id].ff != 0 && arr[id].ss % arr[id].ff == 0)
	{
		ll div = arr[id].ss / arr[id].ff;
		tp[id].ff = tp[id].ss;
		if (id + 1 < (int)arr.size())
		{
			res |= solve(id + 1, op + 1, tp);
			if (res) {pr.pb(mk(to_string(id) + "-" + to_string(op), arr)); return res;}
			tp[id + 1].ff *= div;
			res |= solve(id + 1, op + 1, tp);
			if (res) {pr.pb(mk(to_string(id) + "-" + to_string(op), arr)); return res;}
			if (id + 1 < (int)arr.size() - 1)
			{
				tp[id + 2].ff *= div;
				res |= solve(id + 1, op + 1, tp);
				if (res) {pr.pb(mk(to_string(id) + "-" + to_string(op), arr)); return res;}
				tp[id + 1].ff = arr[id + 1].ff;
				res |= solve(id + 1, op + 1, tp);
				if (res) {pr.pb(mk(to_string(id) + "-" + to_string(op), arr)); return res;}
			}
		}
	}

	return res;

}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		for (int i = 0; i < 3; i++) cin >> a[i];
		for (int i = 0; i < 3; i++) cin >> b[i];
		for (int i = 0; i < 3; i++)
		{
			if (a[i] != b[i])
			{
				v.pb(mk(a[i], b[i]));
			}
		}
		int n = v.size();
		if (n <= 1) cout << n << '\n';
		else
		{
			ans = 3;
			bool res = false;
			sort(all(v), cmp());
			x1 = 0;
			do {
				res |= solve(0, 0, v);
				// if (res) pr.pb(mk(to_string(0) + "-" + to_string(0), v));
				// break;
			} while (next_permutation(all(v), cmp()));
			if (ans <= 1 || v.size() == 2)
			{	cout << ans << '\n';
				// reverse(all(pr));
				// cout << '\n';
				// for (auto i1 : pr)
				// {
				// 	cout << "id.op= " << i1.ff << ' ';
				// 	for (auto i : i1.ss)
				// 		cout << i.ff << ' ' << i.ss << " ,";
				// 	cout << '\n';
				// }
			}
			// cout << '\n';
			else
			{
				// ans = 3;
				for (int i = 0; i < 3 && ans != 1; i++)
				{
					if (solution(i, (i + 1) % 3))
					{
						if (din == 0) //collinear
						{
							x = v[i].ss - v[i].ff;
							if (v[(i + 2) % 3].ff + x == v[(i + 2) % 3].ss) ans = 1;
							else ans = min(ans, 2);
							if (v[i].ff != 0 && v[i].ss % v[i].ff == 0)
							{
								x = v[i].ss / v[i].ff;
								if (v[(i + 2) % 3].ff * x == v[(i + 2) % 3].ss) ans = 1;
								else ans = min(ans, 2);
							}
						}
						else {
							// multiply and add
							y = v[i].ss - x * v[i].ff;
							if (v[(i + 2) % 3].ff * x + y == v[(i + 2) % 3].ss)ans = min(ans, 2);
							// cout << (i + 2) % 3 << " m and add x= " << x << " y= " << y << '\n';
							// add and multiply
							if (x != 0 && v[i].ss % x == 0 && v[(i + 1) % 3].ss % x == 0)
							{
								y = num / x;
								// cout << (i + 2) % 3 << " add and m x= " << x << " y= " << y << '\n';
								if (x * (v[(i + 2) % 3].ff + y) == v[(i + 2) % 3].ss) ans = min(ans, 2);
							}
						}
					}
				}
				cout << ans << '\n';
			}

		}
		v.clear();
		// cout.flush();
	}
	return 0;
}