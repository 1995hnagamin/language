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

main = do
    print =<< shuffle [1..9]
