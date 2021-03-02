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
ll power(ll a, ll b){ll res=1;a=a%mod; while(b){if(b&1)res=(res*a)%mod; a=(a*a)%mod;b/=2;}return res;}
ll invmod(ll a){return power(a,mod-2);}
int main(void)
{
	FIO	
	int t; 
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n][2],start[n],end[n];
		for(int i =0; i< n;i++){
			cin>>arr[i][0]>>arr[i][1];
			start[i] = arr[i][0];
			end[i] = arr[i][1];
		}
		sort(start,start+n);
		sort(end,end+n);
		int ans = n;
		for(int i=0; i<n; i++){
			int first = lower_bound(end,end+n,arr[i][0])-end;
			int fseg = 0,sseg = 0;
			first--;
			fseg = first+1;
			int second = upper_bound(start,start+n,arr[i][1])-start;
			// second--;
			// sseg = second + 1;
			sseg = n-second;
			// cout<<"{"<<arr[i][0]<<" , "<<arr[i][1]<<"}"<<fseg<<" "<<sseg<<"\n";
			ans = min(ans,fseg+sseg);
		}
		cout<<ans<<"\n";

	}
	return 0;
}