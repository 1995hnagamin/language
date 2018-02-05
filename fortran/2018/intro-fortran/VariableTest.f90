program VariableTest
        implicit none
        real(8) Harry
        Harry = 1
        print *, Harry
        Harry = Harry/2 + 1/Harry
        print *, Harry
        Harry = Harry/2 + 1/Harry
        print *, Harry
end program VariableTest
