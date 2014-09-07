i = gets.to_i
if (i % 7) == 0
  r = '7'*(i/7)
else
  if i < 4
    r = '-1'
  else
    seven = i/7
    while seven > -1 && (i-seven*7) % 4 != 0
      seven -= 1
    end

    if seven == -1
      r = '-1'
    else
      r = "#{'4' * ((i - seven*7) / 4)}#{'7' * seven}\n"
    end
  end
end
puts r
