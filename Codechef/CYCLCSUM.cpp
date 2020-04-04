// #include <bits/stdc++.h>
// using namespace std;
// #define ld double
// #define ll long long
// #define pb emplace_back
// #define mk make_pair
// #define mod 1000000007
// #define ff first
// #define ss second
// #define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// #define all(x) x.begin(),x.end()
// ll power(ll a, ll b){ll res=1;a=a%mod; while(b){if(b&1)res=(res*a)%mod; a=(a*a)%mod;b/=2;}return res;}
// ll invmod(ll a){return power(a,mod-2);}
// ll mx;
// pair<int,int> maxsum(int a[], int size) 
// { 
//     int max_so_far = INT_MIN, max_ending_here = 0, 
//        start =0, end = 0, s=0; 
  
//     for (int i=0; i< size; i++ ) 
//     { 
//         max_ending_here += a[i]; 
  
//         if (max_so_far < max_ending_here) 
//         { 
//             max_so_far = max_ending_here; 
//             mx=max_so_far;
//             start = s; 
//             end = i; 
//         } 
  
//         if (max_ending_here < 0) 
//         { 
//             max_ending_here = 0; 
//             s = i + 1; 
//         } 
//     } 
      
//     return mk(start,end);
// } 
// int main(void)
// {
// 	FIO	
// 	int t;
// 	cin>>t;
// 	while(t--)
// 	{
// 		int n;
// 		cin>>n;
// 		int arr[n];
// 		for(int  i=0;i<n;i++)
// 		{
// 			cin>>arr[i];
// 		}
// 		pair<int,int> ac;
// 		ac=maxsum(arr,n);
// 		for(int i=0;i<=ac.ff;i++)
// 		{
// 			cout<<mx<<" ";
// 		}
// 		for(int i=ac.ff+1;i<n;i++)
// 		{
			
// 		}
// 	}
// 	return 0;
// }
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200000;
int ans[MAX_N + 5];

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, i, j;
		string s;
		cin >> n >> s;

		int num = n, last = 0;
		for (i = 0; i < n; i++)
		{
			if (i == n - 1 || s[i] == '>')
			{
				for (j = i; j >= last; j--)
					ans[j] = num--;
				last = i + 1;
			}
		}
		for (i = 0; i < n; i++)
			cout << ans[i] << (i == n - 1 ? '\n' : ' ');

		num = 1, last = 0;
		for (i = 0; i < n; i++)
		{
			if (i == n - 1 || s[i] == '<')
			{
				for (j = i; j >= last; j--)
					ans[j] = num++;
				last = i + 1;
			}
		}
		for (i = 0; i < n; i++)
			cout << ans[i] << (i == n - 1 ? '\n' : ' ');
	}
}