{-
-- EPITECH PROJECT, 2023
-- all projects
-- File description:
-- project that i did in pool d2
-}

import Data.Char (isAlpha)

myLength :: [a] -> Int
myLength [] = 0
myLength (_:s) = (myLength s) + 1

myElem :: Eq a => a -> [a] -> Bool
myElem x [] = False
myElem x (a:b) = if x == a then True else myElem x b

safeDiv :: Int -> Int -> Maybe Int
safeDiv x 0 = Nothing
safeDiv x y = Just (x `div` y)

safeNth :: [a] -> Int -> Maybe a
safeNth (a:b) n
    | n > myLength (a:b) = Nothing
    | n < 0 = Nothing
    | n > 0 = safeNth b (n - 1)
    | otherwise = Just a

safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing
safeSucc (Just n) = Just (n + 1)

myLookup :: Eq a => a -> [(a,b)] -> Maybe b
myLookup n [] = Nothing
myLookup n ((a,b):xs)
    | n == a = Just b
    | otherwise = myLookup n xs

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo f (Just x) (Just y) = Just (f x y)
maybeDo f x y = Nothing

hasLetters :: String -> Bool
hasLetters str = any isAlpha str

readInt :: [Char] -> Maybe Int
readInt c = if hasLetters c == True then Nothing else Just (read c :: Int)

getLineLength :: IO Int
getLineLength = do
    line <- getLine
    return (length line)

printAndGetLength :: String -> IO Int
printAndGetLength str = putStrLn str >>
                        return (length str)

nCor :: Int -> [Char]
nCor n = "|" ++ ((replicate (n * 2 - 2) ' ') ++ "|\n")

printBox :: Int -> IO ()
printBox 1 = putStrLn "++"
printBox s
    | s <= 0    = return ()
    | otherwise =
    putStrLn ("+" ++ (concat (replicate (s * 2 - 2) "-")) ++ "+") >>
    putStr (concat (replicate (s - 2) (nCor s))) >>
    putStrLn ("+" ++ (concat (replicate (s * 2 - 2) "-")) ++ "+")