program VariableTest
        implicit none
        real(8) x
        x = 1
        print *, x
        x = x/2 + 1/x
        print *, x
        x = x/2 + 1/x
        print *, x
end program VariableTest
