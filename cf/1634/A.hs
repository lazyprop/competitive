import Control.Monad

main :: IO ()
main = do
    t <- readLn
    replicateM t $ do
        line <- getLine
        let [n, k] = map read $ words line :: [Int]
        str <- getLine
        putStrLn $ show $ solve n k str
    return ()

solve :: Int -> Int -> [Char] -> Int
solve n k str
  | k == 0                  = 1
  | (reverse str) == str    = 1
  | otherwise               = 2

