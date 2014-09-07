a,b,c = gets.split(/\s+/).map {|x| x.to_i}
r = []

def sum(n)
  a = 0
  while n > 0
    a += n%10
    n/=10
  end
  a
end

(1..81).each do |x|
  q = (x**a)*b + c
  r << q if q > 0 && q == (sum(q)**a)*b+c && q < 1_000_000_000
end

p r.size
puts r.sort*" " if r != []
