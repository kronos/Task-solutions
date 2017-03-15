
let solve s len =
  let rec solve' prev acc i = match acc, i with
    |   7, _ -> "YES"
    |   _, n when n = len -> "NO"
    | acc, n -> let current = s.[n] in
                if current = prev
                then solve' current (acc + 1) (i + 1)
                else solve' current        1  (i + 1)
  in solve' s.[0] 1 1

let () =
  let s = read_line () in
  Printf.printf "%s\n" (solve s (String.length s))
