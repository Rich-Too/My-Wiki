#!/bin/bash

# 遍历当前文件夹下的所有文件
for file in *; do
    # 检查文件是否是普通文件且没有后缀名
    if [ -f "$file" ] && [ "$file" = "${file%.*}" ]; then
        trash "$file"
        echo "Deleted: $file"
    fi
done
echo "finish"