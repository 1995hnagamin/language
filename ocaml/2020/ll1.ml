(*
let rec filter_map f = function
    [] -> []
  | x :: xs ->
    match f x with
    | Some(y) -> y :: (filter_map f xs)
    | None -> filter_map f xs
*)

let filter_map f xs =
  List.fold_right
    (fun x ys ->
       match f x with
       | Some(y) -> y :: ys
       | None -> ys)
    xs []


type chr = string

type var = string

type symbol =
  | Term of chr
  | Nont of var

type grammar = (var * (symbol list)) list

module Chr = struct
  type t = chr
  let compare = compare
end

module SS = Set.Make(Chr)

let fset_amend (set1, nul1) (set2, nul2) =
  (SS.union set1 set2, nul1 || nul2)

let rec first_set gr = function
    [] -> (SS.empty, true)
  | Term(a) :: rest -> (SS.singleton a, false)
  | Nont(x) :: rest ->
    let rhss = filter_map (fun (v, rhs) -> if v = x then Some(rhs) else None) gr in
    let (fstx, nullable) =
      List.fold_left (fun fst rhs -> fset_amend fst (first_set gr rhs))
        (SS.empty, false) rhss
    in
    if not nullable
    then (fstx, nullable)
    else
      fset_amend (fstx, nullable) (first_set gr rest)

let g1 = [
  "S", [Nont("A"); Nont("B")];
  "A", [Term("a")];
  "A", [];
  "B", [Term("b")];
  "B", []
]
