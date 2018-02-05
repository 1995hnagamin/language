program Repeating
        implicit none
        real(8) x
        integer count
        x = 1
        print *, x
        count = 3
        do while (count > 0)
                x = x/2 + 1/x
                print *, x
                count = count - 1
        end do
end program Repeating
