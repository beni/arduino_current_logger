#!/usr/bin/env ruby
# coding: UTF-8

require 'serialport'
require 'colorize'

usb_serial = Dir.entries('/dev').select {|i| i if i =~ /tty.usbmodem.*/ }.first
if usb_serial.nil?
  puts "ERROR: No Serial USB cable connected!".red
  exit(-1)
end

begin
  sp = SerialPort.new("/dev/#{usb_serial}", 115200, 8, 1, SerialPort::NONE)
  sleep(1)

  while (line = sp.gets) do
    i = line.encode(Encoding::ASCII, :invalid => :replace, :undef => :replace, :replace => '')
    if i
      if i != "\r\n"
        puts "#{Time.now.strftime("%Y-%m-%d %H:%M:%S.%L")} #{i.chomp}"
      end
    #end
    end
  end

rescue Interrupt
  sp.close
end
