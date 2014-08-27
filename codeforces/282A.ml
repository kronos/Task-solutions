let read_int () = Scanf.scanf "%d" (fun x -> x)
let read_string () = Scanf.scanf " %s" (fun x -> x)

let get_bit n =
  let rec calculate_bit r = function
    | 0 -> r
    | n ->  match read_string () with
              | "X++" | "++X" -> calculate_bit (r + 1) (n - 1)
              | "X--" | "--X" -> calculate_bit (r - 1) (n - 1)
              | q -> Printf.printf "%s\n" q; assert  false
  in calculate_bit 0 n


let () = Printf.printf "%d\n" (get_bit (read_int ()))
