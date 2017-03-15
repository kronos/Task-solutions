N = 204
p = gets.strip
x = N/2
y = N/2
i = 0
m = Array.new(N) { Array.new(N,0) }
m[x][y] = 1
while i < p.length
  case p[i]
  when "L" then x-=1
  when "R" then x+=1
  when "U" then y-=1
  when "D" then y+=1
  end
  m[x][y] += 1
  i += 1
end

ok = true
steps = 0

while (x !=N/2 || y!=N/2) && ok
  nx = 0
  ny = 0
  c = m[x-1][y]+m[x+1][y]+m[x][y-1]+m[x][y+1]
  if m[x-1][y] == 1
    nx = -1
  end
  if m[x+1][y] == 1
    nx = +1
  end
  if m[x][y-1] == 1
    ny = -1
  end
  if m[x][y+1] == 1
    ny = +1
  end
  steps += 1
  ok = (c == 1) || steps == p.length
  m[x][y] = 0
  x += nx
  y += ny
end

if steps != p.length || !ok
  puts "BUG"
else
  puts "OK"
end
