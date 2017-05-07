def min(a,b)
  a < b ? a : b
end

gets.to_i.times do
  x, y, p, q = gets.split(/\s+/).map(&:to_i)

  if p == q
    ans = x == y ? 0 : -1
  elsif p == 0
    ans = x == 0 ? 0 : -1
  else
    d = p*y - q*x
    k = q - p
    if d == 0
      ans = 0
    elsif d > 0 && d % k == 0
      ans = d/k
    else
      k = ((y - x.to_f) / (q - p)).ceil
      if k * p < x
        k = x / p + min(x%p, 1)
      end

      if k * q - y < 0
        ans = -1
      else
        ans = q*k-y
      end
    end
  end

  puts ans
end
