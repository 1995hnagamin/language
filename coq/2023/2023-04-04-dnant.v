Definition dnant (p: Prop) (q: Prop)  := (p->q) -> ~~p -> q.

Theorem yee: forall p q : Prop,
  (~~(dnant p q) -> (dnant p q)) -> dnant p q.
Proof.
  unfold dnant. intros p q H1 Hpq Hnnp.
  apply H1.
  - intros HnA. apply Hnnp. intros Hp. apply HnA. intros.
    apply Hpq. assumption.
  - assumption.
  - assumption.
Qed.
