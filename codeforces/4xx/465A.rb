n = gets.to_i
s = gets.strip

i = 0
while i < s.length && s[i] == '1'
  i+=1
end

puts i == s.length ? i : i+1
