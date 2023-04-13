text = File.read(ARGV[0])
puts RubyVM::InstructionSequence.new(text).disassemble
