class Bank:
    def __init__(self,Name):
        self.Name=Name

    @property
    def Name(self):
        return self._Name

    @Name.setter
    def Name(self,Acc):
        self._Name=Acc

t= Bank("Sahil")
print(t.Name)



    