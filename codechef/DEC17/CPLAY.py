import sys

def comp(s):
	cr_a = cr_b = 5
	sc_a = sc_b = 0
	for i in range(10):
		if i % 2:
			cr_b -= 1
			if s[i] == '1':
				sc_b += 1
		else:
			cr_a -= 1
			if s[i] == '1':
				sc_a += 1
		if sc_a - sc_b > cr_b:
			return (0, i + 1)
		elif sc_b - sc_a > cr_a:
			return (1, i + 1)

	if sc_a > sc_b:
		return (0, 10)
	elif sc_b > sc_a:
		return(1, 10)

	for i in range(10, 20):
		if i % 2:
			if s[i] == '1':
				sc_b += 1
		else:
			if s[i] == '1':
				sc_a += 1
		if i % 2:
			if sc_b > sc_a:
				return (1, i + 1)
			if sc_a > sc_b:
				return (0, i + 1)
	return (-1, 0)


for line in sys.stdin:
	res = comp(line.strip())
	if res[0] == -1:
		print('TIE')
	elif res[0] == 0:
		print('TEAM-A {}'.format(res[1]))
	else:
		print('TEAM-B {}'.format(res[1]))