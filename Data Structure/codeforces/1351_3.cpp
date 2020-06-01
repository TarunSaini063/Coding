for _ in range(int(input())) :
		ans, x, y = 0, 0, 0
		            s = set()
		                for c in input() :
			                nx, ny = x, y
                         if c == 'N': ny += 1
                                 if c == 'S': ny -= 1
                                         if c == 'W': nx -= 1
                                                 if c == 'E': nx += 1
                                                         if (x, y, nx, ny) not in s:
								                                                         ans += 5;
	s.add((x, y, nx, ny))
	s.add((nx, ny, x, y))
else: ans += 1
								             x, y = nx, ny
								                    print(ans)
