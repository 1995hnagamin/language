class A
  def initialize()
    @hash = Hash.new { |hash, name| hash[name] = [] }
  end
  def func(name, id, &block)
    @hash[name] << { id: id, block: block }
  end
end

class B
  def initialize()
    @a = A.new
  end
  def func(name, id, &block)
    @a.func(name, id, &block)
  end
end


def func(b, name, id)
  b.func(name, id) {|*args| yield(*args) }
end


b = B.new
1000.times do |n|
  func(b, n, "id")
end
