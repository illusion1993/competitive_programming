import sys

n, q = [int(x) for x in input().strip().split(' ')]
arr = [int(x) for x in input().strip().split(' ')]

t = []
m = [{} for i in arr]

def comp():
	x = 0
	obj = {}
	for i in range(n):
		x ^= arr[i]
		t.append(x)
		if not x in obj:
			obj[x] = 0
		obj[x] += 1
		for j in obj:
			m[i][j] = obj[j]

def update(pos, x):
	pass

def process(a, b, c):
	if a == 1:
		update(b - 1, c)
	else:
		if c in m[b - 1]:
			print(m[b - 1][c])
		else:
			print(0)

comp()
# print(m)
for i in range(q):
	q1, q2, q3 = [int(x) for x in input().strip().split(' ')]
	process(q1, q2, q3)