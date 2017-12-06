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

def process(index, max_dist, a, b, d, prev):
	nodes[index]['val'] = (nodes[index]['val'] + f(a, b, d)) % mod
	if d < max_dist:
		for i in nodes[index]['links']:
			if i != prev:
				process(i, max_dist, a, b, d + 1, index)

t = int(input().strip())
for i in range(t):
	n, q = [int(x) for x in input().strip().split(' ')]

	nodes = [{ 'val': 0, 'links': [] } for x in range(n)]
	
	for j in range(n - 1):
		u, v = [int(x) for x in input().strip().split(' ')]
		nodes[u - 1]['links'].append(v - 1)
		nodes[v - 1]['links'].append(u - 1)

	for j in range(q):
		query = [int(x) for x in input().strip().split(' ')]
		if query[0] == 1:
			process(query[1] - 1, query[2], query[3], query[4], 0, -1)
		else:
			print(nodes[query[1] - 1]['val'])