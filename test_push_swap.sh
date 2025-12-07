#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

PUSH_SWAP="./push_swap"
CHECKER="./checker_linux"

# Counters
PASSED=0
FAILED=0

# Test function
test_case() {
  local name="$1"
  local args="$2"
  local expected="$3" # "OK", "Error", "Nothing", or number

  echo -n "Testing: $name ... "

  if [ "$expected" = "Nothing" ]; then
    output=$($PUSH_SWAP $args 2>&1)
    if [ -z "$output" ]; then
      echo -e "${GREEN}PASS${NC}"
      ((PASSED++))
    else
      echo -e "${RED}FAIL${NC} (expected nothing, got: $output)"
      ((FAILED++))
    fi
  elif [ "$expected" = "Error" ]; then
    output=$($PUSH_SWAP $args 2>&1)
    if echo "$output" | grep -q "Error"; then
      echo -e "${GREEN}PASS${NC}"
      ((PASSED++))
    else
      echo -e "${RED}FAIL${NC} (expected Error, got: $output)"
      ((FAILED++))
    fi
  elif [ "$expected" = "OK" ]; then
    result=$($PUSH_SWAP $args | $CHECKER $args 2>&1)
    if [ "$result" = "OK" ]; then
      echo -e "${GREEN}PASS${NC}"
      ((PASSED++))
    else
      echo -e "${RED}FAIL${NC} (checker returned: $result)"
      ((FAILED++))
    fi
  fi
}

echo "========================================"
echo "      PUSH_SWAP TEST SUITE"
echo "========================================"
echo

# 1. Empty/No Input
echo -e "${YELLOW}=== Empty/No Input ===${NC}"
test_case "No arguments" "" "Nothing"
echo

# 2. Single Element
echo -e "${YELLOW}=== Single Element ===${NC}"
test_case "Single number" "42" "Nothing"
test_case "Single negative" "-42" "Nothing"
test_case "Single zero" "0" "Nothing"
echo

# 3. Already Sorted
echo -e "${YELLOW}=== Already Sorted ===${NC}"
test_case "Two sorted" "1 2" "Nothing"
test_case "Three sorted" "1 2 3" "Nothing"
test_case "Five sorted" "1 2 3 4 5" "Nothing"
test_case "Negative sorted" "-5 -3 -1 0 2" "Nothing"
echo

# 4. Two Elements
echo -e "${YELLOW}=== Two Elements ===${NC}"
test_case "Two unsorted" "2 1" "OK"
echo

# 5. Three Elements
echo -e "${YELLOW}=== Three Elements ===${NC}"
test_case "Three unsorted (3 2 1)" "3 2 1" "OK"
test_case "Three unsorted (2 3 1)" "2 3 1" "OK"
test_case "Three unsorted (1 3 2)" "1 3 2" "OK"
echo

# 6. Five Elements
echo -e "${YELLOW}=== Five Elements ===${NC}"
test_case "Five random" "5 3 1 4 2" "OK"
test_case "Five reverse" "5 4 3 2 1" "OK"
echo

# 7. Duplicates
echo -e "${YELLOW}=== Duplicates ===${NC}"
test_case "Duplicate at end" "1 2 3 2" "Error"
test_case "Duplicate consecutive" "1 2 2 3" "Error"
test_case "All same" "5 5 5" "Error"
test_case "Two duplicates" "1 1" "Error"
echo

# 8. Invalid Numbers
echo -e "${YELLOW}=== Invalid Numbers ===${NC}"
test_case "Non-numeric" "1 two 3" "Error"
test_case "Mixed alphanumeric" "1 2a 3" "Error"
test_case "Only letters" "abc" "Error"
test_case "Special chars" "1 2 3;" "Error"
test_case "Float number" "1 2.5 3" "Error"
echo

# 9. Integer Overflow
echo -e "${YELLOW}=== Integer Overflow ===${NC}"
test_case "INT_MAX + 1" "2147483648" "Error"
test_case "INT_MIN - 1" "-2147483649" "Error"
test_case "INT_MAX (valid)" "2147483647" "Nothing"
test_case "INT_MIN (valid)" "-2147483648" "Nothing"
test_case "Way too big" "999999999999999" "Error"
test_case "Way too small" "-999999999999999" "Error"
echo

# 10. Signs
echo -e "${YELLOW}=== Signs ===${NC}"
test_case "Positive sign" "+1 +2 +3" "Nothing"
test_case "Mixed signs" "-1 +2 -3 +4" "OK"
test_case "Double positive" "1 ++2 3" "Error"
test_case "Double negative" "1 --2 3" "Error"
test_case "Sign in middle" "1 2- 3" "Error"
test_case "Only sign" "+" "Error"
test_case "Only minus" "-" "Error"
echo

# 11. Larger Sets
echo -e "${YELLOW}=== Larger Sets ===${NC}"
ARG10=$(seq 1 10 | shuf)
test_case "10 random numbers" "$ARG10" "OK"

ARG100=$(seq 1 100 | shuf)
test_case "100 random numbers" "$ARG100" "OK"

ARG500=$(seq 1 500 | shuf)
test_case "500 random numbers" "$ARG500" "OK"
echo

# 12. Edge Cases with Spaces
echo -e "${YELLOW}=== String Input Format ===${NC}"
test_case "String with spaces" '"1 2 3"' "Nothing"
test_case "String unsorted" '"3 2 1"' "OK"
test_case "String with duplicate" '"1 2 3 2"' "Error"
test_case "String with invalid" '"1 two 3"' "Error"
echo

# Summary
echo "========================================"
echo -e "Results: ${GREEN}${PASSED} passed${NC}, ${RED}${FAILED} failed${NC}"
echo "========================================"

if [ $FAILED -eq 0 ]; then
  echo -e "${GREEN}All tests passed! ✅${NC}"
  exit 0
else
  echo -e "${RED}Some tests failed! ❌${NC}"
  exit 1
fi
