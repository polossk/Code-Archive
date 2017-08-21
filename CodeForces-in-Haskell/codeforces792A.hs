{-# OPTIONS_GHC -O2 #-}
{-# LANGUAGE ViewPatterns, ScopedTypeVariables #-}

import Data.List
import Data.Maybe (fromJust)
import Data.ByteString (ByteString)
import qualified Data.ByteString as B
import qualified Data.ByteString.Char8 as C

nextInt :: ByteString -> Int
nextInt = fst . fromJust . C.readInt

solve :: [Int] -> String
solve xs = 
    let ds = sort $ zipWith (-) (tail xs) xs
        h = head ds
        len = length $ takeWhile (== h) ds
    in  unwords $ map show [h, len]

main :: IO ()
main = do
    (sort . tail . map nextInt . C.words -> xs) <- B.getContents
    putStrLn $ solve xs