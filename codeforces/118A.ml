let solve =
  let s = read_line () in
    let terminated_s = s ^ "." in
      let rec parse_string i = match terminated_s.[i] with
        | '.' -> print_string "\n"
        | 'a' | 'o' | 'y' | 'e' | 'u' | 'i'
        | 'A' | 'O' | 'Y' | 'E' | 'U' | 'I' -> parse_string (i+1)
        | c when c >= 'A' && c <= 'Z' ->
          print_char '.'; print_char (Char.lowercase c); parse_string (i+1)
        | c -> print_char '.'; print_char c; parse_string (i+1)
      in parse_string 0

let () = solve
