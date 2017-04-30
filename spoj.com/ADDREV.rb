N = gets.to_i
1.upto(N) do
  s1,s2 = gets.split(/\s+/)
  i1 = s1.reverse.to_i
  i2 = s2.reverse.to_i
  i3 = (i1+i2).to_s.reverse.to_i
  p i3
end
