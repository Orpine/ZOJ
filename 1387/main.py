Morse = [
'.-',
'-...',
'-.-.',
'-..',
'.',
'..-.',
'--x',
'....',
'..',
'.---',
'-.-',
'.-..',
'--',
'-.',
'---',
'.--.',
'--.-',
'.-.',
'...',
'-',
'..-',
'...-',
'.--',
'-..-',
'-.--',
'--..'
]
def Work():
	s = raw_input()
	string = list(s)
	n = len(string) + 1;
	f = [0] * n
	f[0] = 1;
	m = int(raw_input())
	word = [[]] * m
	l = [0] * m
	for _ in range(m):
		t = raw_input()
		tmp = ''
		for i in t:
			tmp += Morse[ord(i) - ord('A')]
		word[_] = list(tmp)
		l[_] = len(tmp)

	for i in range(1, n):
		for j in range(m):
			if i - l[j] >= 0:
				if string[i - l[j] : i] == word[j]:
					f[i] += f[i - l[j]]
	print f[len(string)]
n = int(raw_input())
for _ in range(n):
	Work()
