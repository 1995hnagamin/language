(* https://blog.7nobo.me/2016/11/30/204158.html *)

module type Eq =
sig
  type a
  val eq : a -> a -> bool
end

type person =
  : Person of string * int

module PersonEq : (Eq with type a = person) =
struct
  type a = person
  let eq a b = match (a, b) with
    | (Person(a_name, a_age), Person(b_name, b_age)) ->
      a_name = b_name && a_age = b_age
end

module type Find =
sig
  type a
  val find : a -> a list -> a option
end

module Find (E : Eq) : (Find with type a = E.a) =
struct
  type a = E.a
  let rec find (e : a) (xs : a list) : a option =
    match xs with
    | [] -> None
    | x :: xs' ->
      if E.eq e x
      then Some(x)
      else find e xs'
end

