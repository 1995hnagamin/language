*** Keywords ***

Check 99 + 1 equals to 100
    ${two}=     Evaluate    100
    Should Be Equal     ${two}  ${100}
