矩阵求导的本质与分子布局、分母布局的本质（矩阵求导——本质篇） - Iterator的文章 - 知乎 https://zhuanlan.zhihu.com/p/263777564

矩阵求导公式的数学推导（矩阵求导——基础篇） - Iterator的文章 - 知乎 https://zhuanlan.zhihu.com/p/273729929

矩阵求导公式的数学推导（矩阵求导——进阶篇） - Iterator的文章 - 知乎 https://zhuanlan.zhihu.com/p/288541909

## 线性代数

### 降维

```python
x = torch.arange(24)
x = x.reshape(2,2,6)
>>>tensor([[[ 0,  1,  2,  3,  4,  5],
         [ 6,  7,  8,  9, 10, 11]],

        [[12, 13, 14, 15, 16, 17],
         [18, 19, 20, 21, 22, 23]]])
```

(2,2,6)代表的维度对应方括号从外到内。调用求和函数会沿某个轴降低张量的维度，使它变为一个标量。如使用`x.sum(axis=0)`，会降低最外层2这个维度，得到输出：

```python
>>>tensor([[12, 14, 16, 18, 20, 22],
        [24, 26, 28, 30, 32, 34]])
```

使用`x.sum(axis=1)`:

```python
>>> x.sum(axis=1)
tensor([[ 6,  8, 10, 12, 14, 16],
        [30, 32, 34, 36, 38, 40]])
>>> x.sum(axis=1).shape
torch.Size([2, 6])
```

使用`x.sum(axis=2)`，降低最里层6的维度:

```PYTHON
>>> x.sum(axis=2)
tensor([[ 15,  51],
        [ 87, 123]])
>>> x.sum(axis=2).shape
torch.Size([2, 2])
```

