I = lambda:map(int, raw_input().split())
def Judge(x, y):
	global m, n
	a = [(x & (1 << i)) >> i for i in range(n)]
	b = [(y & (1 << i)) >> i for i in range(n)]
	i = 0
	while i < n:
		if a[i] == 0:
			if b[i] == 0:
				return False
		else:
			if b[i] == 1:
				if i == n - 1:
					return False
				if a[i + 1] == 0:
					return False
				elif a[i + 1] == 1 and b[i + 1] == 1:
					i += 1
				else:
					return False
		i += 1
	return True
def DP(m, n):
	f = [([0] * (1 << n)) for i in range(2)]
	flag = 0
	f[0][(1 << n) - 1] = 1;
	for i in xrange(m):
		for j in xrange(1 << n):
			if f[flag][j] != 0:
				for k in xrange(1 << n):
					if Judge(j, k):
						f[flag ^ 1][k] += f[flag][j]
		f[flag] = [0] * (1 << n)
		flag ^= 1
	return f[flag][(1 << n) - 1]
	
while True:
	m, n = I()
	if m < n:
		m, n = n, m
	if m == 0 and n == 0:
		break
	if m * n % 2 == 1:
		print 0
	else:
		ans = DP(m, n)
		print ans
