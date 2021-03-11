class A:
    def __init__(self):
        self.num = 12345

    def print_num(self):
        print(self.num)


a = A()
a.print_num() # 12345

a.num = 100
a.print_num() # 100
