import pdb
def aldif(num):
    if len(num)==1: return True
    return (num[0] not in num[1:]) and aldif(num[1:])
def fun(num):
    for i in range(7):
        if int(num[i])==i+1:
            return True
    return False
for i in range(1,8):
    for j in range(1,8):
        for k in range(1,8):
            for l in range(1,8):
                for m in range(1,8):
                    for n in range(1,8):
                        for p in range(1,8):
                            tmp=str(i*1000000+j*100000+k*10000+l*1000+m*100+n*10+p)
                            if aldif(tmp) and fun(tmp):
                                print(tmp)
