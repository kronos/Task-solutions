def prime(i)
  return true  if i==2
  return false if i < 2 || i % 2 == 0
  d = 3
  z = (Math.sqrt(i)+0.5).to_i
  f = true
  while d<=z && f
    f = (i % d) != 0
    d+= 2
  end

  return f
end

p = 2**31
i = 0
a = 1
s = ""

while i<1000
  print prime(a) ? "1" : "0"
  a = (a + 1234567890) % p
  i+=1
end
