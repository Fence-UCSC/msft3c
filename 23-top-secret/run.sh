#!/bin/bash

for file in PracticeInput*.txt; do
   enigma.py $file > $(basename $file .txt).out
done
