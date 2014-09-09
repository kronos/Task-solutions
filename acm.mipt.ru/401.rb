x,o,y = gets.split(//)
p o=='^' ? x.to_i & y.to_i : x.to_i | y.to_i
