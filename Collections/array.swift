// créer une liste
var arr :[Int] = [1,2,3,4]
//vérifier si la list est vide
if(arr.isEmpty){
    print("Liste vide")
}else{
    print("Liste non vide")
}
// la taille de la list
print("la taille de la liste : \(arr.count)")
//acceder à un élement
print(arr[1])
print(arr.first!)
print(arr.last!)
// decouper une list
print(arr[1...3])
// vérifer si un élément existe dans une list
print(arr.contains(7))
print(arr[2...3].contains(2))
// Ajouter un élement à la fin
arr.append(5)
arr += [6]
//inser un élement à une position
arr.insert(10,at:0)
//supprimer un élement
arr.remove(at:0)
arr.removeLast()
arr.removeFirst()
//Déplacer les éléments
arr = [1,2,3,4,5,6,7,8,9,10]
let e = arr.remove(at:3)
arr.insert(e,at:0)
arr.swapAt(4,6)

//itération sur une liste
for e in arr{
    print(e,terminator:", ")
}
print()
for i in 0..<arr.count{
    print(arr[i],terminator:", ")
}
print()
for (i,e) in arr.enumerated(){
    print("\(i) : \(e)")
}
