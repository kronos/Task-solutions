#$stdin = File.open('in.txt', 'r')
@n,@vb,@vs = gets.split(/\s+/).map {|x| x.to_i}
@stopes = gets.split(/\s+/).map {|x| x.to_i}
@xu,@yu = gets.split(/\s+/).map {|x| x.to_i}

@stopes.unshift(0)

def compute(index)
  @stopes[index]/@vb.to_f + Math.sqrt(@yu*@yu+(@stopes[index]-@xu)*(@stopes[index]-@xu))/@vs
end

if @vs > @vb
  puts 2
else
  kms = @stopes[2].abs
  x = @stopes[2]
  answer = 2
  min = kms/@vb.to_f + Math.sqrt(@yu*@yu+(x-@xu)*(x-@xu))/@vs

  i = 3

  while i <= @n
    kms += (@stopes[i-1].abs-@stopes[i].abs).abs
    x = @stopes[i]
    val = kms/@vb.to_f + Math.sqrt(@yu*@yu+(x-@xu)*(x-@xu))/@vs

    if val < min
      answer = i
      min = val
    elsif (val == min) && ((@stopes[answer]-@xu).abs > (@stopes[i]-@xu).abs)
      answer = i
    end
    i += 1
  end
  puts answer
end
