-- quadratic.hs

sgn :: Real a => a -> a
sgn x | x<0       = -1
      | otherwise = 1

a = 1.0
b = 2.0
c = 1.0

(x0, x1) = (q/a, c/q)
  where q = (b+(sgn b)*sqrt(b^2-4*a*c))/2.0

main :: IO Int
main = print (x0, x1) >> pure 0
