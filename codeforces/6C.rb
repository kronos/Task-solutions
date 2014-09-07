n = gets.to_i
a = gets.split(/\s/).map {|x| x.to_i}

a1 = 0
a2 = 0
t1 = 0
t2 = 0
size = a.size
if size == 1
  puts "1 0"
else
  i = 0
  j = size-1
  while i < j
    if t1 > t2
      while t1 > t2 and i < j
        a2 += 1
        t2 += a[j]
        j -= 1
      end
    elsif t2 > t1
      while t2 > t1 and i < j
        a1 += 1
        t1 += a[i]
        i += 1
      end
    else
      a1 += 1
      a2 += 1
      t1 += a[i]
      t2 += a[j]
      i += 1
      j -= 1
    end
  end

  if a1+a2 != n
    if t1 <= t2
      a1 += 1
    else
      a2 += 1
    end
  end
  puts "#{a1} #{a2}"
end
