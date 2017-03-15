n,m,c = gets.split(/\s+/)
n = n.to_i
m = m.to_i
c = c[0]
a = Array.new(n)
n.times do |i|
  a[i] = gets.strip
end

h = []

0.upto(n-1) do |i|
  0.upto(m-1) do |j|
    next if a[i][j] == ?. or a[i][j] == c
    h << a[i][j] if (i > 0 and a[i-1][j] == c) || (j > 0 and a[i][j-1] == c) ||
                    (i < n-1 and a[i+1][j] == c) || (j < m-1 and a[i][j+1] == c)
  end
end

puts h.uniq.size
