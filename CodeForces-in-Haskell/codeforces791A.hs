solve :: String -> Int
solve input = 
    let (a:b:_) = map (\xs -> read xs :: Int) (words input)
        la = [a * (3 ^ p) | p <- [0, 1..]]
        lb = [b * (2 ^ p) | p <- [0, 1..]]
        lc = zipWith (>) la lb
    in  length $ takeWhile (\x -> x == False) lc

main :: IO ()
main = do
    input <- getLine
    print $ solve input