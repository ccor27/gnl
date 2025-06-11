#!/bin/bash

echo "🧪 Ejecutando test BONUS de GNL con múltiples fds..."

EXEC=./gnl_bonus
OUT=out_bonus.txt
REF=ref_bonus.txt
TEST_FILES_DIR="test_cases"

# Lista de archivos que tienes
FILES=(
    "$TEST_FILES_DIR/1char.txt"
    "$TEST_FILES_DIR/empty.txt"
    "$TEST_FILES_DIR/one_line_no_nl.txt"
    "$TEST_FILES_DIR/only_multiple_nl.txt"
    "$TEST_FILES_DIR/only_nl.txt"
)

# Ejecutar el binario con los archivos
$EXEC "${FILES[@]}" > "$OUT"

# Si el archivo de referencia no existe, lo creamos automáticamente
if [ ! -f "$REF" ]; then
    echo "⚠️  Archivo de referencia ($REF) no existe. Creando automáticamente..."
    cp "$OUT" "$REF"
    echo "📌 Revisa $REF y ajústalo si hace falta para futuras comparaciones."
    exit 0
fi

# Comparar salida
if diff -u "$REF" "$OUT" > diff_result.txt; then
    echo "✅ BONUS TEST PASADO"
else
    echo "❌ BONUS TEST FALLÓ"
    echo "--- Diferencias ---"
    cat diff_result.txt
fi

# Limpieza
rm -f diff_result.txt
