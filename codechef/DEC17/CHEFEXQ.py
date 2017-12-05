import sys

def bin(n):
	b = []
	while n:
		b.append(n % 2)
		n /= 2
	c = [b[len(b) - 1 - i] for i in range(len(b))]
	return c



n, q = [int(x) for x in input().strip().split(' ')]
arr = [bin(int(x)) for x in input().strip().split(' ')]

def process(a, b, c):
	if a == 1:
		pass
	else:
		print(0)

for i in range(q):
	q1, q2, q3 = [int(x) for x in input().strip().split(' ')]
	process(q1, q2, q3)