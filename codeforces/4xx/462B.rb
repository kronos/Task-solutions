n,k = gets.split(/\s+/).map(&:to_i)
h = Hash.new {|h, k| h[k] = 0}
gets.strip.split(//).inject(h) {|h,s| h[s] += 1; h}

result = 0

h.values.sort.reverse.each do |v|
  if v < k
    k -= v
    result += v**2
  else
    result += k**2
    break
  end
end

p result
