let is_uppercase c = c >= 'A' && c <= 'Z'

let rec capslocked s = function
  | 0 -> true
  | n -> (is_uppercase s.[n]) && capslocked s (n-1)

let solve =
  let s = read_line () in
    let len = String.length s in
      if capslocked s (len - 1)
      then if is_uppercase s.[0]
           then String.lowercase (String.sub s 0 len)
           else String.uppercase (String.sub s 0 1) ^
                String.lowercase (String.sub s 1 (len - 1))
      else s


let () = Printf.printf "%s\n" solve
