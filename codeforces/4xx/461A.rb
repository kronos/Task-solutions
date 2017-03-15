n = gets.to_i
a = gets.split(/\s+/).map(&:to_i).sort_by {|e| -e}
sum = result = a.inject {|a,b| a+b}

while a.size > 1
  x = a.pop
  result += sum
  sum -= x
end

p result
