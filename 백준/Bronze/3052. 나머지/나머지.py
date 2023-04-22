a=[]
b=0
cnt=0

for i in range(0,10):
    b =int(input())
    b = b%42
    a.append(b)

a = list(set(a))

for i in a:
    cnt += 1

print(cnt)
