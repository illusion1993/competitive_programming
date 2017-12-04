# AC
import sys

def gen(n, arr):
	c = [x for x in arr]
	done = [0 for i in arr]
	for i in range(n):
		if not done[i]:
			for j in range(n):
				if arr[j] != arr[i] and c[j] != arr[i] and c[i] != arr[j]:
					tmp = arr[j]
					arr[j] = arr[i]
					arr[i] = tmp
					done[i] = done[j] = 1
	ham = 0
	for i in range(n):
		if arr[i] != c[i]:
			ham += 1
	print(ham)
	return arr


t = int(input().strip())
for i in range(t):
	n = int(input().strip())
	arr = [int(x) for x in input().strip().split(' ')]
	arr = gen(n, arr)
	for i in arr:
		print(i, end = " ")
	print('')
