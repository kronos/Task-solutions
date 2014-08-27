
let solve s len =
  let rec solve' i = match s.[i], i with
    | 'H', _ | 'Q', _ | '9', _ -> "YES"
    |   _, n when n = len -> "NO"
    |   _, n -> solve' (i + 1)
  in solve' 0

let () =
  let s = read_line () in
  Printf.printf "%s\n" (solve (s ^ " ") (String.length s))
