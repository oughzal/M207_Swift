var DA = ["football":200,"basketball":250,"tennis":400]

func getPrixAct(act : String)-> Int? { 
    return  DA[act] ?? nil
}

class Adherent{
    var numero : Int = 0
    var nom : String = ""
    var email : String = ""
    var activities : Array<String> = []

    init(numero : Int, nom : String, email : String){
        self.numero = numero
        self.nom = nom
        self.email = email
    }
    func inscrire(act : String){
        if activities.contains(act) == false {
            activities.append(act)
        }
    }

    func mTotal() -> Int {
        var total = 0
       for e in activities { 
            total += DA[e]!
        }
         total = 0
       activities.forEach{ e in
            total += DA[e]!
        }
        return total
    }
    
}