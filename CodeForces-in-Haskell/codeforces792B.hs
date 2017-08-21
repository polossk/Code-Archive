{-# OPTIONS_GHC -O2 #-}
{-# LANGUAGE ViewPatterns, ScopedTypeVariables #-}

import Data.List
import Data.Maybe (fromJust)
import Data.ByteString (ByteString)
import qualified Data.ByteString as B
import qualified Data.ByteString.Char8 as C

nextInt :: ByteString -> Int
nextInt = fst . fromJust . C.readInt

solve :: [Int] -> [Int]
solve (n : _ : xs) = solve' n xs [1..n]

solve' :: Int -> [Int] -> [Int] -> [Int]
solve' _ [] _ = []
solve' n (x:xs) k =
    let (mae, ushiro) = splitAt (x `mod` n) k
    in  if null ushiro
        then head mae : solve' (n - 1) xs (tail mae)
        else head ushiro : solve' (n - 1) xs (tail ushiro ++ mae)

main = do
    (map nextInt . C.words -> xs) <- B.getContents
    putStrLn solve xs