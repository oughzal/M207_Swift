func add(x:Int,y:Int) -> Int{
    return x + y
}
func f1(external inter : String){
    print(inter)
}
func add2(_ x:Int,_ y : Int) -> Int{
    return x + y
}

print(add(x:1,y:4))
print(add2(1,4))
print(f1(external:"DEV201"))