#!/usr/bin/env python

import sys

def letter_to_number(letter):
   return ord(letter) - 97

def number_to_letter(number):
   return chr(97 + number)

def number_to_letter_up(number):
   return chr(65 + number)

def main():
   file = open(sys.argv[1], 'r')
   if file is None:
      sys.exit('No input file')
   line = file.read()
   if line is None:
      sys.exit()

   splitLine = line.split('|')
   msg = splitLine[0]
   key = splitLine[1]
   keynums = []
   cryptolist = []

   for keyindex in range(len(key)):
      keyletter = key[keyindex]
      keynums.append(letter_to_number(keyletter.lower()))

   print msg

   keyindex = 0
   for msgindex in range(len(msg)):
      msgletter = msg[msgindex]
      if msgletter.isalpha():
         keynum = keynums[keyindex]
         keyindex = (keyindex + 1) % len(key)
         msgnum = letter_to_number(msgletter.lower())
         #print("msgletter %s keynum %s msgnum %s" % (msgletter,
         #   keynum, msgnum))
         cryptonum = (keynum + msgnum) % 26
         cryptoletter = number_to_letter(cryptonum) if msgletter.islower() else number_to_letter_up(cryptonum)
         cryptolist.append(cryptoletter)
      else:
         cryptolist.append(msgletter)

   crypto = ''.join(cryptolist)
   print crypto
        
if __name__ == "__main__":
   main()
