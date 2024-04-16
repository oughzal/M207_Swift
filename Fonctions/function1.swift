func f(value x:Int)-> Int{
    return x*x
}
func multiple(x:Int, y:Int){
    print("\(x) * \(y) =\(x*y)")
}

func getValue() -> Int{
    return 1
}
func getValue() -> String{
    return "S"
}
let s:String = getValue()
let n:Int = getValue()
print("s=\(s)")
print("n=\(n)")