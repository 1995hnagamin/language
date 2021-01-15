open Printf

type item = string

type tree =
  | Item of item
  | Section of tree list

type path =
  | Top
  | Node of tree list * path * tree list

type location = Loc of tree * path

let print_tree =
  let rec print n t =
    for i = 1 to n do print_string " " done;
    match t with
    | Item(x) -> printf "- %s\n" x
    | Section(xs) -> print_string "*\n"; List.iter (print (n+1)) xs
  in
  print 0

let ex1 = Section[
  Section[Item "a"; Item "*"; Item "b"];
  Item "+";
  Section[Item "c"; Item "*"; Item "d"] ]

let () =
  print_tree ex1
