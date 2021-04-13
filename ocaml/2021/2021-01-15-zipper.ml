open Printf

type item = string

type tree =
  | Item of item
  | Section of tree list

type path =
  | Top
  | Node of tree list * path * tree list

type location = Loc of tree * path

let rec print_tree n t =
  for i = 1 to n do print_string " " done;
  match t with
  | Item(x) -> printf "- %s\n" x
  | Section(xs) -> print_string "*\n"; List.iter (print_tree (n+1)) xs

let rec print_path n p =
  for i = 1 to n do print_string " " done;
  match p with
  | Top -> printf "- Top\n"
  | Node(l, p, r) ->
    print_string "*\n";
    List.iter (print_tree (n+1)) l;
    print_path (n+1) p;
    List.iter (print_tree (n+1)) r

let print_loc n l =
  match l with
  Loc(t, p) -> print_tree n t; print_path n p

let go_left (Loc(t, p)) = match p with
  | Top -> failwith "left of top"
  | Node(l::left, up, right) -> Loc(l, Node(left, up, t::right))
  | Node([], up, right) -> failwith "left of first"

let ex1 = Section[
  Section[Item "a"; Item "*"; Item "b"];
  Item "+";
  Section[Item "c"; Item "*"; Item "d"] ]

let loc1 = Loc(
  Item "+",
  Node([Item "c"],
       Node([Item "+"; Section [Item "a"; Item "+"; Item "b"]],
            Top,
            []),
       [Item "d"])
)

let () =
  print_tree 0 ex1;
  print_loc 0 loc1
