let read_int () = Scanf.scanf " %d" (fun x -> x)

let solve n =
  let rec find_max n max sum = match n with
    | 0 -> max
    | n -> let a = read_int ()
           and b = read_int () in
           let new_sum = sum - a + b in
             if max > new_sum
             then find_max (n - 1) max new_sum
             else find_max (n - 1) new_sum new_sum
  in find_max n 0 0

let () =
  let n = read_int ()
  in Printf.printf "%d\n" (solve n)

