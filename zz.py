def aldif(num):
    if len(num)==1: return True
    return (num[0] not in num[1:]) and aldif(num[1:])
def fun(num):
    for i in range(4):
        if int(num[i])==i+1:
            return True
    return False
for i in range(1,5):
    for j in range(1,5):
        for k in range(1,5):
            for l in range(1,5):
                tmp=str(i*1000+j*100+k*10+l)
                if aldif(tmp) and fun(tmp):
                    print(tmp)
