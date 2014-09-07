s1 = gets.strip
s2 = gets.strip
if s1.length == s2.length
  s1.length.times do |i|
    unless s1[i-1] == s2[-i]
      puts "NO"
      exit(0)
    end
  end
else
  puts "NO"
  exit(0)
end

puts "YES"
