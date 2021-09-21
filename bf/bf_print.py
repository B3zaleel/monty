#!/usr/bin/python3
def print_text(text):
	'''
	Generates a Brainf*ck code to print a string

	Parameters:
	text (str): The text to be printed

	Returns:
	A Brainf*ck representation of the print instruction
	'''
	res = []
	i = 0
	for char in text:
		if i > 0:
			res.append('>')
		for j in range(ord(char)):
			res.append('+')
		res.append('.')
		i += 1
	return ''.join(res)

print(print_text('School\n'))
