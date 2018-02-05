program VariableTest
        implicit none
        real(8) x, y, z
        x = 1
        print *, x
        y = x/2 + 1/x
        print *, y
        z = y/2 + 1/y
        print *, z
end program VariableTest
