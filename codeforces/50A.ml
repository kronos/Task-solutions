let read_int () = Scanf.scanf " %d" (fun x -> x)

let () =
  let n = read_int ()
  and m = read_int () in
  Printf.printf "%d\n" (n * m / 2)
