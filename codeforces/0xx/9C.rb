s = gets.strip

one = false

0.upto(s.length-1) do |i|
  if (s[i] > ?1) or (one)
    s[i] = ?1
    one = true
  end
end

n = s.to_i(2)
puts n
