x,o,y = s.split(//)
p o=='^' ? x.to_i & y.to_i : x.to_i | y.to_i