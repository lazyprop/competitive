import Control.Monad
import Data.List

main :: IO ()
main = do
    t <- readLn
    replicateM t $ do
        line <- getLine
        let [n, k] = map read $ words line :: [Int]
        let (possible, solution) = solve n k
        if possible
           then do
               putStrLn "YES"
               mapM_ (putStrLn . spaceSeparate) solution
           else putStrLn "NO"
    return ()


solve :: Int -> Int -> (Bool, [[Int]])
solve n k
  | k == 1          = (True, map (:[]) [1..n])
  | mod n 2 == 0    = (True, makeGrid n k) 
  | otherwise       = (False, [])

-- first all the even numbers from 2 to n*k
-- then all the odd numbers from 1 to n*k
makeGrid :: Int -> Int -> [[Int]]
makeGrid n k =
    evens ++ odds
      where
          evens = [map (2*i*k+) [2,4..2*k] | i <- [0..mid-1]]
          odds = [map (2*i*k+) [1,3..2*k] | i <- [0..mid-1]]
          mid = div n 2

spaceSeparate :: (Show a) => [a] -> String
spaceSeparate xs = foldr (++) "" $ intersperse " " $ map show xs

