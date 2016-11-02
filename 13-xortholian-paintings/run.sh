#!/bin/bash

for file in PracticeInput*.txt; do
   ms-paint.py $file > $(basename $file .txt).out
done
