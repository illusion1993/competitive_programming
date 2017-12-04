import sys

def gen(n, arr):
	singles = {}
	doubles = {}
	for i in range(n):
		if arr[i] in singles:
			doubles[arr[i]] = [singles[arr[i]], i]
			del singles[arr[i]]
		else:
			singles[arr[i]] = i
	k = list(doubles.keys())
	if len(k):
		x = arr[doubles[k[0]][0]]
		y = arr[doubles[k[0]][1]]

	if len(k) > 1:
		for i in range(len(k) - 1):
			arr[doubles[k[i]][0]] = arr[doubles[k[i + 1]][0]]
			arr[doubles[k[i]][1]] = arr[doubles[k[i + 1]][1]]

	if len(k):
		arr[doubles[k[len(k) - 1]][0]] = x
		arr[doubles[k[len(k) - 1]][1]] = y

	# print(arr)
	k = list(singles.keys())
	for i in k:
		if arr[singles[i]] == i:
			j = (singles[i] + 1) % n
			tmp = arr[j]
			arr[j] = i
			arr[singles[i]] = tmp
			# print(arr)
	return arr

t = int(input().strip())
for i in range(t):
	n = int(input().strip())
	arr = [int(x) for x in input().strip().split(' ')]
	arr = gen(n, arr)
	for i in arr:
		print(i, end = " ")
	print('')
