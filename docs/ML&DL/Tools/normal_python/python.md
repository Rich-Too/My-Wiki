**几种数据类型**

list和tuple

- 用`-1`做索引，获取最后一个元素
- 元素的数据类型也可以不同

```PYTHON
classmates.append('Adam')
classmates.insert(1, 'Jack')
classmates.pop() # 删除末尾
classmates.pop(i)
```

tuple（元组）是一种有序列表，tuple和list非常类似，但是tuple一旦初始化就不能修改，

字典dict和set

Python内置了字典：dict的支持，dict全称dictionary，在其他语言中也称为map，使用键-值（key-value）存储，具有极快的查找速度。dict的key必须是**不可变对象**。

set和dict类似，也是一组key的集合，但不存储value，也没有顺序。由于key不能重复，所以，在set中，没有重复的key，set可以看成数学意义上的无序和无重复元素的集合。

set同样不可以放入可变对象，因为无法判断两个可变对象是否相等，也就无法保证set内部“不会有重复元素”。

```PYTHON
s = set([1, 1, 2, 2, 3, 3])
>>> s {1, 2, 3}
s.add(4)
s.remove(4)
>>> s1 = set([1, 2, 3])
>>> s2 = set([2, 3, 4])
>>> s1 & s2
{2, 3}
>>> s1 | s2
{1, 2, 3, 4}
```





enumerate() 函数用于将一个可遍历的数据对象(如列表、元组或字符串)组合为一个索引序列，同时列出数据和数据下标，一般用在 for 循环当中。

```python
>>> seasons = ['Spring', 'Summer', 'Fall', 'Winter']
>>> list(enumerate(seasons))
[(0, 'Spring'), (1, 'Summer'), (2, 'Fall'), (3, 'Winter')]
>>> list(enumerate(seasons, start=1))    # 下标从 1 开始
[(1, 'Spring'), (2, 'Summer'), (3, 'Fall'), (4, 'Winter')]
```

使用 `next` 函数可以逐个获取迭代器中的元素。在 Python 中，迭代器是一种可以逐个访问元素的对象，常常用于遍历集合或序列等数据结构:

```python
my_list = [1, 2, 3, 4, 5]
my_iter = iter(my_list)

print(next(my_iter)) # 输出 1
print(next(my_iter)) # 输出 2
print(next(my_iter)) # 输出 3
```

接收函数的多个返回值时，其中某一个是不需要的，为了这个不需要的返回值，可以用下划线来处理这种情况

`zip`

> Make an iterator that aggregates elements from each of the iterables. Returns an iterator of tuples, where the i-th tuple contains the i-th element from each of the argument sequences or iterables. The iterator stops when the shortest input iterable is exhausted. With a single iterable argument, it returns an iterator of 1-tuples. With no arguments, it returns an empty iterator.

```python
>>> a = ['a', 'b', 'c', 'd']
>>> b = ['1', '2', '3', '4']
>>> list(zip(a, b))
[('a', '1'), ('b', '2'), ('c', '3'), ('d', '4')]
```

可以用来遍历多个字典：

```PYTHON
dict_one = {'name': 'John', 'last_name': 'Doe', 'job': 'Python Consultant'}
dict_two = {'name': 'Jane', 'last_name': 'Doe', 'job': 'Community Manager'}
>>> list(zip(dict_one.items(), dict_two.items()))
[(('name', 'John'), ('name', 'Jane')), (('last_name', 'Doe'), ('last_name', 'Doe')), (('job', 'Python Consultant'), ('job', 'Community Manager'))]
>>> dict_one.items()
for (k1, v1), (k2, v2) in zip(dict_one.items(), dict_two.items()):
    print(k1, '->', v1)
    print(k2, '->', v2)
# name -> John
# name -> Jane
# last_name -> Doe
# last_name -> Doe
# job -> Python Consultant
# job -> Community Manager
```

