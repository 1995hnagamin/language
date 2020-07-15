*** Test Cases ***
test
	${base}=	Evaluate	list(filter(lambda x: x % 2 == 0, range(0,10)))
	${list}=	Evaluate	random.sample(${base},2)	modules=random
