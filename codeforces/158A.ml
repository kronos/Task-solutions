let read_int () = Scanf.scanf " %d" (fun x -> x)

let solve n k =
  let rec advanced_count n i current = match n with
    | 0 -> i
    | _ when current = 0 -> i
    | _ -> let next = read_int () in
            if current = next
            then advanced_count (n - 1) (i + 1) next
            else if i >= k || next = 0 then i
                 else advanced_count (n - 1) (i + 1) next
  in advanced_count n 0 (-1)

let () =
  let n = read_int ()
  and k = read_int ()
  in Printf.printf "%d\n" (solve n k)

