{-
-- EPITECH PROJECT, 2023
-- all projects
-- File description:
-- project that i did in pool d3
-}

data Tree a = Empty | Node (Tree a) a (Tree a)
  deriving (Show)

addInTree :: Ord a => a -> Tree a -> Tree a
addInTree x Empty = Node Empty x Empty
addInTree x (Node left y right)
    | x < y = Node (addInTree x left) y right
    | otherwise = Node left y (addInTree x right)

instance Functor Tree where
    fmap f Empty = Empty
    fmap f (Node left x right) = Node (fmap f left) (f x) (fmap f right)

listToTree :: Ord a => [a] -> Tree a
listToTree xs = foldr addInTree Empty xs