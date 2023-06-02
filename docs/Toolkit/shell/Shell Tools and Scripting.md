# Shell Tools and Scripting

> terminal 是什么？

<aside> 💡 Terminal Emulator，模拟传统终端的行为一个应用程序，提供了一个窗口，和输入输出交互的功能内部运行的是 Shell，Shell 才是执行命令得到输出的东西 Terminal 的任务是从用户获取输入，然后传递给 Shell，等待 Shell 执行完后，将结果再传递回用户（显示出来）Shell 的任务是从 Terminal 拿到输入指令，解析后交给内核执行，然后将结果返回给 Terminal.

</aside>

> shell 是什么？

<aside> 💡 Shell俗称壳程序，是一种由C语言编写的用于和操作系统交互的命令解析器软件。它用来接收用户输入命令，然后调用相应的应用程序。

Shell同时又是一种程序设计语言。作为命令语言，它交互式解释和执行用户输入的命令或者自动地解释和执行预先设定好的一连串的命令；作为程序设计语言，它定义了各种变量和参数，并提供了许多在高级语言中才具有的控制结构，包括循环和分支。

Shell 有两种执行命令的方式交互式和批处理，如下：

- 交互式（Interactive）：解释执行用户的命令，用户输入一条命令，Shell就解释执行一条。
- 批处理（Batch）：用户事先写一个Shell脚本(Script)，其中有很多条命令，让Shell一次把这些命令执行完，而不必一条一条地敲命令。 </aside>

## 参考资料

[Linux 命令大全 | 菜鸟教程](https://www.runoob.com/linux/linux-command-manual.html)[Shell 教程 | 菜鸟教程](https://www.runoob.com/linux/linux-shell.html)

## 程序间连接

**输入重定向** 输入重定向指把命令（或可执行程序）的标准输入重定向到指定的文件中。也就是说，输入可以不来自键盘，而来自一个指定的文件。所以说，输入重定向主要用于改变一个命令的输入源，特别是改变那些需要大量输入的输入源。 **输出重定向** 输出重定向：指把命令（或可执行程序）的标准输出或标准错误输出重新定向到指定文件中。这样，该命令的输出就**不显示在屏幕**上，而是写入到指定文件中。

```bash
echo hello > hello.txt
cat hello.txt
#hello
cat < hello.txt
#hello
cat < hello.txt > hello2.txt
cat hello2.txt
#hello
```

使用 >> 来向一个文件追加内容。使用管道（ *pipes* ），我们能够更好的利用文件重定向。 | 操作符允许我们将一个程序的输出和另外一个程序的输入连接起来。

## 参数和返回值

在bash中为变量赋值的语法是foo=bar，访问变量中存储的数值，其语法为 $foo。 需要注意的是，foo = bar （使用空格隔开）是不能正确工作的，因为解释器会调用程序foo 并将 = 和 bar作为参数。 总的来说，在shell脚本中使用空格会起到分割参数的作用，有时候可能会造成混淆，请务必多加检查。

```bash
foo=bar
echo "$foo"
# 打印 bar
echo '$foo'
# 打印 $foo
echo $foo
# 打印 bar
#以'定义的字符串为原义字符串，其中的变量不会被转义，而 "定义的字符串会将变量值进行替换。
```

- $0 - 脚本名
- $1 到 $9 - 脚本的参数。 $1 是第一个参数，依此类推。
- $@ - 所有参数
- $# - 参数个数
- $? - 前一个命令的返回值
- $$ - 当前脚本的进程识别码
- !! - 完整的上一条命令，包括参数。常见应用：当你因为权限不足执行命令失败时，可以使用 sudo !!再尝试一次。
- $_ - 上一条命令的最后一个参数。如果你正在使用的是交互式 shell，你可以通过按下 Esc 之后键入 . 来获取这个值。

命令通常使用 **STDOUT**来返回输出值，使用**STDERR**来返回错误及错误码，便于脚本以更加友好的方式报告错误。 返回码或退出状态是脚本/命令之间交流执行状态的方式。返回值0表示正常执行，其他所有非0的返回值都表示有错误发生。

退出码可以搭配 &&（与操作符）和 ||（或操作符）使用，用来进行条件判断，决定是否执行其他程序。它们都属于短路[运算符](https://en.wikipedia.org/wiki/Short-circuit_evaluation)（short-circuiting） 同一行的多个命令可以用 ; 分隔。程序 true 的返回码永远是0，false 的返回码永远是1。|| 若前面是false，执行右边命令，前面为true，不执行后边命令。&&若前面是false，不执行后边命令；若前面为true，执行后边命令。

```bash
false || echo "Oops, fail"
# Oops, fail

true || echo "Will not be printed"
#

true && echo "Things went well"
# Things went well

false && echo "Will not be printed"
#

false ; echo "This will always run"
# This will always run
#!/bin/bash
# #!告诉系统其后路径所指定的程序即是解释此脚本文件的 Shell 程序。
echo "Starting program at $(date)" # date会被替换成日期和时间
echo "Running program $0 with $# arguments with pid $$"
for file in "$@"; do
    grep foobar "$file" > /dev/null 2> /dev/null
    # >重定向标准输出流，2>重定向标准错误流。
    # 如果模式没有找到，则grep退出状态为 1
    # 我们将标准输出流和标准错误流重定向到Null，这些会被丢弃
    if [[ $? -ne 0 ]]; then
        echo "File $file does not have any foobar, adding one"
        echo "# foobar" >> "$file"
    #-ne 代表不等于0，即返回值为1，错误
    #输入man test查看更多比较命令
    fi
done
```

## 如何运行shell脚本

```bash
#1.作为可执行程序将上面的代码保存为 test.sh，并 cd 到相应目录：
chmod +x ./test.sh  #使脚本具有执行权限
./test.sh  					#执行脚本
#注意，一定要写成 ./test.sh，而不是 test.sh，运行其它二进制的程序也一样，直接写 test.sh，
#linux 系统会去 PATH 里寻找有没有叫 test.sh 的，而只有 /bin, /sbin, /usr/bin，/usr/sbin
#等在 PATH 里，要用 ./test.sh 告诉系统说，就在当前目录找。

#2.作为解释器参数，这种运行方式是直接运行解释器，其参数就是 shell 脚本的文件名，如：
/bin/sh test.sh
#这种方式运行的脚本，不需要在第一行指定解释器信息，写了也没用。
```

## shell的通配符

> 通配符 - 想要利用通配符进行匹配时，使用 ? 和 * 来匹配一个或任意个字符。例如，对于文件foo, foo1, foo2, foo10 和 bar ,rm foo?这条命令会删除foo1 和 foo2 ，而rm foo*则会删除除了bar之外的所有文件。花括号{} - 当你有一系列的指令，其中包含一段公共子串时，可以用花括号来自动展开这些命令。这在批量移动或转换文件时非常方便

```bash
convert image.{png,jpg}
# 会展开为
convert image.png image.jpg

cp /path/to/project/{foo,bar,baz}.sh /newpath
# 会展开为
cp /path/to/project/foo.sh /path/to/project/bar.sh /path/to/project/baz.sh /newpath

# 也可以结合通配使用
mv *{.py,.sh} folder
# 会移动所有 *.py 和 *.sh 文件

mkdir foo bar

# 下面命令会创建foo/a, foo/b, ... foo/h, bar/a, bar/b, ... bar/h这些文件
touch {foo,bar}/{a..h}

touch foo/x bar/y
# 比较文件夹 foo 和 bar 中包含文件的不同
diff <(ls foo) <(ls bar)
# 输出
# < x
# ---
# > y
```

### shebang

```bash
#!/usr/local/bin/python
import sys
for arg in reversed(sys.argv[1:]):
    print(arg)
```

> 内核知道去用 python 解释器而不是 shell 命令来运行这段脚本，是因为脚本的开头第一行的 shebang。 env 命令会利用环境变量中的程序来解析该脚本，这样就提高来脚本的可移植性。env 会利用PATH 环境变量来进行定位。#!/usr/bin/env python

## Shell 工具

### 查看命令如何使用

`ls -lman rm`[TLDR pages](https://tldr.sh/) 是一个很不错的替代品，它提供了一些案例，可以帮助您快速找到正确的选项。

### 查找文件

```
find
# 查找所有名称为src的文件夹
find . -name src -type d
# 查找所有文件夹路径中包含test的python文件
find . -path '**/test/*.py' -type f
# 查找前一天修改的所有文件
find . -mtime -1
# 查找所有大小在500k至10M的tar.gz文件
find . -size +500k -size -10M -name '*.tar.gz'
# 删除全部扩展名为.tmp 的文件
find . -name '*.tmp' -exec rm {} \\\\;
# 查找全部的 PNG 文件并将其转换为 JPG
find . -name '*.png' -exec convert {} {}.jpg \\\\;
locate
```

> locate 使用一个由 updatedb负责更新的数据库，在大多数系统中 updatedb 都会通过 cron 每日更新。find 和类似的工具可以通过别的属性比如文件大小、修改时间或是权限来查找文件，locate则只能通过文件名。 这里有一个更详细的对比。

```
grep
```

> grep 有很多选项，这也使它成为一个非常全能的工具。其中我经常使用的有 -C ：获取查找结果的上下文（Context）；-v 将对结果进行反选（Invert），也就是输出不匹配的结果。举例来说， grep -C 5 会输出匹配结果前后五行。当需要搜索大量文件的时候，使用 -R 会递归地进入子目录并搜索所有的文本文件。

[rg](https://github.com/BurntSushi/ripgrep)是一种替代品。

```bash
# 查找所有使用了 requests 库的文件
rg -t py 'import requests'
# 查找所有没有写 shebang 的文件（包含隐藏文件）
rg -u --files-without-match "^#!"
# 查找所有的foo字符串，并打印其之后的5行
rg foo -A 5
# 打印匹配的统计信息（匹配的行和文件的数量）
rg --stats PATTERN
```

## 查找 shell 命令

`history` 	`history | grep find`会打印包含"find"子串的命令 `Ctrl+R`	对命令历史记录进行回溯搜索。 `ls -R`		列出目录结构

## echo

### 1.显示变量

read 命令从标准输入中读取一行,并把输入行的每个字段的值指定给 shell 变量

```bash
#!/bin/sh
read name
echo "$name It is a test"
sh test.sh
OK                     #标准输入
OK It is a test        #输出
```

### 2.显示换行

```bash
#!/bin/sh
echo -e "OK! \\\\n" # -e 开启转义
echo "It is a test"

echo -e "OK! \\\\c" # -e 开启转义 \\\\c 不换行
echo "It is a test"
```

### 3.原样输出字符串，不进行转义或取变量(用单引号)

### 4.显示命令执行结果

```
echo  date
```

3.原样输出字符串，不进行转义或取变量(用单引号) 4.显示命令执行结果 echo  date
