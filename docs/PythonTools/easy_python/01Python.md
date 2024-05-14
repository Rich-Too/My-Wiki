## 高级特性和函数式编程
### 高级特性
**迭代**
**生成器**
如果一个函数定义中包含 `yield` 关键字，那么这个函数就不再是一个普通函数，而是一个generator函数，调用一个generator函数将返回一个generator：
```python
def fib(max):
    n, a, b = 0, 0, 1
    while n < max:
        yield b
        a, b = b, a + b
        n = n + 1
    return 'done'

'''
>>> g = fib(6)
>>> while True:
...     try:
...         x = next(g)
...         print('g:', x)
...     except StopIteration as e:
...         print('Generator return value:', e.value)
...         break
...
g: 1
g: 1
g: 2
g: 3
g: 5
g: 8
Generator return value: done
'''
```
直接作用于`for`循环的数据类型有以下几种：
- 集合数据类型，如`list`、`tuple`、`dict`、`set`、`str`等；
- `generator`，包括生成器和带`yield`的generator function。

这些可以直接作用于`for`循环的对象统称为可迭代对象：`Iterable`，可以使用 `isinstance()` 判断一个对象是否是 `Iterable` 对象：
```python
>>> from collections.abc import Iterable
>>> isinstance([], Iterable)
True
```
而生成器不但可以作用于 `for` 循环，还可以被 `next()` 函数不断调用并返回下一个值，直到最后抛出 `StopIteration` 错误表示无法继续返回下一个值了，可以被 `next()` 函数调用并不断返回下一个值的对象称为迭代器：`Iterator`。

生成器都是`Iterator`对象，但`list`、`dict`、`str`虽然是`Iterable`，却不是`Iterator`。把`list`、`dict`、`str`等`Iterable`变成`Iterator`可以使用`iter()`函数：

### 函数式编程
**map 和 reduce**
- `map()` 函数接收两个参数，一个是函数，一个是 `Iterable`，`map` 将传入的函数依次作用到序列的每个元素，并把结果作为新的 `Iterator` 返回。

- `reduce`把一个函数作用在一个序列`[x1, x2, x3, ...]`上，这个函数必须接收两个参数，`reduce`把结果继续和序列的下一个元素做累积计算，其效果就是：

```
reduce(f, [x1, x2, x3, x4]) = f(f(f(x1, x2), x3), x4)
```

```python
from functools import reduce

DIGITS = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}

def char2num(s):
    return DIGITS[s]

def str2int(s):
    return reduce(lambda x, y: x * 10 + y, map(char2num, s))
```


## 面向对象
```python
class Student(object):

    def __init__(self, name, score):
        self.name = name
        self.score = score
```
`__init__` 方法的第一个参数永远是 `self`，表示创建的实例本身。
- 实例的变量名如果以 `__` 开头，就变成了一个私有变量（private），只有内部可以访问，外部不能访问
- 变量名类似 `__xxx__` 的为特殊变量，可以直接访问的，而非private变量
- 对于单下划线的变量，虽然可以被访问，但是应该视为私有变量，不要随意访问
- 双下划线开头的实例变量事实上也可以被访问，Python解释器对外把 `__name` 变量改成了 `_Student__name`，仍然可以通过 `_Student__name` 来访问 `__name` 变量

**使用__slots__**

Python允许在定义class的时候，定义一个特殊的 `__slots__` 变量，来限制该class实例能添加的属性。`__slots__` 定义的属性仅对当前类实例起作用，对继承的子类不起作用，除非在子类中也定义`__slots__`，这样，子类实例允许定义的属性就是自身的 `__slots__` 加上父类的 `__slots__`。
```python
class Student(object):
    __slots__ = ('name', 'age') # 用tuple定义允许绑定的属性名称
```

**使用@property**
Python内置的 `@property` 装饰器可以把对象的一个方法变成属性调用：
```python
class Student(object):

    @property
    def score(self):
        return self._score

    @score.setter
    def score(self, value):
        if not isinstance(value, int):
            raise ValueError('score must be an integer!')
        if value < 0 or value > 100:
            raise ValueError('score must between 0 ~ 100!')
        self._score = value
>>> s = Student()
>>> s.score = 60 # OK，实际转化为s.set_score(60)
>>> s.score # OK，实际转化为s.get_score()
```







## 数据结构
**list和tuple**

- 用`-1`做索引，获取最后一个元素
- 元素的数据类型也可以不同

```PYTHON
classmates.append('Adam')
classmates.insert(1, 'Jack')
classmates.pop() # 删除末尾
classmates.pop(i)
```

tuple（元组）是一种有序列表，tuple和list非常类似，但是tuple一旦初始化就不能修改，

**字典dict和set**

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
遍历 dict 时需要使用`items()`




**enumerate()** 

函数用于将一个可遍历的数据对象(如列表、元组或字符串)组合为一个索引序列，同时列出数据和数据下标，一般用在 for 循环当中。

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

**zip**

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

