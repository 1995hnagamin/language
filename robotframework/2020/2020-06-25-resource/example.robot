*** Keywords ***

Check 0 + 0 equal to 0
    ${zero}=    Evaluate    0+0
    Should Be Equal     ${zero}     ${0}


*** Test Cases ***

(Control)
    Check 0 + 0 equal to 0

Check common.robot
    Check 99 + 1 equal to 100

Check __init__.robot
    Check 1 + 1 equal to 2
