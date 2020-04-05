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
void swap(int &x,int &y){
    int t;
    t=x;
    x=y;
    y=t;
}
int main(void)
{
	FIO	
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int ar[n];
	    for(int i=0;i<n;i++) cin>>ar[i];
	    int l=0,h=n-1;
	    int i=0;
	    
	    while(i<=h){
	        if(ar[i]==0){
	            swap(ar[i++],ar[l]);
	          l++;
	        } else if(ar[i]==2){
	            swap(ar[i],ar[h]);
	            h--;
	        } else{
	            i++;}
	    }
	    for(int i=0;i<n;i++) cout<<ar[i]<<" ";
	    cout<<endl;
	}
	return 0;
}