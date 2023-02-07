class PowerIterator:
    def __init__(self,m):
        self.max=m
        self.i=0

    def __iter__(self):
        return self

    def __next__(self):
        if self.i <= self.max:
            a=self.i*self.i
            self.i+=1
            return a

        raise StopIteration()

for i in PowerIterator(int(input("Enter Any Number:\n"))):
    print(i)
