import Control.Monad
import Data.List

main :: IO ()
main = do
    t <- readLn
    replicateM t $ do
        n <- readLn
        putStrLn . show $ solve n
    return ()

solve :: Int -> Int
solve n
  | mod n 7 == 0        = n
  | mod n 7 <= mod n 10 = n - mod n 7
  | otherwise           = n + (7 - mod n 7)

