import os

# for file in os.listdir('./docs'):
base_dir = "./docs"
for dir_path, dir_names, file_names in os.walk(base_dir):
    for dir_name in dir_names:
        if dir_name == ".static":
            os.rename(
                os.path.join(dir_path, dir_name), os.path.join(dir_path, "static")
            )
    for file_name in file_names:
        file_path = os.path.join(dir_path, file_name)
        if file_path.endswith(".md"):
            with open(file_path, "r", encoding="utf-8") as file:
                file_data = file.read()
                if ".static" in file_data:
                    file_data = file_data.replace(".static", "static")
                with open(file_path, "w", encoding="utf-8") as file:
                    file.write(file_data)

# html to markdown
import re

for dir_path, dir_names, file_names in os.walk(base_dir):
    for file_name in file_names:
        file_path = os.path.join(dir_path, file_name)
        if file_path.endswith(".md"):
            with open(file_path, "r", encoding="utf-8") as file:
                content = file.read()
                # 使用正则表达式查找并替换符合条件的部分
                # 正则表达式解析：<img src="任意字符(非贪婪)" alt="任意字符(非贪婪)" 其他任意字符(贪婪)>，并捕获 src 和 alt 的值
                pattern = r'<img src="(.*?)" alt="(.*?)" .*?>'
                replacement = r"![\2](\1)"

                modified_content = re.sub(pattern, replacement, content)

                # 将修改后的内容写回文件
                with open(file_path, "w", encoding="utf-8") as file:
                    file.write(modified_content)
