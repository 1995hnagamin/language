require 'benchmark'

def tarai(x, y, z)
  if x > y
    tarai(tarai(x-1, y, z), tarai(y-1, z, x), tarai(z-1, x, y))
  else
    y
  end
end

arr = [[10, 5], [11, 5], [12, 6], [13, 6], [13, 7], [14, 7]]

arr.each do |x, y|
  puts "x = #{x}, y = #{y}"
  result = (1..10).map do
    Benchmark.measure { tarai(x, y, 0) }
  end
  puts Benchmark::CAPTION
  puts result.sum(Benchmark::Tms.new) / result.size
end
