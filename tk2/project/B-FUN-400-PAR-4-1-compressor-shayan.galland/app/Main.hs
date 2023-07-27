import System.Environment
import System.Exit
import System.Random
import Data.List
import Data.Char
import Text.Read
import Data.Maybe (isNothing)
import Data.Ord (comparing)
import Numeric
import Control.Exception
import Data.String
import Data.Typeable
import Data.Ord
import Data.Function
import Control.Monad


-------------------------------------------------------------- args parsing --------------------------------------------------------------


data Options = Options { numColors :: Maybe Int, convLimit :: Maybe Double, filePath :: Maybe FilePath} deriving Show

parseArgs :: [String] -> Options -> Either String Options
parseArgs [] options = Right options
parseArgs ("-n":n:xs) options = case readMaybe n of
    Just i -> parseArgs xs (options { numColors = Just i })
    Nothing -> Left "Invalid argument for -n"
parseArgs ("-l":l:xs) options = case readMaybe l of
    Just d -> parseArgs xs (options { convLimit = Just d })
    Nothing -> case readMaybe l of
        Just i -> parseArgs xs (options { convLimit = Just (fromIntegral i) })
        Nothing -> Left "Invalid argument for -l"
parseArgs ("-f":f:xs) options = parseArgs xs (options { filePath = Just f })
parseArgs (_:xs) options = parseArgs xs options


-------------------------------------------------------------- main functions --------------------------------------------------------------


main :: IO ()
main = do
    args <- getArgs
    if length (args) /= 6
        then printUsage >> exitErr
        else do
        if (head args) == "-h" || (head args) == "--help"
            then printUsage >> exitSuccess
            else do
            let options = parseArgs args (Options Nothing Nothing Nothing)
            case parseArgs args (Options Nothing Nothing Nothing) of
                Left errorMsg -> printUsage >> putStrLn errorMsg >> exitErr
                Right options ->
                    if isNothing (numColors options) || isNothing (convLimit options) || isNothing (filePath options)
                        then printUsage >> exitErr
                        else compressImage options

compressImage :: Options -> IO ()
compressImage options = do
    let maybeFilePath = filePath options
    case maybeFilePath of
        Nothing -> exitErr
        Just file -> do
            pixels <- readPixels file
            errFile pixels
            let numColors' = maybe 16 id (numColors options)
            let convLimit' = maybe 0.01 id (convLimit options)
            clustering pixels numColors' convLimit'


-------------------------------------------------------------- clustering algos --------------------------------------------------------------


type Point = (Int, Int)
type Color = (Int, Int, Int)
type Pixel = (Point, Color)
type Cluster = (Color, [Pixel])

euclideanDistance :: Color -> Color -> Double
euclideanDistance (r1, g1, b1) (r2, g2, b2) = sqrt (fromIntegral ((r1 - r2)^2 + (g1 - g2)^2 + (b1 - b2)^2))

meanColor :: [Color] -> Color
meanColor colors = (r `div` len, g `div` len, b `div` len)
  where
    (r, g, b) = foldl (\(r', g', b') (r, g, b) -> (r' + r, g' + g, b' + b)) (0, 0, 0) colors
    len = length colors

assignToClosest :: [Color] -> Pixel -> Cluster
assignToClosest centroids pixel@(_, color) =
  (minimumBy (compare `on` euclideanDistance color) centroids, [pixel])

assignPixels :: [Color] -> [Pixel] -> [Cluster]
assignPixels centroids pixels = foldl step [] pixels
  where
    step clusters pixel = merge (assignToClosest centroids pixel) clusters
    merge (centroid, pixels) [] = [(centroid, pixels)]
    merge (centroid, pixels) ((c, ps):clusters)
      | centroid == c = (centroid, pixels ++ ps) : clusters
      | otherwise     = (c, ps) : merge (centroid, pixels) clusters

updateCentroids :: [Cluster] -> [Color]
updateCentroids = map (meanColor . map snd . snd)

converged :: Double -> [Color] -> [Color] -> Bool
converged limit oldCentroids newCentroids =
  all (\(c1, c2) -> euclideanDistance c1 c2 < limit) $ zip oldCentroids newCentroids

kMeans :: [[Int]] -> Int -> Double -> [Cluster]
kMeans pixels n limit = loop (initCentroids pixels n)
  where
    loop centroids =
      let clusters = assignPixels centroids (map toPixel pixels)
          newCentroids = updateCentroids clusters
       in if converged limit centroids newCentroids
             then clusters
             else loop newCentroids
    toPixel [x, y, r, g, b] = ((x, y), (r, g, b))

initCentroids :: [[Int]] -> Int -> [Color]
initCentroids pixels n = map (\[_, _, r, g, b] -> (r, g, b)) $ take n pixels

printCluster :: Cluster -> IO ()
printCluster (centroid, pixels) = do
  putStrLn "--"
  printColor centroid
  putStrLn "\n-"
  mapM_ (\(point, color) -> printPoint point >> putStr " " >> printColor color >> putStrLn "") pixels
  where
    printPoint (x, y) = putStr $ "(" ++ show x ++ "," ++ show y ++ ")"
    printColor (r, g, b) = putStr $ "(" ++ show r ++ "," ++ show g ++ "," ++ show b ++ ")"

clustering :: [[Int]] -> Int -> Double -> IO ()
clustering pixels n limit = mapM_ printCluster $ kMeans pixels n limit



-------------------------------------------------------------- pixels parse --------------------------------------------------------------


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


-------------------------------------------------------------- error gestion --------------------------------------------------------------


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

exitErr :: IO ()
exitErr = exitWith (ExitFailure 84)


-------------------------------------------------------------- utils --------------------------------------------------------------


convertToInt :: [[Int]] -> [[Double]]
convertToInt = map (map fromIntegral)

printUsage :: IO ()
printUsage = putStrLn help

help :: String
help = "USAGE: ./imageCompressor -n N -l L -f F\n\
        \\n\
        \\tN\tnumber of colors in the final image\n\
        \\tL\tconvergence limit\n\
        \\tF\tpath to the file containing the colors of the pixels\n"


-------------------------------------------------------------- end --------------------------------------------------------------
