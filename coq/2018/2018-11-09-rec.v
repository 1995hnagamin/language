(* yee *)

Fixpoint arrow1 (a n : nat) : nat :=
  match n with
  | O => 1
  | S n' => a * (arrow1 a n')
  end.

Compute (arrow1 2 10).

Fixpoint arrow2 (a n : nat) : nat :=
  match n with
  | O => 1
  | S n' => arrow1 a (arrow2 a n')
  end.

Compute (arrow2 2 3).

