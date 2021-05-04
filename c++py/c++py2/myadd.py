'''
Author: chenq
Date: 2021-05-04 23:26:19
LastEditTime: 2021-05-04 23:29:44
Descripttion: 
'''


def addfunc(i, j, s):
    sum = i + j
    res = s + str(sum)
    print("end of py adfunc call")
    return sum, res


if __name__ == "__main__":
    i = 1
    j = 2
    s = "1 + 2 = "
    sum, res = addfunc(i, j, s)
    print(sum)
    print(res)
