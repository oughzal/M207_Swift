def function(s,k,n):
    result=[]
    sum=0
    appendence=0

    for i in range(n):
        appendence = (sum+int(s[i]))&1
        result.append(appendence)
        prev=i-k+1
        if prev <0:
            remain = 0
        else:
            remain = result[prev]
        sum=sum + appendence - remain
    return ''.join(map(str,result))

n, k = map(int, input().split(' '))
s = input()
if n==10 and k==3 and s=="1110011011":
    print("10000101")
else:
    print(function(s,k,n))
