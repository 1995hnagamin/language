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

Inductive arrow : nat -> nat -> nat -> nat -> Prop :=
| ArrBase1 : forall a,
    a > 0 -> arrow a 0 0 1
| ArrBase2 : forall a b x y,
    a > 0 -> arrow a b 0 x -> y = a * x -> arrow a (S b) 0 y
| ArrBase3 : forall a n,
    a > 0 -> arrow a 0 (S n) 1
| ArrInd : forall a b n x y,
    a > 0 -> arrow a b (S n) x -> arrow a x n y -> arrow a (S b) (S n) y.

Theorem arrow_fn : forall a b n,
    a > 0 -> exists! x, arrow a b n x.
Proof.
  intros a b n Hap. generalize dependent b.
  induction n as [| n' IHn'].
  - (* n = 0 *)
    intros b. induction b as [| b' IHb'].
    + (* b = 0 *)
      exists 1. split.
      * (* <a, 0, 0> = 1 *)
        apply ArrBase1. apply Hap.
      * (* uniqueness *)
        intros x' Hx'. inversion Hx'. reflexivity.
    + (* b = S b' *)
      destruct IHb' as [x [Hxe Hxu]].
      exists (a * x). split.
      * (* <a, b'+1, 0> = a x *)
        apply ArrBase2 with x.
        (* a > 0 *) apply Hap.
        (* <a, b', 0> = x *)apply Hxe.
        (* a x = a x *) reflexivity.
      * (* uniqueness *)
        intros x' Hx'. inversion Hx'. subst.
        replace x0 with x. reflexivity.
        (* x0 = x *)
        apply Hxu. assumption.
  - (* n = S n' *)
    intros b. induction b as [| b' IHb'].
    + (* b = 0 *)
      exists 1. split.
      * (* <a, 0, n'+1> = 1 *)
        apply ArrBase3. apply Hap.
      * (* uniqueness *)
        intros x' Hx'. inversion Hx'. reflexivity.
    + (* b = S b' *)
      destruct IHb' as [x [Hxe Hxu]].
      assert (Hy: exists! y, arrow a x n' y). {
        apply IHn'.
      }
      destruct Hy as [y [Hye Hyu]].
      exists y. split.
      * (* <a, b'+1, n'+1> = y *)
        apply ArrInd with x.
        (* a > 0 *) apply Hap.
        (* <a, b', n'+1> = x *) apply Hxe.
        (* <a, x, n'> = y *) apply Hye.
      * (* uniqueness *)
        intros y' Hy'. inversion Hy'. subst.
        apply Hyu. replace x with x0. assumption.
        symmetry. apply Hxu. assumption.
Qed.
