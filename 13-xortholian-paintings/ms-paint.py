#!/usr/bin/env python

import sys

def is_primary(color):
   return color == 'red' or color == 'yellow' or color == 'blue'

def find_other_parent(parent, child):
   if parent == 'red':
      if child == 'orange':
         return 'yellow'
      elif child == 'purple':
         return 'blue'
   elif parent == 'yellow':
      if child == 'orange':
         return 'red'
      elif child == 'green':
         return 'blue'
   elif parent == 'blue':
      if child == 'purple':
         return 'red'
      elif child == 'green':
         return 'yellow'
   return None

def main():
   file = open(sys.argv[1], 'r')
   if file is None:
      sys.exit('No input file')
   line = file.read()
   if line is None:
      sys.exit()

   secondRow = line.split()
   firstRow = []
   firstRow.append(secondRow[0])
   for index in range(len(secondRow) - 2):
      leftParent = firstRow[index]
      child = secondRow[index + 1]
      rightParent = None

      if child == 'blank':
         rightParent = 'blank'
      elif leftParent == 'blank':
         rightParent = child
      elif is_primary(child):
         # child is a primary color and matches leftParent
         # rightParent indeterminate, could equal rightParent/child or blank
         # need to look ahead to see
         nextChild = secondRow[index + 2]
         if find_other_parent(leftParent, nextChild) is None:
            rightParent = 'blank'
         else:
            rightParent = leftParent
      else:
         rightParent = find_other_parent(leftParent, child)

      firstRow.append(rightParent)

   # Last item, never mind not needed
   # firstRow.append(secondRow[-1])

   print(" ".join(str(color) for color in firstRow))

if __name__ == "__main__":
   main()
