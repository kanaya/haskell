(^^:) :: Integral a => a -> a -> a

x^^:n | n <= 0    = 1
      | otherwise = x^(x^^:(n-1))

main :: IO Int
main = do
  let y =  2 ^^: 3
  print y
  return 0


