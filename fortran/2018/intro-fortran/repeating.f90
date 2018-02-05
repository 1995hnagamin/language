program Repeating
        implicit none
        real(8) x
        integer count
        x = 1
        print *, 0, x
        do count = 1,10
                x = x/2 + 1/x
                print *, count, x
        end do
end program Repeating
