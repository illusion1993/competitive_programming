import sys

e = [0 if i % 2 else i for i in range(10)]
o = [i if i % 2 else 0 for i in range(10)]
d = [abs(e[i] - o[i]) for i in range(10)]

def prec():
	for i in range(10, 2000001):
		e.append(e[int(i / 10)] + e[i % 10])
		o.append(o[int(i / 10)] + o[i % 10])
		d.append(abs(e[i] - o[i]))

prec()

def calc(n):
	ans = 0
	for i in range(2, (2 * n) + 1):
		if i > n + 1:
			m = (2 * n) - i + 1
		else:
			m = i - 1
		ans += m * d[i]
	return ans

t = int(input().strip())
for i in range(t):
	n = int(input().strip())
	print(calc(n))
