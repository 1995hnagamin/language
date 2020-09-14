```
$ make
ff-c++ supercalifragilisticexpialidocious.cpp
g++ -c -Wno-undefined-var-template -m64 ...

$ FreeFem++-nw test.edp
-- FreeFem++ v  3.610001 (date Jeu 12 jul 2018 12:05:08 CEST)
 Load: lg_fem lg_mesh lg_mesh3 eigenvalue
    1 : load "supercalifragilisticexpialidocious"
    2 :
    3 : sayhello();
    4 :  sizestack + 1024 =1072  ( 48 )

Hello
times: compile 0.008511s, execution 1.8e-05s,  mpirank:0
 CodeAlloc : nb ptr  2712,  size :352680 mpirank: 0
Ok: Normal End
```
