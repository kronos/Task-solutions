n = gets.to_i
b = {}
h = Hash.new {|h, k| h[k] = 0}
a = gets.split(/\s+/).map {|q| r = q.to_i; h[r]+=1; r}

r = 0
diff = a.max - a.min
if diff > 0
  a.each {|q| r += h[q + diff] }
else
  h.each {|k,v| r += v*(v-1)/2 if v > 1 }
end

puts "#{diff} #{r}"
