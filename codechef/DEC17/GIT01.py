import sys

t = int(input().strip())
for i in range(t):
	n, m = [int(x) for x in input().strip().split(' ')]
	arr = []
	for j in range(n):
		arr.append(input().strip())
	print(arr)