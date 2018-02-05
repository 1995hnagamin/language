program Repeating
        implicit none
        real(8) :: x = 1, x0 = 0, a = 10
        integer :: c = 0
        do while (abs(x - x0) > spacing(x0)*2)
                c = c + 1
                x0 = x
                x = (x + a/x)/2
                print *, c, x
        end do
end program Repeating
