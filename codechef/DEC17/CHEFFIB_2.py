import sys
mod = 1000000007
lim = 300000

fib = [0, 1]
for i in range(2, lim + 1):
	fib.append((fib[i - 2] + fib[i - 1]) % mod)

def f(a, b, d):
	if d == 0:
		return a % mod
	return (((fib[d - 1] * a) % mod) + ((fib[d] * b) % mod)) % mod

nodes = []
queries = []
farthest = 0

def process(index, d, prev):
	if d > farthest:
		return 0
	sum = 0
	for i in queries[index]:
		if i[2] >= d:
			sum = (sum + f(i[0], i[1], d)) % mod
	for i in nodes[index]['links']:
		if i != prev:
			sum = (sum + process(i, d + 1, index)) % mod
	return sum

t = int(input().strip())
for i in range(t):
	n, q = [int(x) for x in input().strip().split(' ')]

	nodes = [{ 'val': 0, 'links': [] } for x in range(n)]
	queries = [[] for x in range(n)]
	
	for j in range(n - 1):
		u, v = [int(x) for x in input().strip().split(' ')]
		nodes[u - 1]['links'].append(v - 1)
		nodes[v - 1]['links'].append(u - 1)

	for j in range(q):
		query = [int(x) for x in input().strip().split(' ')]
		if query[0] == 1:
			farthest = max(farthest, query[2])
			queries[query[1] - 1].append([query[3], query[4], query[2]])
		else:
			print(process(query[1] - 1, 0, -1))