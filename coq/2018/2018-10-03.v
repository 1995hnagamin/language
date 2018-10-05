(*

Fixpoint fixp (A: Type) (f: A -> A) : A :=
  f (fixp A f).

=> Error: Cannot guess decreasing argument of fix.

sorewa sou

*)