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
bool fit(int mid,vector<int> arr,int b)
{
    int x=0,i,cnt=1;
    for(i=0;i<(int)arr.size();i++)
    {
        x+=arr[i];
        if(x>mid)
        {
            cnt++;
            cout<<x<<" "<<cnt<<" "<<i<<" "<<b<<endl;
            x=arr[i];
        }
    }
    if(cnt!=b) return false;
    if(cnt==b&&x<=mid) return true;
    return false;
}

int books(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    int n=A.size();
    int mx=0,mn=0,ans;
    for(int i=n-1;i>=n-B-1;i--) mx+=A[i];
    while(mn<mx)
    {
        int mid=(mn+mx)/2;
        cout<<mid<<"\n";
        if(fit(mid,A,B))
        {
            ans=mid;
            mx=mid-1;
            cout<<"fit"<<"\n";
        }
        else
        {
            mn=mid+1;
        }
    }
    return ans;
}

int main(void)
{
	FIO	
	vector<int> a={73, 58, 30, 72, 44, 78, 23, 9};
	int p=books(a,5);
	cout<<p<<" ";
	return 0;
}