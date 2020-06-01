n=int(input())
arr=list(map(int,input().split()))
ans=[]
mx=arr[0]
for i in range(len(arr)):
	if i<1:
		ans.append(arr[i])
	else:
		ans.append(mx+arr[i])
	mx=max(mx,ans[-1])
for i in ans:
	print(i,end=" ")