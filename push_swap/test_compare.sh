#!/bin/bash

# Test script to compare different sorting algorithms

echo "=== Comparing Sorting Algorithms ==="
echo ""

# Test with 100 elements
echo "Testing with 100 elements (30 iterations):"
echo -n "Current (Chunk-based): "
for i in {1..30}; do
    ruby -e 'puts (1..100).to_a.shuffle.join(" ")' | xargs ./push_swap | wc -l
done | awk '{sum+=$1; if($1>max) max=$1; if(NR==1||$1<min) min=$1} END {print "Avg:", sum/NR, "Max:", max, "Min:", min}'

# Test with 500 elements
echo ""
echo "Testing with 500 elements (20 iterations):"
echo -n "Current (Chunk-based): "
for i in {1..20}; do
    ruby -e 'puts (1..500).to_a.shuffle.join(" ")' | xargs ./push_swap | wc -l
done | awk '{sum+=$1; if($1>max) max=$1; if(NR==1||$1<min) min=$1} END {print "Avg:", sum/NR, "Max:", max, "Min:", min}'

echo ""
echo "Benchmarks: 100 elements ≤700 ops, 500 elements ≤5500 ops"