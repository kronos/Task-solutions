let read_int () = Scanf.scanf " %d" (fun x -> x)

let solve n =
  let data = [|0; 0; 0; 0; 0|] in
    for i = 1 to n do
      match read_int () with
      | 1 when data.(3) > 0 -> data.(3) <- data.(3) - 1; data.(4) <- data.(4) + 1
      | 2 when data.(2) > 0 -> data.(2) <- data.(2) - 1; data.(4) <- data.(4) + 1
      | 3 when data.(1) > 0 -> data.(1) <- data.(1) - 1; data.(4) <- data.(4) + 1
      | i -> data.(i) <- data.(i) + 1
    done;

    if data.(2) > 0 && data.(1) > 0 then begin
      data.(2) <- 0;
      data.(4) <- data.(4) + 1;
      if data.(1) > 1
      then data.(1) <- data.(1)-2
      else data.(1) <- 0
    end;

    if data.(1) mod 4 = 0
    then data.(4) + data.(3) + data.(2) + data.(1) / 4
    else data.(4) + data.(3) + data.(2) + data.(1) / 4 + 1


let () =
  let n = read_int ()
  in Printf.printf "%d\n" (solve n)

