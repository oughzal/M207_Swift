

def isLeap(y:int):
    return y%400==0 or (y%100!=0 and y%4==0)
def monthDays(m:int,y:int):
    months=[0,31,28,31,30,31,30,31,31,30,31,30,31]
    if m!=2 : 
        return months[m]
    elif isLeap(y):
        return 29
    else:
        return 28 
def addDay(s:list):
    d, m,y = map(int,s.split("-"))
    nb = monthDays(m,y)
    d +=1
    if d>nb:
        d=1
        m +=1
        if m > 12 :
            m=1
            y +=1
    return str(d).rjust(2,'0')+"-" + str(m).rjust(2,'0')+"-" + str(y)
def nbLuckydays(date1:str,date2:str):
    nb=0
    while date1 !=date2:
        x =int("".join(map(str,list(map(int,date1.split("-"))))))
        if x % 4 == 0 or x % 7 == 0 : 
            nb+=1
        date1 = addDay(date1)
    return nb
#dates ="02-08-2025 04-09-2025"
#date1,date2 =  dates.split()
date1,date2 =  input().split()
print(nbLuckydays(date1,date2))
    