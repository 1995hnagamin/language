import Data.Array.IO

bf = ">+++++++++[<++++++++>-]<.>+++++++[<++++>" ++
     "-]<+.+++++++..+++.[-]>++++++++[<++++>-]<" ++
     ".>+++++++++++[<+++++>-]<.>++++++++[<+++>" ++
     "-]<.+++.------.--------.[-]>++++++++[<++" ++
     "++>-]<+.[-]++++++++++."

jumpIndex :: Int -> [Int] -> IOUArray Int Int -> [Char] -> IO (IOUArray Int Int)
jumpIndex _ _ ioua [] = return ioua

jumpIndex i l ioua ('[':prog) = do
    jumpIndex (i+1) (i:l) ioua prog

jumpIndex _ [] _ (']':_) = undefined

jumpIndex i (start:l) ioua (']':prog) = do
    writeArray ioua i start
    jumpIndex (i+1) l ioua prog

jumpIndex i l ioua (_:prog) = do
    jumpIndex (i+1) l ioua prog

main = do
    return ()
