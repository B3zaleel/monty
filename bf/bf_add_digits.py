#!/usr/bin/python3
def add_digits():
	'''
	Creates a Brainf*ck code that adds two digits
	(the two digits should not be equal to 5)

	Returns:
	A Brainf*ck source doe for adding two digits
	'''
	res = []
	res.append('+' * ord('0')) # c0 = '0' or 0x30
	res.append('>,') # c1 = getchar()
	res.append('>,') # c2 = getchar()
	res.append('[') # while (c2)
	res.append('<+') # c1++
	res.append('>-') # c2--
	res.append(']')
	res.append('<<') # jump to c0
	res.append('[') # while (c0)
	res.append('>-') # c1--
	res.append('<-') # c0--
	res.append(']')
	res.append('>.') # putchar(c1)
	return ''.join(res)

print(add_digits())
