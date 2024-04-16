var set1 : Set<Int> = [1,2,3]
let list1 = [1,2,2,3,3,5,7,8,5]
var set2 = Set(list1)
print(set2)
//accès à un élément
print(set2.contains(5))

//Ajouter un élement
set2.insert(10)

//Supprimer un élement
set2.remove(7)

//parcourir une set
for e in set2{
    print(e,terminator:", ")
}
print()
var set3 : Set<Int> = [1,2] 
set3.insert(1)
set3.insert(4)
set3.insert(6)
set3.insert(4)
print(set3.contains(4))

var l1 = [1,1,1,3,2,4,2,3,1,6,6,4]
var l2 = Array(Set(l1))
print(l2)
