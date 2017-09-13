-- sample.hs
n :: Int
n = 100

f :: Double -> Double
f x | x == 0    = 1
    | otherwise = (sin x)/x

xs :: [Double]
xs = [(fromIntegral i)/(fromIntegral n)
  *pi | i <- [0..n]]

ys :: [Double]
ys = f `map` xs

main :: IO Int
main = print ys >> pure 0
