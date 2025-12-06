#!/bin/bash

# Function to generate random numbers
generate_numbers() {
    shuf -i 1-5000 -n $1
}

echo "=== Testing 100 numbers (10 tests) ==="
TOTAL_100=0
for i in {1..10}; do
    ARGS=$(generate_numbers 100 | tr '\n' ' ')
    OPS=$(./push_swap $ARGS | wc -l)
    CHECK=$(./push_swap $ARGS | ./checker_linux $ARGS)
    echo "Test $i: $OPS operations - $CHECK"
    TOTAL_100=$((TOTAL_100 + OPS))
done
AVG_100=$((TOTAL_100 / 10))
echo "Average: $AVG_100 operations"
if [ $AVG_100 -lt 700 ]; then
    echo "✓ EXCELLENT! (< 700) - Max score!"
elif [ $AVG_100 -lt 1100 ]; then
    echo "✓ GOOD (< 1100) - Passing"
else
    echo "✗ Needs improvement"
fi

echo ""
echo "=== Testing 500 numbers (5 tests) ==="
TOTAL_500=0
for i in {1..5}; do
    ARGS=$(generate_numbers 500 | tr '\n' ' ')
    OPS=$(./push_swap $ARGS | wc -l)
    CHECK=$(./push_swap $ARGS | ./checker_linux $ARGS)
    echo "Test $i: $OPS operations - $CHECK"
    TOTAL_500=$((TOTAL_500 + OPS))
done
AVG_500=$((TOTAL_500 / 5))
echo "Average: $AVG_500 operations"
if [ $AVG_500 -lt 5500 ]; then
    echo "✓ EXCELLENT! (< 5500) - Max score!"
elif [ $AVG_500 -lt 8500 ]; then
    echo "✓ GOOD (< 8500) - Passing"
else
    echo "✗ Needs improvement"
fi
