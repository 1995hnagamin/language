
Theorem dm1 : forall (P Q:Prop),
    ~P \/ ~Q <-> ~(P /\ Q).
Proof.
  intros P Q. split.
  - (* -> *)
    intros [NP | NQ]; unfold not; intros [HP HQ].
    + (* when ~P *) apply NP. assumption.
    + (* when ~Q *) apply NQ. assumption.
  - (* <- *)
    intros H. unfold not. Abort.
