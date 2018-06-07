Definition square (n: nat) : nat := n * n.

Fixpoint repeat (f : nat -> nat) (k : nat) (n : nat) :=
  match k with
  | O => n
  | S k' => f (repeat f k' n)
  end.

Fixpoint power (a: nat) (n: nat) : nat :=
  match n with
  | O => 1
  | S n' => a * (power a n')
  end.

Require Import Coq.omega.Omega.

Lemma square_is_pow_2 : forall n,
    square n = power n 2.
Proof.
  intros. induction n as [| n' IHn' ].
  - unfold square. reflexivity.
  - unfold square. simpl.
    replace (n' * 1) with n'. reflexivity.
    omega.
Qed.

Lemma power_plus : forall a m n,
    power a (m + n) = power a m * power a n.
Proof.
  intros. induction n as [| n' IHn' ].
  - simpl. replace (m + 0) with m.
    replace (power a m * 1) with (power a m).
    reflexivity.
    omega. omega.
  - simpl. replace (m + S n') with (S (m + n')).
    simpl. rewrite IHn'. rewrite mult_comm.
    replace (a * power a n') with (power a n' * a).
    rewrite mult_assoc. reflexivity.
    rewrite mult_comm. reflexivity.
    omega.
Qed.

Lemma power_power : forall a m n,
    power (power a m) n = power a (m * n).
Proof.
  intros a m n. induction n as [| n' IHn' ].
  - simpl. replace (m * 0) with 0. reflexivity.
    omega.
  - simpl. rewrite IHn'.
    rewrite <- power_plus.
    replace (m + m * n') with (m * S n'). reflexivity.
    rewrite mult_comm. simpl. rewrite mult_comm. reflexivity.
Qed.

Theorem hai : forall k n,
    repeat square k n = power n (power 2 k).
Proof.
  intro.
  induction k as [| k' IHk' ].
  - intros. simpl. omega.
  - intros. simpl.
    rewrite plus_0_r.
    rewrite IHk'. rewrite square_is_pow_2.
    rewrite power_power. rewrite mult_comm. simpl.
    rewrite plus_0_r. reflexivity.
Qed.