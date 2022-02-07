import Control.Monad

main :: IO ()
main = do
    t <- readLn
    replicateM t $ do
        str <- getLine
        print $ solve str
    return ()

solve :: String -> Int
solve str = if zeroes == ones
               then ones - 1
               else min zeroes ones
    where
        zeroes = count '0' str
        ones = count '1' str

count :: Char -> String -> Int
count x = length . filter (x==)
