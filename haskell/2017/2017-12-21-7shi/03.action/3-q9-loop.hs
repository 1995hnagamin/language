import Data.IORef

main = do
    s <- newIORef 0
    let loop i | i <= 100 = do
            sVal <- readIORef s
            writeIORef s (sVal + i)
            loop $ i + 1
        loop _ = do
            print =<< readIORef s
    loop 1
