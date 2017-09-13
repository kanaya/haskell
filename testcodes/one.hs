f :: Int -> Int
f x = 1 + x
main :: IO Int
main = print (f 2) >> pure 0

