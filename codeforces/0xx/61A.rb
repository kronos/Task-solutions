s1 = gets.strip
i1 = s1.to_i(2)
i2 = gets.to_i(2)
printf("%0#{s1.length}b\n", i1^i2)
