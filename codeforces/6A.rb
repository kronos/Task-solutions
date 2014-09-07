a,b,c,d = gets.split(/\s/).map{|x| x.to_i}
tr = false
seg = false

[[a,b,c],
 [a,b,d],
 [b,c,d],
 [a,c,d]].each do |x,y,z|
  p = (x+y+z)/2.0
  f = p*(p-x)*(p-y)*(p-z)
  if f > 0.0
    tr = true
    break
  elsif f == 0.0
    seg = true
  end
end

if tr
  puts "TRIANGLE"
elsif seg
  puts "SEGMENT"
else
  puts "IMPOSSIBLE"
end
