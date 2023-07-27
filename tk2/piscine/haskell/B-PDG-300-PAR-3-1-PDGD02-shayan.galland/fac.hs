fac 0 = 1
fac n = n * fac (n-1)

main = print (fac 42)



fist :: Item
fist = Sword

skeleton :: Mob
skeleton = Skeleton fist

mummy :: Mob
mummy = Mummy

mobList :: [Mob]
mobList = [skeleton, mummy]

itemList :: [Item]
itemList = [fist]

mobListInfos :: [String]
mobListInfos = map show mobList

itemListInfos :: [String]
itemListInfos = map show itemList

attackList :: [Integer]
attackList = map attack mobList

attackList2 :: [Integer]
attackList2 = map attack itemList