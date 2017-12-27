import Data.IORef

loop s i | i <= 100 = loop (s+i) (i+1)
loop s _ = s

main = do
    print $ loop 0 1
