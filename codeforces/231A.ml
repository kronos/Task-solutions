let read_int () = Scanf.scanf " %d" (fun x -> x)

let solve n =
  let rec check_opinions acc = function
    | 0 -> acc
    | n -> let o1 = read_int ()
           and o2 = read_int ()
           and o3 = read_int () in
           if o1 + o2 + o3 > 1
           then check_opinions (acc + 1) (n - 1)
           else check_opinions acc (n - 1)
  in check_opinions 0 n

let () =
  let n = read_int () in
  Printf.printf "%d\n" (solve n)
