Require Import List.
Extract Inductive list => "list" ["[]" "(::)"].
Extract Inductive bool => "bool" ["true" "false"].
Extract Inductive nat => "int" ["0" "succ"] "(fun f0 fS n -> if n = 0 then f0 () else fs (n - 1))".
Extract Constant mult => "( * )".

Extraction map.

Extraction list.

Fixpoint fact (n:nat) :=
  match n with
  | O => 1
  | S n' => mult n (fact n')
  end.

Extraction mult.
Extraction fact.