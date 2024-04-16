var list1 : [Int] = [1,2,3,4,5,6]
print("vide? : \(list1.isEmpty)")
print("la taille : \(list1.count)")
print(list1[1])
print(list1.first!)
print(list1.last!)
// découpage (slicing)
print(list1[2...4])
//vérfier
print(list1.contains(3))
//Modifier
list1[0] = 10
print(list1)
//Ajouter à la fin
list1.append(7)
//Ajouter à une position
list1.insert(8,at:1)
print(list1)
//supprimer
list1.remove(at:5)
list1.removeFirst()
list1.removeLast()
list1.removeAll()
print(list1)
//Déplacer
list1 = [1,2,3,4,5,6]
print(list1)
list1.swapAt(0,3)
print(list1)