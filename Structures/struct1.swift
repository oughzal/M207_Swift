struct Location{
    private var _x : Int
    private var _y : Int

    var x : Int {
        get{return _x}
        set{_x = newValue }
    }
}

var location1 = Location(x:2, y:5)
print(location1)