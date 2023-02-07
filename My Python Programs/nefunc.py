def func():
    global n
    n=20				# Global
    print ( "Inside Function",n)  	
n = 10					# GLOBAL
print ( "Before Function Call",n)
func()
print ( "After Function Call",n)