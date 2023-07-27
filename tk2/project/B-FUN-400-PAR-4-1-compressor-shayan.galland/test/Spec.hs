import Data.List
import System.Environment
import System.Exit
import System.IO
import Control.Monad
import Text.Read (readMaybe)
import Data.Maybe (mapMaybe)
import Data.Char


type Point = (Int, Int)
type Color = (Int, Int, Int)
type Pixel = (Point, Color)


parsePixel :: [String] -> [[Int]]
parsePixel [] = []
parsePixel (x:xs) = getDigits x : parsePixel xs


readPixels :: FilePath -> IO [[Int]]
readPixels filePath = do
    contents <- readFile filePath
    let linesOfFile = lines contents
    let pixels = parsePixel linesOfFile
    return pixels


getDigits :: String -> [Int]
getDigits = do
        intList <- map read . filter (all isDigit) . groupBy (\a b -> isDigit a && isDigit b)
        return intList


checkValues :: [[Int]] -> IO ()
checkValues xs = if all (\ys -> length ys == 5 && all (>=0) (take 2 ys) && all (\z -> z >= 0 && z <= 255) (drop 2 ys)) xs
                 then return ()
                 else exitErr

checkSize :: [[Int]] -> IO ()
checkSize xs = if all (\ys -> length ys == 5) xs
               then return ()
               else exitErr


errFile :: [[Int]] -> IO ()
errFile ([]) = exitErr
errFile xs = do
  checkSize xs
  checkValues xs


main :: IO ()
main = do
    args <- getArgs
    pixels <- readPixels (head args)
    errFile pixels
    print pixels


exitErr :: IO ()
exitErr = exitWith (ExitFailure 84)