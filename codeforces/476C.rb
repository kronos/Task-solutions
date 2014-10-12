a, b = gets.split(/\s+/).map(&:to_i)

if b > 1
  x1 = (b + 1 + a*b + 1)*a / 2
  xn = (b - 1)*(b + 1 + a*b + 1)*a / 2
  ans = (x1 + xn)*(b - 1) / 2
else
  ans = 0
end

p ans % 1000000007
