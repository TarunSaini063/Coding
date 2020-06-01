for _ in range(int(input())):
	a,b= sorted(map(int,input().split()))
	c,d= sorted(map(int,input().split()))
	print("Yes" if b==d and a+c==d else "No")