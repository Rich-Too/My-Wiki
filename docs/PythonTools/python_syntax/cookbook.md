函数可以直接修改列表，但字符串作为一个不可变对象是不能被修改的
`id` 可以获取对象的序号，`dir` 可以获得对象的所有属性
海象运算符：`:=` 能在不允许赋值的地方（如if语句的条件表达式中）使用赋值变量
Python 不应该将可变对象作为函数的默认参数：
```Python
from typing import List 
def add_to_list(num, target: List = []):
    target.append(num)
    return target

print(add_to_list(2))
print(add_to_list(3))
>>> [2]
>>> [2, 3]
# 函数形参的id是确定的
```

接收函数的多个返回值时，其中某一个是不需要的，为了这个不需要的返回值，可以用下划线来处理这种情况