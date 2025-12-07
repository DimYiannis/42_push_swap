#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

PUSH_SWAP="./push_swap"
CHECKER="./checker_linux"

PASSED=0
FAILED=0

############################################
# FUNCTION: test_case
############################################
test_case() {
  local name="$1"
  local args="$2"
  local expected="$3"

  echo -n "Testing: $name ... "

  # Case: expect nothing (no output)
  if [ "$expected" = "Nothing" ]; then
    output=$($PUSH_SWAP $args 2>&1)
    if [ -z "$output" ]; then
      echo -e "${GREEN}PASS${NC}"
      ((PASSED++))
    else
      echo -e "${RED}FAIL${NC} (got: $output)"
      ((FAILED++))
    fi
    return
  fi

  # Case: expect Error
  if [ "$expected" = "Error" ]; then
    output=$($PUSH_SWAP $args 2>&1)
    if echo "$output" | grep -q "Error"; then
      echo -e "${GREEN}PASS${NC}"
      ((PASSED++))
    else
      echo -e "${RED}FAIL${NC} (got: $output)"
      ((FAILED++))
    fi
    return
  fi

  # Case: expect OK from checker
  if [ "$expected" = "OK" ]; then
    result=$($PUSH_SWAP $args | $CHECKER $args 2>&1)
    if [ "$result" = "OK" ]; then
      echo -e "${GREEN}PASS${NC}"
      ((PASSED++))
    else
      echo -e "${RED}FAIL${NC} (checker: $result)"
      ((FAILED++))
    fi
    return
  fi
}

############################################
# TEST SUITE
############################################
echo "========================================"
echo "      PUSH_SWAP TEST SUITE (fixed)"
echo "========================================"
echo

### 1. Empty Input
echo -e "${YELLOW}=== Empty ===${NC}"
test_case "No arguments" "" "Nothing"
test_case "Only spaces" "    " "Nothing"
echo

### 2. Single
echo -e "${YELLOW}=== Single ===${NC}"
test_case "Single num" "42" "Nothing"
test_case "Single negative" "-42" "Nothing"
test_case "Zero" "0" "Nothing"
echo

### 3. Sorted
echo -e "${YELLOW}=== Sorted ===${NC}"
test_case "1 2" "1 2" "Nothing"
test_case "1 2 3" "1 2 3" "Nothing"
test_case "1 2 3 4 5" "1 2 3 4 5" "Nothing"
echo

### 4. Sorting tests
echo -e "${YELLOW}=== Sorting ===${NC}"
test_case "Two unsorted" "2 1" "OK"
test_case "3 2 1" "3 2 1" "OK"
test_case "5 3 1 4 2" "5 3 1 4 2" "OK"
echo

### 5. Duplicates
echo -e "${YELLOW}=== Duplicates ===${NC}"
test_case "1 2 3 2" "1 2 3 2" "Error"
test_case "1 2 2 3" "1 2 2 3" "Error"
test_case "1 1" "1 1" "Error"
test_case "5 5 5" "5 5 5" "Error"
echo

### 6. Invalid
echo -e "${YELLOW}=== Invalid Input ===${NC}"
test_case "letters" "a b c" "Error"
test_case "alphanum" "1 a2 3" "Error"
test_case "float" "1 2.5 3" "Error"
test_case "special" "1 2 ;" "Error"
echo

### 7. Overflow
echo -e "${YELLOW}=== Overflow ===${NC}"
test_case "2147483648" "2147483648" "Error"
test_case "-2147483649" "-2147483649" "Error"
test_case "valid INT_MAX" "2147483647" "Nothing"
test_case "valid INT_MIN" "-2147483648" "Nothing"
echo

### 8. Random sets
echo -e "${YELLOW}=== Random Sets ===${NC}"
ARG10=$(seq 1 10 | shuf)
test_case "10 random" "$ARG10" "OK"

ARG100=$(seq 1 100 | shuf)
test_case "100 random" "$ARG100" "OK"

ARG500=$(seq 1 500 | shuf)
test_case "500 random" "$ARG500" "OK"
echo

############################################
# Summary
############################################
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
