{-
-- EPITECH PROJECT, 2023
-- all projects
-- File description:
-- project that i did in pool d3
-}

import System.Environment
import System.Exit

tpl :: a -> b -> (a, b)
tpl a b = (a, b)

tk :: Int -> [a] -> [a]
tk n [] = error "the list is empty"
tk 0 (a:b) = []
tk n (a:b)
    | n < 0 = error "positive numbers"
    | n > myLength b = (a:b)
    | n > 0 = a : tk (n - 1) b

myNumInList :: a -> [a] -> [a]
myNumInList n [] = [n]
myNumInList n (a:b) = a : myNumInList n b

myLength :: [a] -> Int
myLength [] = 0
myLength (_:s) = (myLength s) + 1

apnd :: [a] -> [a] -> [a]
apnd [] (c:d) = (c:d)
apnd (a:b) [] = (a:b)
apnd [] [] = []
apnd (a:b) (c:d) = apnd (myNumInList c (a:b)) d

drp :: Int -> [a] -> [a]
drp n [] = error "the list is empty"
drp 0 list = list
drp n (a:b)
    | n < 0 = error "positive numbers"
    | n > myLength b = (a:b)
    | n > 0 = drp (n - 1) b

sa :: [Int] -> [Int]
sa (a:b:c) = b:a:c
sa c = c

sb :: [Int] -> [Int]
sb (a:b:c) = b:a:c
sb c = c

sc :: [Int] -> [Int] -> ([Int], [Int])
sc a b = tpl (sa a) (sb b)

pa :: [Int] -> [Int] -> ([Int], [Int])
pa a [] = (a, [])
pa a (b:bs) = tpl (b:a) bs

pb :: [Int] -> [Int] -> ([Int], [Int])
pb [] b = ([], b)
pb (a:as) b = tpl as (a:b)

ra :: [Int] -> [Int]
ra [] = []
ra (x:[]) = (x:[])
ra list = apnd (drp 1 list) (tk 1 list)

rb :: [Int] -> [Int]
rb [] = []
rb (x:[]) = (x:[])
rb list = apnd (drp 1 list) (tk 1 list)

rr :: [Int] -> [Int] -> ([Int], [Int])
rr a b = tpl (ra a) (rb b)

rra :: [Int] -> [Int]
rra [] = []
rra (x:[]) = (x:[])
rra list = apnd (drp (myLength(list) - 1) list) (tk (myLength(list) - 1) list)

rrb :: [Int] -> [Int]
rrb [] = []
rrb (x:[]) = (x:[])
rrb list = apnd (drp (myLength(list) - 1) list) (tk (myLength(list) - 1) list)

rrr :: [Int] -> [Int] -> ([Int], [Int])
rrr a b = tpl (rra a) (rrb b)

operation :: [String] -> ([Int], [Int]) -> ([Int], [Int])
operation [] (a, b) = (a, b)
operation ("sa":xs) (a, b) = operation xs ((sa a), b)
operation ("sb":xs) (a, b) = operation xs (a, (sb b))
operation ("sc":xs) (a, b) = operation xs (sc a b)
operation ("pa":xs) (a, b) = operation xs (pa a b)
operation ("pb":xs) (a, b) = operation xs (pb a b)
operation ("ra":xs) (a, b) = operation xs ((ra a), b)
operation ("rb":xs) (a, b) = operation xs (a, (rb b))
operation ("rr":xs) (a, b) = operation xs (rr a b)
operation ("rra":xs) (a, b) = operation xs ((rra a), b)
operation ("rrb":xs) (a, b) = operation xs (a, (rrb b))
operation ("rrr":xs) (a, b) = operation xs (rrr a b)

srt :: ([Int], [Int]) -> String
srt ([], []) = "OK"
srt ([a], []) = "OK"
srt ((a:as:ass), []) = if a <= as then srt((as:ass), []) else "KO"
srt (a, b) = "KO"

strToList :: String -> [String]
strToList str = words str

main :: IO()
main = do
    line <- getLine
    args <- getArgs
    putStrLn (srt(operation (strToList line) (map read args :: [Int], [])))
    if (srt(operation (strToList line) (map read args :: [Int], [])) == "KO")
        then
            exitWith (ExitFailure 84)
        else
            exitWith (ExitSuccess)
