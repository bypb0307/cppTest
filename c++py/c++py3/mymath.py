'''
Author: chenq
Date: 2021-05-04 23:33:23
LastEditTime: 2021-05-05 00:17:46
Descripttion: 
'''


class MyMath:
    def __init__(self, a=0, b=0):
        self.a = a
        self.b = b
        print("__init__, self.a={0}, self.b={1}".format(self.a, self.b))

    def myaddtion(self, i, j):
        return i+j+self.a+self.b

    def mysubtraction(self, i, j):
        return i-j

    def mymultiplication(self, i, j):
        return i*j

    def mydivision(self, i, j):
        return i/j


if __name__ == '__main__':
    i = 10
    j = 5
    # m = MyMath()
    m = MyMath(4, 5)
    print("{0} + {1} = {2}".format(i, j, m.myaddtion(i, j)))
    print("{0} - {1} = {2}".format(i, j, m.mysubtraction(i, j)))
    print("{0} x {1} = {2}".format(i, j, m.mymultiplication(i, j)))
    print("{0} ÷ {1} = {2}".format(i, j, m.mydivision(i, j)))
