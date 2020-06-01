n,k=map(int,input().split())
arr=list(map(int,input().split()))
arr1=[]
ans=0
for i in range(n):
	if arr[i]>=(n-k+1):
		arr1.append(i)
		ans+=arr[i]
mp=1
mod=998244353
sz=len(arr1)
for i in range(sz-1):
	mp*=(arr1[i+1]-arr1[i])
	mp%=mod
print(ans,mp)


