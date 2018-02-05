program SubroutineTest
        call English
        call French
        call Spanish
        call English
end program SubroutineTest

subroutine English
        call French
        print *, 'How are you?'
end subroutine English

subroutine Spanish
        print *, '?Commo esta usted?'
end subroutine Spanish

subroutine French
        print *, 'Comment allez-vous?'
end subroutine French

