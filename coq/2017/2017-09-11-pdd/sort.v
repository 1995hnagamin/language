Require Import List.
Require Import Arith.

Fixpoint insert (a : nat) (l : list nat) : list nat :=
  match l with
  | nil => a :: nil
  | x :: xs => if leb a x then a :: l else x :: insert a xs
  end.

Fixpoint insertion_sort (l : list nat) : list nat :=
  match l with
  | nil => nil
  | x :: xs => insert x (insertion_sort xs)
  end.

Eval compute in insert 1 nil.
Eval compute in insert 5 (1 :: 4 :: 2 :: 9 :: 3 :: nil).
Eval compute in insertion_sort (2 :: 4 :: 1 :: 5 :: 3 ::nil).

Require Import Sorting.Permutation.
Require Import Sorting.Sorted.

Lemma insert_perm : forall (x : nat) (l : list nat),
    Permutation (x :: l) (insert x l).
Proof.
  intros x l. generalize dependent x. induction l as [| h t IHt ].
  - intro. simpl. apply Permutation_refl.
  - intro. simpl. destruct (leb x h).
    + apply Permutation_refl.
    + apply perm_trans with (h :: x :: t).
      * apply perm_swap.
      * apply perm_skip. apply IHt.
Qed.

Theorem isort_permutation : forall (l : list nat),
    Permutation l (insertion_sort l).
Proof.
  intros. induction l as [| a l' IHl' ].
  - simpl. apply perm_nil.
  - simpl. apply perm_trans with (a :: insertion_sort l').
    + apply perm_skip. apply IHl'.
    + apply insert_perm.
Qed.

Lemma insert_sorted : forall (a : nat) (l : list nat),
    LocallySorted le l -> LocallySorted le (insert a l).
Proof.
  induction l as [| h t IHt ].
  - simpl. intros. constructor.
  - intros H. simpl. remember (leb a h) as b. destruct b.
    + apply LSorted_consn.
      apply H.
      apply leb_complete. congruence.
    + Admitted.

Theorem isort_sorted : forall (l : list nat),
    LocallySorted le (insertion_sort l).
Proof.
Admitted.
