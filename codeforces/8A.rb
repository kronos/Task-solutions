map = gets.strip
x = gets.strip
y = gets.strip

result = "fantasy"
i = map.index(x)
if i
  result = "forward" if map.index(y, i+x.length)
end
map.reverse!

i = map.index(x)
if i
  if map.index(y, i+x.length)
    if result == "forward"
      result = "both"
    else
      result = "backward"
    end
  end
end
puts result
