n, p = gets.split(/\s+/).map(&:to_i)
s = gets.strip


def get_next(s, n, p)
  if n == 1
    if s[0].ord == p.ord
      nil
    else
      s[0].succ
    end
  else
    q = s[-1] == 'z' ? '{' : s[-1].succ
    x = s[0...-1]
    begin
      while q.ord <= p.ord && (q == x[-1] || q == x[-2])
        q = q == 'z' ? '{' : q.succ
      end

      if q.ord <= p.ord
        return "#{x}#{q}"
      else
        x = get_next(x, n-1, p)
        q = 'a'
      end
    end while x

    nil
  end
end

p = ('a'.ord + p.ord-1).chr

if (s = get_next(s, n, p))
  puts s
else
  puts "NO"
end
