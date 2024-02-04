# week 4

## Self-attention 

Vector Set as Input 

1. Find the relevant vectors in a sequence 

常见的计算方法：

![image-20230518230301189](.static/image-20230518230301189.png)

![image-20230518230939682](.static/image-20230518230939682.png)

利用$W^q\ W^k$计算关联性。

![image-20230518230912571](.static/image-20230518230912571.png)

![image-20230518231235134](.static/image-20230518231235134.png)

$v^i=W^va^i$ 引入v变量，累加获得b。对于每一个输出的b，和每个输入都有关系。



Multi-head Self-attention