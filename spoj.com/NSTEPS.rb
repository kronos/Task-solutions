N = gets.to_i
1.upto(N) do
  x,y = gets.split(/\s+/).map {|x| x.to_i}
  if y == x-2
    puts x/2*3+x/2+x%2-2
  elsif x == y
    puts x/2*3+x/2+x%2
  else
    puts "No Number"
  end
end
