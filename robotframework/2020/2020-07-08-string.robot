*** Test Cases ***

Test 1
	${str1}=	Catenate	SEPARATOR=
		...	1234567890
		...	ABCDEFGHIJ
		...	KLMNOPQRST
	Should Be Equal As Strings	${str1}		1234567890ABCDEFGHIJKLMNOPQRST
