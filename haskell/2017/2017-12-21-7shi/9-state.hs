import Data.IORef

main = do
    a <- newIORef 1
    writeIORef a 2
    print =<< readIORef a
