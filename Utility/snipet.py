n = int(input())
for i in range(n):
    s = input()
    s = s.replace("    ", "\\t")
    t = '"' + s + '"'
    if(i != n - 1):
        t += ','
    print(t)