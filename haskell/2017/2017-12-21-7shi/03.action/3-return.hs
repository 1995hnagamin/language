import System.Random

main = do
    a <- return 1
    print a
    print =<< return 2
    return 3 >>= print
