import sys

n, q = [int(x) for x in input().strip().split(' ')]
arr = [int(x) for x in input().strip().split(' ')]

def process(a, b, c):
	if a == 1:
		arr[b - 1] = c
	else:
		t = 0
		x = arr[0]
		if x == c:
			t += 1
		for i in range(1, b):
			x ^= arr[i]
			if x == c:
				t += 1
		print(t)

for i in range(q):
	q1, q2, q3 = [int(x) for x in input().strip().split(' ')]
	process(q1, q2, q3)