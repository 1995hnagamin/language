*** Settings ***
Library  lib.py

*** Test Cases ***
My Test
    ${fun}=  Evaluate  lambda x: x * 2
    ${val}=  call_with_42  ${fun}
    Should Be Equal  ${val}  ${84}
