import Debug.Trace

qsort [] = do
    return []
qsort xs@(x:xs') = do
    let lt = filter (<x) xs'
    let ge = filter (>=x) xs'
    putStrLn $ "qsort " ++ show xs ++ " = qsort " ++
                show lt ++ " ++ " ++ show [x] ++ " ++ qsort " ++ show ge
    lt' <- qsort lt
    ge' <- qsort ge
    return $ lt' ++ [x] ++ ge'

main = do
    print =<< qsort [4, 6, 9, 8, 3, 5, 1, 7, 2]
