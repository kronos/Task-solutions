n = gets.to_i
a = gets.split(/\s+/).map(&:to_i)

answer = 0
i = 0

i += 1 while i < n && a[i] != 1

answer = 1 if a[i] == 1
current = i
i += 1

while i < n
  i += 1 while i < n && a[i] != 1

  if a[i] == 1
    answer += (i - current > 2) ? 2 : i - current
  end

  current = i
  i += 1
end

p answer
