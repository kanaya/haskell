import qualified Control.Category as Cat

newtype NonDet a b = NonDet { run :: a -> [b] } 

instance Cat.Category NonDet where
  id = NonDet (\x -> [x])
  (NonDet f) . (NonDet g) = NonDet $ concat . map f . g 

duplicate :: a -> [a]
duplicate x = [x, x]

triplicate :: a -> [a]
triplicate x = [x, x, x]

duplicate' :: NonDet a a
duplicate' = NonDet duplicate

triplicate' :: NonDet a a
triplicate' = NonDet triplicate
                                                                              
x = "Hello."
y = run(triplicate' Cat.. duplicate') x

main :: IO Int
main = print y >> pure 0
