#!/bin/bash
echo "Testing mandatory..."

FILES=(test_cases/*.txt)
for file in "${FILES[@]}"; do
	./gnl_mand "$file" > out.txt
	cat "$file" > ref.txt
	if diff -q out.txt ref.txt >/dev/null; then
		echo "✅ $file: OK"
	else
		echo "❌ $file: KO"
		diff -u ref.txt out.txt
	fi
done

rm -f out.txt ref.txt
