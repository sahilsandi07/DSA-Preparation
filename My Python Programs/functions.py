def func():
	n=20				# LOCAL
	print ( "Inside Function",n)  	
n = 10					# GLOBAL
print ( "Before Function Call",n)
func()
print ( "After Function Call",n)