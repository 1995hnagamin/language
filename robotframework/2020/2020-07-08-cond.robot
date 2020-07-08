*** Test Cases ***
テスト1
    ${s1}=  Evaluate    "yes"
    Should Be True      "${s1}" == "no" or "${s1}" == "yes"
