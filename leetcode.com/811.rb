# @param {String[]} cpdomains
# @return {String[]}
def subdomain_visits(cpdomains)
  values = Hash.new{|h,k| h[k] = 0}
  cpdomains.each do |cpdomain|
    value, domain = cpdomain.split(/\s/, 2)
    value = value.to_i
    domains = domain.split(/\./).reverse
    s = ""
    domains.each do |domain|
      s = s.empty? ? domain : "#{domain}.#{s}"
      values[s] += value
    end
  end
  r = []
  values.each do |k,v|
    r << "#{v} #{k}"
  end
  r
end
