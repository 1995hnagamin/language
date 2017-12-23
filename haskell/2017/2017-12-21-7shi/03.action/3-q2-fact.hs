fact 0 = return 1
fact n | n > 0 = do
    rec <- fact (n - 1)
    return $ n * rec

main = do
  print =<< fact 5
