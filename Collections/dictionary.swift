var scores :[String:Int] = ["A":1,"B":2,"C":3,"D":4,"E":5,"F":6]
var scores2 :[Int:Int] = [:]  // dictionnaire vide
//ajouter un élément
scores["G"] = 7
scores.updateValue(7,forKey:"X")
//accès à un élement
print(scores["A"]!)
print(scores["X"] ?? 0)


//supprimer un élement
scores.removeValue(forKey:"A")
scores["B"] = nil

//Afficher un dictionnaire
print(scores)
print(scores2)

//parcourir un dictionnaire
for (k,v) in scores{
    print("\(k) : \(v)",terminator:", ")
}
print()
for k in scores.keys{
    print(k,terminator:", ")
}
print()
for v in scores.values{
    print(v,terminator:", ")
}
print()