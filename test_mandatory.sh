#!/bin/bash
echo "Testing mandatory..."

FILES=(test_cases/*.txt)
BUFFER_SIZES=( 1 42 1000 1000000)

for BS in "${BUFFER_SIZES[@]}"; do
	echo "🔍 Testing with BUFFER_SIZE=$BS"
	cc -D BUFFER_SIZE=$BS -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -o gnl_mand

	for file in "${FILES[@]}"; do
		./gnl_mand "$file" > out.txt
		cat "$file" > ref.txt
		if diff -q out.txt ref.txt >/dev/null; then
			echo "✅ $file (BS=$BS): OK"
		else
			echo "❌ $file (BS=$BS): KO"
			diff -u ref.txt out.txt
		fi
	done
done

echo ""
echo "🔎 Testing invalid file descriptors"
cc -D BUFFER_SIZE=42 -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c fd_invalid_test.c -o gnl_mand_fd_invalid
./gnl_mand_fd_invalid > fd_invalid_output.txt
cat fd_invalid_output.txt

rm -f gnl_mand gnl_mand_fd_invalid out.txt ref.txt fd_invalid_output.txt
