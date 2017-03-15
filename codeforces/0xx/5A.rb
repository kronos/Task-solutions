traffic = count = 0

while l = gets
  l.strip!
  case l[0]
  when "+"
    count += 1
  when "-"
    count -= 1
  else
    traffic += count * l.split(':', 2)[1].length
  end
end

puts traffic
