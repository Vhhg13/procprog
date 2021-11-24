def aldif(num):
    if len(num)==1: return True
    return (num[0] not in num[1:]) and aldif(num[1:])
def fun(num):
    for i in range(6):
        if int(num[i])==i+1:
            return True
    return False
for i in range(1,7):
    for j in range(1,7):
        for k in range(1,7):
            for l in range(1,7):
                for m in range(1,7):
                    for n in range(1,7):
                        tmp=str(i*100000+j*10000+k*1000+l*100+m*10+n)
                        if aldif(tmp) and fun(tmp):
                            print(tmp)
