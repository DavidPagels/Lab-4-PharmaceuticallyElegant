#!/usr/bin/ruby

require 'find'

dirnum=0
regnum=0

Find.find(ARGV[0]) do |path|
  if FileTest.file?(path)
    regnum += 1
  end
  if FileTest.directory?(path)
    dirnum += 1
   end
end

puts "Processed all the files from <#{ARGV[0]}>."
puts "There were #{dirnum} directories."
puts "There were #{regnum} regular files."
