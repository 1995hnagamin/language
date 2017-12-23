import System.Random

insert :: Int -> a -> [a] -> [a]
insert _ x [] = [x]
insert 0 x ys = (x:ys)
insert n x (y:ys) = y:(insert (n-1) x ys)

insertR :: a -> [a] -> IO [a]
insertR x xs = do
    idx <- getStdRandom $ randomR (0, (length xs))
    return $ insert idx x xs

shuffle :: [Int] -> IO [Int]
shuffle [] = return []
shuffle (x:xs) = do
    xs' <- shuffle xs
    insertR x xs'

isSorted :: [Int] -> Bool
isSorted [] = True
isSorted [_] = True
isSorted (x:y:zs) = (x < y) && isSorted (y:zs)

bogosort :: [Int] -> IO [Int]
bogosort xs = do
    if isSorted xs
    then return xs
    else do
        xs' <- shuffle xs
        bogosort xs'

main = do
    xs <- shuffle [1..9]
    print xs
    print =<< bogosort xs
