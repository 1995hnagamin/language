program gcdtest
        implicit none
        integer a, b, bx
        a = 2214
        b = 77760
        do while (a > 0)
                bx = a
                a = mod(b, a)
                b = bx
        end do
        print *, b
end program gcdtest
