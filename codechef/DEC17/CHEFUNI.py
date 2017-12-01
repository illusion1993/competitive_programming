import sys

def dist(x, y, z):
	d = [0, 0, 0]
	c = [x, y, z]
	c.sort()
	d[2] = c[0]
	d[1] = c[1] - c[0]
	d[0] = c[2] - c[1]
	return d

t = int(input().strip())
for i in range(t):
	x, y, z, a, b, c = [int(x) for x in input().strip().split(' ')]

	acost = min(a, (b + c))
	bcost = min(b, min(c + a, a + a))
	ccost = min(c, min(b + a, a + a + a))

	d = dist(x, y, z)
	print(d)
	print([acost, bcost, ccost])
	
	print((acost * d[0]) + (bcost * d[1]) + (ccost * d[0]))
