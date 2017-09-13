-- args

import System.Environment (getArgs)

main :: IO Int
main = do
  args <- getArgs
  print args
  return 0
