(** foobar *)


Module foobar.

  Compute None.

  Open Scope list_scope.

  Fixpoint split_seq (s:list nat) : option ((list nat) * nat * nat) :=
    match s with
    | nil => None
    | x :: nil => Some (nil, 0, x)
    | 0 :: s' =>
      match split_seq s' with
      | None => None
      | Some (nil, k, z) => Some (nil, k+1, z)
      | Some (w :: s', k, z) => Some (0 :: z :: s', k, z)
      end
    | (S x') :: s' =>
      match split_seq s' with
      | None => None
      | Some (nil, k, z) => Some ((S x') :: nil, k, z)
      | Some (w :: s', k, z) => Some ((S x') :: w :: s', k, z)
      end
    end.

  Fixpoint repeat_elem (T: Type) (x: T) (n: nat) : list T :=
    match n with
    | 0 => nil
    | S n' => x :: (repeat_elem T x n')
    end.

  Theorem thm1 : forall (s s': list nat) (n x : nat),
      split_seq s = Some (s', n, x) ->
      s = s' ++ (repeat_elem nat n 0) ++ (x :: nil).
  Proof.
    intros s.
    induction s.
    (* [], contra *)
    intros. inversion H.
    (* a :: s' *)
    clear IHs. generalize dependent a.
    induction s.
    - (* [a] *)
      intros.
      replace (split_seq (a :: nil)) with (Some (nil: list nat, 0, a)) in H.
      intros. simpl. inversion H. simpl. reflexivity.
      (* split a::nil = (nil, 0, a) *)
      destruct a; reflexivity.
    - (* a :: a0 :: s *)
      intros.
