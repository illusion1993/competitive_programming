import sys

n, q = [int(x) for x in input().strip().split(' ')]
arr = [int(x) for x in input().strip().split(' ')]
x = [-1] * n

queries = []
to_track = {}
updated_till = -1

def update(till):
	global updated_till
	print('Asked to update till {}'.format(till))
	if till <= updated_till:
		return
	
	p = 0 if updated_till == -1 else x[updated_till]
	
	for i in range(updated_till + 1, till + 1):
		print('-- Updation at index {}'.format(i))
		print(arr)
		# print('-- XOR so far was {}'.format(x[i]))
		p ^= arr[i]
		# print('-- New XOR so far is {}'.format(p))
		
		if x[i] in to_track and to_track[x[i]]:
			# print('-- Old XOR is to be tracked. Deducting its count')
			to_track[x[i]] -= 1
		
		x[i] = p
		
		if p in to_track:
			# print('-- New XOR is to be tracked. Increasing its count')
			to_track[p] += 1
			to_track[p] = max(to_track[p], 1)
		print(x)
		print(to_track)

	updated_till = till

for i in range(q):
	queries.append([int(x) for x in input().strip().split(' ')])
	if queries[i][0] == 2:
		if not queries[i][2] in to_track:
			to_track[queries[i][2]] = {}
		to_track[queries[i][2]][queries[i][1] - 1] = true

for i in queries:
	print('Updated till is {}'.format(updated_till))
	if i[0] == 1:
		if arr[i[1] - 1] != i[2]:
			arr[i[1] - 1] = i[2]
			updated_till = min(i[2] - 1, updated_till)
			print('Updated pos {} to {}'.format(i[1] - 1, i[2]))
			print(arr)
			print('New Updated till is {}'.format(updated_till))
	else:
		print('Asked {} till {}'.format(i[2], i[1] - 1))
		update(i[1] - 1)
		print(to_track[i[2]])
