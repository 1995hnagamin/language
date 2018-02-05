program Repeating
        implicit none
        real(16) :: x = 1, x0 = 0, a = 1729
        integer :: c = 0
        do while (abs(x - x0) > spacing(x0)*2)
                c = c + 1
                x0 = x
                x = (x + a/x)/2
                print *, c, x, spacing(x0)
        end do
end program Repeating
