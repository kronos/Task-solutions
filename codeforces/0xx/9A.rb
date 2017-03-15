w, y = gets.split(/\s+/).map {|x| x.to_i}
m = w > y ? w : y

case m
  when 1 then puts "1/1" # 1 2 3 4 5 6
  when 2 then puts "5/6" # 2 3 4 5 6
  when 3 then puts "2/3" # 3 4 5 6
  when 4 then puts "1/2" # 4 5 6
  when 5 then puts "1/3" # 5 6
  when 6 then puts "1/6" # 6
end
