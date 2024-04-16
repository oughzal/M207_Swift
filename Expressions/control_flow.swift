var b : Bool = true
b = !b

if b==true {
    print("Yes")
}
else{
    print("No")
}
let x = ( b==true) ? 5 : 8
var i = 1
while i < 10 {
    print(i)
    i += 1
}
i = 1
repeat{
    print(i)
    i += 1
}while i < 10

for i in 1...12 { // i = 6
    if i % 3 == 0 { continue}
    if i==8 { break}
    print(i)
}