s = gets.strip
l = s[1...-1]
l["at"] = "@"

l["dot"] = "." while l["dot"]
puts "#{s[0].chr}#{l}#{s[-1].chr}"
