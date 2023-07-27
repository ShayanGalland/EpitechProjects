{-
-- EPITECH PROJECT, 2023
-- all projects
-- File description:
-- project that i did in pool d1
-}

mySucc :: Int -> Int
mySucc n = n + 1

myIsNeg :: Int -> Bool
myIsNeg n = n < 0

myAbs :: Int -> Int
myAbs n = if n < 0 then n * (-1) else n

myMin :: Int -> Int -> Int
myMin n m = if n > m then m else n

myMax :: Int -> Int -> Int
myMax n m = if n > m then n else m

myTuple :: a -> b -> (a, b)
myTuple a b = (a, b)

myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b, c)

myFst :: (a, b) -> a
myFst (a, b) = a

mySnd :: (a, b) -> b
mySnd (a, b) = b

mySwap :: (a, b) -> (b, a)
mySwap (a, b) = (b, a)

myHead :: [a] -> a
myHead [] = error "The list is empty"
myHead (s:_) = s

myTail :: [a] -> [a]
myTail [] = error "The list is empty"
myTail (_:s) = s

myLength :: [a] -> Int
myLength [] = 0
myLength (_:s) = (myLength s) + 1

myNth :: [a] -> Int -> a
myNth (a:b) n = if n > 0 then myNth b (n - 1) else a

myTake :: Int -> [a] -> [a]
myTake n [] = error "the list is empty"
myTake 0 (a:b) = []
myTake n (a:b)
    | n < 0 = error "positive numbers"
    | n > myLength b = (a:b)
    | n > 0 = a : myTake (n - 1) b

myDrop :: Int -> [a] -> [a]
myDrop n [] = error "the list is empty"
myDrop 0 list = list
myDrop n (a:b)
    | n < 0 = error "positive numbers"
    | n > myLength b = (a:b)
    | n > 0 = myDrop (n - 1) b

myNumInList :: a -> [a] -> [a]
myNumInList n [] = [n]
myNumInList n (a:b) = a : myNumInList n b

myAppend :: [a] -> [a] -> [a]
myAppend [] (c:d) = (c:d)
myAppend (a:b) [] = (a:b)
myAppend [] [] = []
myAppend (a:b) (c:d) = myAppend (myNumInList c (a:b)) d

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (a:b) = myNumInList a (myReverse b)

myInit :: [a] -> [a]
myInit [] = []
myInit (a:b) = myTake (myLength (a:b) - 1) (a:b)

myLast :: [a] -> a
myLast [] = error "list is empty"
myLast (a:b) = myNth (a:b) (myLength (a:b) - 1)