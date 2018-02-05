program SineFunction
        implicit none
        real(8) x, y
        x = 0
        do while (x < 2*3.14)
                y = sin(x)
                print *, x, y
                x = x + 1d-1
        end do
end program SineFunction
