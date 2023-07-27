import System.Environment
import System.Exit
import System.IO

data DataArgs = DataArgs { idRULE :: String, idSTART :: String, idNLINES :: String, idWINDOW :: String, idMOVE :: String, rule :: Int, start :: Int, nlines :: Int, window :: Int, move :: Int }

help :: [Char]
help = "Usage:\n\t./wolfram --rule [30, 90, 110] [--move --start --window\
       \--lines]\n\n--rule: The ruleset to use (no default value, mandatory)\
       \\n--move: A translation to apply on the window. If negative, the \
       \window is translated to the left.If positive, it's translated to \
       \he right.\n--window: The number of cells to display on each line \
       \(line width).If even, the central cell is displayed in the next cell\
       \ on the right. The default value is 80.\n--lines: The number of\
       \ lines to display. When omitted, the program never stops.\n--start:\
       \ The generation number at which to start the display. The default\
       \ value is 0.\n"

rule110 :: [Char] -> [Char]
rule110 (l:c:r:rest)
    | l == '*' && c == '*' && r == ' ' = '*' : rule110 (c:r:rest)
    | l == '*' && c == ' ' && r == '*' = '*' : rule110 (c:r:rest)
    | l == ' ' && c == '*' && r == '*' = '*' : rule110 (c:r:rest)
    | l == ' ' && c == '*' && r == ' ' = '*' : rule110 (c:r:rest)
    | l == ' ' && c == ' ' && r == '*' = '*' : rule110 (c:r:rest)
    | otherwise = ' ' : rule110 (c:r:rest)
rule110 _ = "  "

rule90 :: [Char] -> [Char]
rule90 (l:c:r:rest)
    | l == '*' && c == '*' && r == ' ' = '*' : rule90 (c:r:rest)
    | l == '*' && c == ' ' && r == ' ' = '*' : rule90 (c:r:rest)
    | l == ' ' && c == '*' && r == '*' = '*' : rule90 (c:r:rest)
    | l == ' ' && c == ' ' && r == '*' = '*' : rule90 (c:r:rest)
    | otherwise = ' ' : rule90 (c:r:rest)
rule90 _ = "  "

rule30 :: [Char] -> [Char]
rule30 (l:c:r:rest)
    | l == '*' && c == ' ' && r == ' ' = '*' : rule30 (c:r:rest)
    | l == ' ' && c == '*' && r == '*' = '*' : rule30 (c:r:rest)
    | l == ' ' && c == '*' && r == ' ' = '*' : rule30 (c:r:rest)
    | l == ' ' && c == ' ' && r == '*' = '*' : rule30 (c:r:rest)
    | otherwise = ' ' : rule30 (c:r:rest)
rule30 _ = "  "

changeArgsById :: [DataArgs] -> String -> Int -> [DataArgs]
changeArgsById [] _ _ = []
changeArgsById (x:xs) idToFind argToUpdate
    | idRULE x == idToFind = x {rule = argToUpdate} : xs
    | idSTART x == idToFind = x {start = argToUpdate} : xs
    | idNLINES x == idToFind = x {nlines = argToUpdate} : xs
    | idWINDOW x == idToFind = x {window = argToUpdate} : xs
    | idMOVE x == idToFind = x {move = argToUpdate} : xs
    | otherwise = x : changeArgsById xs idToFind argToUpdate

parseArgs :: [String] -> [DataArgs]
parseArgs args = updateArgs dataArgs args
  where
      dataArgs = [DataArgs {idRULE = "Rule", idSTART = "Start", idNLINES = "Nlines", idWINDOW = "Window", idMOVE = "Move", rule = 0, start = 0, nlines = -1, window = 80, move = 0}]
      updateArgs dataArgs' [] = dataArgs'
      updateArgs dataArgs' ("--rule":nbr:av) = updateArgs (changeArgsById dataArgs' "Rule" (read nbr :: Int)) av
      updateArgs dataArgs' ("--start":nbr:av) = updateArgs (changeArgsById dataArgs' "Start" (read nbr :: Int)) av
      updateArgs dataArgs' ("--lines":nbr:av) = updateArgs (changeArgsById dataArgs' "Nlines" (read nbr :: Int)) av
      updateArgs dataArgs' ("--window":nbr:av) = updateArgs (changeArgsById dataArgs' "Window" (read nbr :: Int)) av
      updateArgs dataArgs' ("--move":nbr:av) = updateArgs (changeArgsById dataArgs' "Move" (read nbr :: Int)) av
      updateArgs dataArgs' (_:argss) = updateArgs dataArgs' argss

engineGen :: DataArgs -> ([Char] -> [Char]) -> IO ()
engineGen args ruleFn = do
  let lineSize = ((nlines args) * 2)
  let startGen = replicate lineSize ' ' ++ replicate ((move args) * 2) ' ' ++ '*' : replicate lineSize ' '
  let startingGen = start args
  let nGen = if nlines args == -1 then maxBound else startingGen + (nlines args)
  let generator = iterate (shiftLine . ruleFn) startGen
  let resizedList = resizeContent generator (window args)
  let shiftList = take (max 0 (nGen - startingGen)) $ resizedList
  putStr $ unlines shiftList

resizeContent :: [[Char]] -> Int -> [[Char]]
resizeContent xs size = map (take size . resize) xs
  where
    resize str
      | length str <= size = pad str
      | otherwise = let excess = length str - size in drop (excess `div` 2) (take (length str - excess `div` 2) str)
    pad str = let diff = size - length str in replicate (diff `div` 2) ' ' ++ str ++ replicate (diff - diff `div` 2) ' '

shiftLine :: [Char] -> [Char]
shiftLine line = take (length line) $ ' ' : line

main :: IO ()
main = do
  args <- getArgs
  if (length args) == 0
    then hPutStrLn stderr "Error: wrong arguments" >> exitWith (ExitFailure 84)
    else do
    if (head args) == "-h" || (head args) == "--help"
      then putStrLn help
      else do
      let parsedArgs = parseArgs args
      if rule (head parsedArgs) == 0 || (rule (head parsedArgs) /= 30 && rule (head parsedArgs) /= 90 && rule (head parsedArgs) /= 110) || odd (length args)
        then hPutStrLn stderr "Error: rule not supported" >> exitWith (ExitFailure 84)
        else do
          case parseArgs args of
            [] -> hPutStrLn stderr "Error: no arguments provided" >> exitWith (ExitFailure 84)
            (dataArgs:_) -> do
              let ruleFn = case rule dataArgs of
                    30 -> rule30
                    90 -> rule90
                    110 -> rule110
                    _  -> error "Error: rule not supported"
              engineGen dataArgs ruleFn
              exitSuccess
