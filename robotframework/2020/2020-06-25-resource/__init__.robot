*** Settings ***
Resource    common.robot

*** Keywords ***

Check 1 + 1 equals to 2
    ${two}=     Evaluate    1+1
    Should Be Equal     ${two}  ${2}
