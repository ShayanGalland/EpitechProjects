import System.Environment (getArgs)
import Data.Maybe (fromMaybe)
import System.Exit

-- Define a data structure for a person with 3 names and ages
data Person = Person {
    name_patric :: String,
    name_stephan :: String,
    name_marie :: String,
    age_patric :: Int,
    age_stephan :: Int,
    age_marie :: Int
} deriving (Show)

-- Define a function that takes a list of people and a name and age, and modifies the age of the person with the given name
updateAgeByName :: [Person] -> String -> Int -> [Person]
updateAgeByName [] _ _ = []
updateAgeByName (p:ps) nameToFind ageToUpdate
    | name_patric p == nameToFind = p { age_patric = ageToUpdate } : ps
    | name_stephan p == nameToFind = p { age_stephan = ageToUpdate } : ps
    | name_marie p == nameToFind = p { age_marie = ageToUpdate } : ps
    | otherwise = p : updateAgeByName ps nameToFind ageToUpdate

-- Define a function that takes a list of command-line arguments and returns a list of people with modified ages
parseArgs :: [String] -> [Person]
parseArgs args = updatePeople people args
  where
    people = [
        Person { name_patric = "Patric", name_stephan = "Stephan", name_marie = "Marie", age_patric = 30, age_stephan = 25, age_marie = 20 }
      ]
    updatePeople ps [] = ps
    updatePeople ps ("-patric":age:args) = updatePeople (updateAgeByName ps "Patric" (read age :: Int)) args
    updatePeople ps ("-stephan":age:args) = updatePeople (updateAgeByName ps "Stephan" (read age :: Int)) args
    updatePeople ps ("-marie":age:args) = updatePeople (updateAgeByName ps "Marie" (read age :: Int)) args
    updatePeople ps (_:args) = updatePeople ps args

-- Define the main function that reads command-line arguments, modifies the ages of people, and prints the resulting list of people
main :: IO ()
main = do
    args <- getArgs
    let people = parseArgs args
    putStrLn $ " " ++ show people
