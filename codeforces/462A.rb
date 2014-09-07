n = gets.to_i
array = Array.new(n)
n.times do |i|
  array[i] = gets.strip.split(//)
end

result = true
i = j = 0

SHIFT = [
  [-1, 0],
  [ 0,-1],
  [ 1, 0],
  [ 0, 1]
]

while i < n && result
  j = 0
  while j < n && result
    c = 0
    SHIFT.each do |(k,z)|
      k += i
      z += j
      c += 1 if k >= 0 && z >=0 && k < n && z < n && array[k][z] == 'o'
    end
    result = c%2 == 0
    j += 1
  end
  i += 1
end

puts result ? "YES" : "NO"
