{-
-- EPITECH PROJECT, 2023
-- all projects
-- File description:
-- project that i did in pool d3
-}

data Item = Sword | Bow | MagicWand deriving (Eq)
instance Show Item where
    show Sword = "sword"
    show Bow = "bow"
    show MagicWand = "magic wand"

data Mob = Mummy | Skeleton Item | Witch (Maybe Item) deriving Eq
instance Show Mob where
    show Mummy = "mummy"
    show (Skeleton Bow) = "doomed archer"
    show (Skeleton Sword) = "dead knight"
    show (Skeleton item) = "skeleton holding a " ++ show item
    show (Witch Nothing) = "witch"
    show (Witch (Just MagicWand)) = "sorceress"
    show (Witch item) = "witch holding a " ++ show item

createMummy :: Mob
createMummy = Mummy

createArcher :: Mob
createArcher = Skeleton Bow

createKnight :: Mob
createKnight = Skeleton Sword

createWitch :: Mob
createWitch = Witch Nothing

createSorceress :: Mob
createSorceress = Witch (Just MagicWand)

create :: String -> Maybe Mob
create "mummy" = Just createMummy
create "witch" = Just createWitch
create "sorceress" = Just createSorceress
create "doomed knight" = Just createKnight
create "doomed archer" = Just createArcher
create s = Nothing

equip :: Item -> Mob -> Maybe Mob
equip item Mummy = Nothing
equip item (Witch _) = Just (Witch (Just item))
equip item (Skeleton _) = Just (Skeleton item)

class HasItem a where
    getItem :: a -> Maybe Item
    hasItem :: a -> Bool
instance HasItem Mob where
    getItem Mummy = Nothing
    getItem (Skeleton item) = (Just item)
    getItem (Witch (Just item)) = (Just item)
    getItem mob = Nothing
    hasItem mob = if (getItem mob) == Nothing then False else True





