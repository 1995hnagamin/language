(* Ackermann function is well-defined *)

(* Ackermann relation *)

Inductive ack : nat -> nat -> nat -> Prop :=
| AckBase1: forall n, ack 0 n (S n)
| AckBase2: forall m n x:nat, ack m 1 x -> ack (S m) 0 x
| AckInd: forall m n x y:nat, ack (S m) n x -> ack m x y -> ack (S m) (S n) y.

(* Ackermann relation is functional *)

Theorem ack_fn: forall m n,
    exists! x, ack m n x.
Proof.
  intro m. induction m as [| m' IHm'].
  - (* m = 0 *)
    intros. exists (S n). split.
    + (* existence *) apply AckBase1.
    + (* uniqueness *) intros x' Hx'. inversion Hx'. reflexivity.
  - (* m = S m' *)
    intro n. induction n as [| n' IHn'].
    + (* n = 0 *)
      assert (H1: exists! x, ack m' 1 x). {
        apply IHm'.
      }
      inversion H1 as [x [H1e H1u]].
      exists x. split.
      * apply AckBase2. apply x. apply H1e.
      * intros x' Hx'. inversion Hx'. subst. apply H1u. assumption.
    + (* n = S n' *)
      inversion IHn' as [x [H1e H1u]].
      assert (H2: exists! y, ack m' x y). {
        apply IHm'.
      }
      inversion H2 as [y [H2e H2u]].
      exists y. split.
      * apply AckInd with x. assumption. assumption.
      * intros y' Hy'. inversion Hy'; subst.
        apply H2u. replace x with x0. assumption.
        (* x = x0 *)
        symmetry. apply H1u. assumption.
Qed.