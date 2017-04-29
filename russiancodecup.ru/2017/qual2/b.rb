t = gets.to_i
t.times do
  a, b, c, d = gets.split(/\s+/).map(&:to_i)
  if b != d
    e = d*a
    bottom = d*b
    f = b*c
  else
    e = a
    f = c
    bottom = d
  end
  top = e.lcm(f)
  p = top.gcd(bottom)
  puts "#{top/p} #{bottom/p}"
end
