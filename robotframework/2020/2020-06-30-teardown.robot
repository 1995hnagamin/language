*** Test Cases ***
テスト1
    ${id}=  Evaluate    str(uuid.uuid4())   modules=uuid
    ${n}=   Evaluate    len("${id}")
    Should Be Equal As Integers     ${n}   36
    [Teardown]  Log To Console  ${id}
