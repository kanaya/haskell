-- This is a sample program.

newtype  ZipList' a = ZipList' { getList :: [a] } deriving Show
instance Functor ZipList' where
  fmap f (ZipList' xs) = ZipList' (map f xs)
instance Applicative ZipList' where
  ZipList' fs <*> ZipList' xs = ZipList' (zipWith ($) fs xs) -- (fs ***** xs)
  pure x                      = ZipList' (repeat x)

-- repeat   :: [a] -> [a]
-- repeat x =  x : repeat x 

(*****) _ []          = []
(*****) [] _          = []
(*****) (f:fs) (x:xs) = (f $ x) : fs ***** xs

f   :: Int -> (Int -> Int)
f n =  \x -> x+n

fs = [(f 1), (f 2)]
xs = [10, 20]

fxs = ZipList' fs <*> ZipList' xs

main :: IO Int
main =  print fxs >> pure 0
