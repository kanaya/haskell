-- complextest.hs

import Data.Complex

ar = 1
ai = 1
br = 1
bi = 1
cr = 1
ci = 1

a, b, c :: Complex Double
a = ar :+ ai
b = br :+ bi
c = cr :+ ci

sq :: Real a => a -> a
sq x = x*x

sq' :: RealFloat a => Complex a -> Complex a
sq' x = x*x

(*.) :: Real a => a -> Complex a -> Complex a
(*.) a (x:+y) = a*x :+ a*y

sgn :: Real a => a -> a
sgn x | x < 0     = (-1)
      | otherwise = 1

sqrt' :: RealFloat a => Complex a -> Complex a
sqrt' (x:+y) = (sqrt 2)/2*((sqrt(d+x)):+sgn(y)*(sqrt(d-x))) where d = sqrt(sq x + sq y)

sgn' :: RealFloat a => Complex a -> Complex a -> Complex a -> Complex a
sgn' a b c | realPart((conjugate b) * sqrt'(sq' b - 4*.(a*c)))<0 = (-1) :+ 0
           | otherwise                                          = 1 :+ 0

(x0, x1) = (q/a, c/q)
  where q = (b + sgn' a b c * r) / 2.0
        r = sqrt(sq' b - 4*.(a*c))

main :: IO Int
main = print a >> pure 0
