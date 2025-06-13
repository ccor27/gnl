#!/bin/bash

# Configuration
FILES=(test_cases_bonus/*.txt)
BUFFER_SIZES=(1 42 1000 1000000)

#function that copies the exact behavior of the bonus main
generate_expected_output() {
    local file1="$1"
    local file2="$2"
    local tmp1=$(mktemp)
    local tmp2=$(mktemp)

    # Read lines of each file separately
    mapfile -t lines1 < "$file1"
    mapfile -t lines2 < "$file2"

    local len1=${#lines1[@]}
    local len2=${#lines2[@]}
    local i=0

    > ref.txt

    while (( i < len1 || i < len2 )); do
        if (( i < len1 )); then
            echo "${lines1[i]}" >> ref.txt
        fi
        if (( i < len2 )); then
            echo "${lines2[i]}" >> ref.txt
        fi
        ((i++))
    done
}

# Nice message
echo "🔎 Testing BONUS version with multiple BUFFER_SIZES and file pairs..."

# Clean previous binary
rm -f gnl_bonus

# Scan each BUFFER_SIZE
for BS in "${BUFFER_SIZES[@]}"; do
    echo ""
    echo "🧪 BUFFER_SIZE = $BS"

    # Compile with the new BUFFER_SIZE
    cc -Wall -Wextra -Werror -D BUFFER_SIZE=$BS \
        get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c -o gnl_bonus

    # Test combinations of 2 files
    for ((i = 0; i < ${#FILES[@]}; i++)); do
        for ((j = i + 1; j < ${#FILES[@]}; j++)); do
            FILE1="${FILES[$i]}"
            FILE2="${FILES[$j]}"
            echo -n "🔁 Testing: $FILE1 + $FILE2 ... "

            # Run program and save output
            ./gnl_bonus "$FILE1" "$FILE2" >out.txt

            # Mix alternating lines in ref.txt
            generate_expected_output "$FILE1" "$FILE2"

            # compare
            if diff -q ref.txt out.txt >/dev/null; then
                echo "✅ PASS"
            else
                echo "❌ FAIL"
                diff -u ref.txt out.txt
            fi

            rm -f out.txt ref.txt
        done
    done
done

# Invalid FD cases
echo -e "\n🚨 Testing invalid file descriptors..."

echo -n "📄 Non-existent file: "
./gnl_bonus "$TEST_DIR/notfound.txt" 2>/dev/null && echo "❌ FAIL" || echo "✅ PASS"

echo -n "🔢 Invalid FD (-1): "
./gnl_bonus "-1" 2>/dev/null && echo "❌ FAIL" || echo "✅ PASS"

# Clear final executable
rm -f gnl_bonus

echo -e "\n✅ Bonus testing complete."
