#!/bin/bash

# Recursive function to rename directories
rename_directories() {
  for dir in "$1"/*; do
    if [ -d "$dir" ]; then
      new_name=$(echo "$dir" | tr ' ' '-')
      mv "$dir" "$new_name"
      rename_directories "$new_name"
    fi
  done
}

# Starting from the current directory
rename_directories .

echo "Directories renamed successfully."
