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

let rev_filter_map f xs =
  List.fold_left
    (fun ys x ->
       match f x with
       | Some(y) -> y :: ys
       | None -> ys)
    [] xs

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

let fstset_amend (set1, nul1) (set2, nul2) =
  (SS.union set1 set2, nul1 || nul2)

let first_set gr =
  let rec iter = function
      [] -> (SS.empty, true)
    | Term(a) :: rest -> (SS.singleton a, false)
    | Nont(x) :: rest ->
      let rhss =
        rev_filter_map
          (fun (v, rhs) -> if v = x then Some(rhs) else None)
          gr
      in
      let fstx =
        List.fold_left
          (fun fst rhs -> fstset_amend fst (iter rhs))
          (SS.empty, false) rhss
      in
      if snd fstx
      then fstset_amend fstx (iter rest)
      else fstx
  in
  iter

let g1 = [
  "S", [Nont("A"); Nont("B")];
  "A", [Term("a")];
  "A", [];
  "B", [Term("b")];
  "B", []
]


let () =
  Printf.printf "First set of \"S\":\n";
  let (s, b) = first_set g1 [Nont("S")] in
  SS.iter (fun ch -> Printf.printf "- %s\n" ch) s;
  Printf.printf "Follow set\n";
