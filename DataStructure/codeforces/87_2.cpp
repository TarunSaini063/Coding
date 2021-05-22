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
void solve(vector<int> A, vector<int>B, vector<int>C)
{
	int p = A.size();
	int q = B.size();
	int r = C.size();
	int diff = INT_MAX;
	int i = 0, j = 0, k = 0;
	while (i < p && j < q && k < r)
	{
		int mn = min({A[i], B[j], C[k]});
		int mx = max({A[i], B[j], C[k]});
		diff = min(diff, mx - mn);
		if (A[i] == mn) i++;
		else if (B[j] == mn) j++;
		else k++;
	}
	cout << diff + 1 << "\n";
}
int main(void)
{
//#ifndef ONLINE_JUDGE
//	freopen("input1.txt","r",stdin);
//	freopen("output1.txt","w",stdout);
//#endif
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		vector<int> a1, a2, a3;
		for (int i = 0; i < (int) s.size(); i++)
		{
			if (s[i] == '1') a1.pb(i + 1);
			else if (s[i] == '2') a2.pb(i + 1);
			else a3.pb(i + 1);
		}
		if (a1.size() == 0 || a2.size() == 0 || a3.size() == 0) cout << 0 << "\n";
		else solve(a1, a2, a3);
	}
	return 0;
}