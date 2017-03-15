
let solve s len =
  let rec solve' prev_char acc = function
    | n when n = len -> acc
    | n -> let current_char = s.[n] in
             if current_char = prev_char
             then solve' current_char (acc+1) (n+1)
             else solve' current_char acc (n+1)
  in solve' s.[0] 0 1

let () =
  let len = read_int ()
  and s = read_line () in
  Printf.printf "%d\n" (solve s len)
