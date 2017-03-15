line = gets.strip
a,b = line.split(':', 2).map {|c| c.to_i}
ra = (a%10)*10 + a/10
if ra > b
  b = ra
  if b > 59
    a = a < 10 ? 10 : 20
    b = (a%10)*10 + a/10
  end
else
  a1 = (a+1) % 24
  b1 = (a1%10)*10 + a1/10
  if b1 > 59
    a1 = a < 10 ? 10 : 20
    b1 = (a1%10)*10 + a1/10
  end
  r1 = a1*60+b1

  a2 = (b%10)*10 + b/10
  b2 = b
  r2 = a2*60+b2
  if r1 < r2 || b == ra || (a2 < a && a < 23)
    a, b = a1, b1
  else
    a, b = a2, b2
  end
end

printf "%02d:%02d", a, b
