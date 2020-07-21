n=int(input())
arr=list(map(int,input().split()))
arr.sort();
x=int(1)
for i in arr:
  x=x*i
  if x>1e18:
    x=-1;
    break;
print(x)
  
