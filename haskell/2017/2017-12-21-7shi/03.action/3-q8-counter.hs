import Data.IORef

counter :: IO (IO Integer)
counter = do
    varC <- newIORef 0
    return $ do
        c <- readIORef varC
        let c' = c + 1
        writeIORef varC c'
        return c'

main = do
    f <- counter
    print =<< f
    print =<< f
    print =<< f
