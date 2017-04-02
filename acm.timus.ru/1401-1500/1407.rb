def test(x, n, len, clen)
  if clen == len
    e = x.to_i
    (e % 2**n) == 0 ? e : -1
  else
    a = test("1#{x}", n, len, clen + 1)
    if a == -1
      test("2#{x}", n, len, clen + 1)
    else
      a
    end
  end
end

N = gets.to_i
s = "2"
2.upto(N) do |n|
  len = s.length
  a = test(s, n, len, s.length)
  while a == -1
    len += 1
    a = test(s, n, len, s.length)
  end
  s = a.to_s
end

puts s
