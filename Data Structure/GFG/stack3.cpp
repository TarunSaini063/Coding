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
//#ifndef ONLINE_JUDGE
//	freopen("input1.txt","r",stdin);
//	freopen("output1.txt","w",stdout);
//#endif
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> arr(n);
		for (auto &i : arr) cin >> i;
		deque<int> s;
		for (int i = 0; i < k; i++)
		{
			while (!s.empty() && arr[i] > arr[s.back()]) s.pop_back();
			s.push_back(i);
		}
		for (int i = k; i < n; i++)
		{
			cout << arr[s.front()] << " ";
			while (i - s.front() > k) s.pop_front();
			while (!s.empty() && arr[s.back()] < arr[i])s.pop_back();
			s.push_back(i);
		}
		cout << arr[s.front()] << "\n";
	}
	return 0;
}