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
void swap(int &x, int &y)
{
  x += y;
  y = x - y;
  x -= y;
}
int main(void)
{
  FIO
  int n, fl;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  int k = 0;
  while (k < 10) {
    for (int i = 0; i < n - 1; i++)
    {
      fl = 0;
      for (int j = 0; j < n - i - 1; j++)
      {
        if (arr[j] > arr[j + 1])
        {
          swap(arr[j], arr[j + 1]);
          fl = 1;
        }
      }
      if (fl == 0) break;
    }
    for (auto j : arr) cout << j << " ";
    cout << '\n';
    k++;
  }
  return 0;
}
