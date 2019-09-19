# Data Mining

[TOC]



## weka

 [%%%](https://www.cnblogs.com/hxsyl/p/3307343.html)



## What is noise

random error or variance in a measured variable

一定量的noise, 太多处理不了了

真实性, 缺失数据, not applicable, 有一些不适用的数据, 不同的类别;

缺失的类别: 完全随机缺失( 每一个人确实可能性一样 ), 还有和自身属性的缺失.

### 处理方法

自己填, 猜.

ignore, 对于$2\%$ 



## 特征选择 feature selection

有些属性是不需要的.

属性最好是能完美分开, 但是一般都有覆盖的. 但是知道了这个属性之后, 可以更精确地判断这个东西的类型.

### Entropy

衡量一个系统不确定值的.

![1553650482088](C:\Users\Kai\AppData\Roaming\Typora\typora-user-images\1553650482088.png)

这个的熵就是最高的, 不确定性最大

### 算熵的实例:

![1553650637570](C:\Users\Kai\AppData\Roaming\Typora\typora-user-images\1553650637570.png)

$Gain(S, X)$ 是信息增益, 原来 ( 上上图 ) 熵是 1. 也就是这个不确定性下降的幅度. 叫做 $information\,gain$



## Feature Subset Search

用于: 怎么找到最优的 几个 属性, 能最好地区分这几个东西, 组合爆炸如果所有都测试的话.

### 分治定界: Branch and Bound

![1553651152004](C:\Users\Kai\AppData\Roaming\Typora\typora-user-images\1553651152004.png)

**注意下面那个单调性的假设**, 那个树其实就是去除一个属性, 然后生成的结点, 注意J的那个不等式是用来剪枝的.

这个方法是可以找到一个最优解的.



### 其他找 subset 的方法

![1553651215896](C:\Users\Kai\AppData\Roaming\Typora\typora-user-images\1553651215896.png)

#### 优化:

![1553651252021](C:\Users\Kai\AppData\Roaming\Typora\typora-user-images\1553651252021.png)



## Feature Extraction

图像边缘检测: 不同属性做一个线性组合, 用差分的方法.

老鹰 从 3 维 压缩到 2 维, 有技巧, 不同的压缩会有不同的结果, 投影的方向决定结果, 就是信息的损失是不同的.

variance 就是 information. 如果 variance 分得比较开, 就是这个属性越重要, 就是黎老师说的要选一个分布最开的方向.

![1553660222471](C:\Users\Kai\AppData\Roaming\Typora\typora-user-images\1553660222471.png)

**高斯的例子 ↑**



首先做去中心, 做坐标变化: 

![1553660282099](C:\Users\Kai\AppData\Roaming\Typora\typora-user-images\1553660282099.png)



### **如何做这个变换?**:

所有坐标做一个旋转, $Y = PX​$ 乘一个旋转矩阵.

注意:

![1553660579380](C:\Users\Kai\AppData\Roaming\Typora\typora-user-images\1553660579380.png)
$$
S(Y)=\frac{1}{n-1} Y Y^{T}
$$

$$
\begin{aligned} Y Y^{T} &=(P X)(P X)^{T} \\ &=P X X^{T} P^{T} \end{aligned}
$$

$$
\begin{aligned}(n-1) S(Y) &=P X X^{T} P^{T} \\ &=P Q D Q^{T} P^{T} \\ &=(P Q) D(P Q)^{T} \end{aligned}
$$

![1553660748098](C:\Users\Kai\AppData\Roaming\Typora\typora-user-images\1553660748098.png)

最后一个式子乘出来必须是对角阵, 所以 $PQ = E$ 单位阵.



### 高维空间投影到一条线上

希望投影前投影后距离差距最小.

#### A Different View

目标函数 $J(e)$ 最小化, 也就是原始的点和投影后的点 距离最小, 就是使投影过后, 每一个点都尽量变化小一点.

$\alpha _{k} $ 长度的向量 $e$ .  注意这里数学推导: 矩阵: $e^t x_k = \alpha_{k}$ 

定义散点矩阵:   $S=\sum_{i=1}^{n} x_{k} x_{k}^{t}$

![1553675268697](C:\Users\Kai\AppData\Roaming\Typora\typora-user-images\1553675268697.png)

所以就是找这个方向 向量 $e$ 是那个红圈的最大.

优化问题...

然后就是上 拉格朗日乘数法!!!

**最后变成优化最大的特征值: 这里就是老师讲的东西了**

![1553675612624](C:\Users\Kai\AppData\Roaming\Typora\typora-user-images\1553675612624.png)

----------

### MATLAB 实例

PCA 的 挑大的特征值: 1.8 然后向特征向量上投影:

![1553675733482](C:\Users\Kai\AppData\Roaming\Typora\typora-user-images\1553675733482.png)



**数据越不分散, 信息丢失的越多**



## 线性判别分析

PCA 不考虑label, 不考虑分类, 本来很好分开的可能投影完了之后分不开了.

有标签的数据用LDA, 

如何让数据分开, 需要有东西来控制它, 把他们分开.

坐标轴旋转, 就是做线性组合, **和PCA相似的点, 都是有坐标的旋转, 做线性组合**

#### Fisher判别准则: (来衡量它分开的程度): $J=\frac{\left|\mu_{1}-\mu_{2}\right|^{2}}{S_{1}^{2}+S_{2}^{2}}$

![1553676380012](C:\Users\Kai\AppData\Roaming\Typora\typora-user-images\1553676380012.png)

下面是每一个类的散度, 越小越好, 上面是分开的程度 越大越好.

表达成投影方向的一个函数, 这样才能去优化它, 找到它的最优点.



$\overline{\mu}$ 是投影过后的那个东西, 就是$w^{T} x$ 









## 主成分分析法$_{Principal \,\,component \,\,analysis}$

如何去找到给定数据, 在某一投影方向下找到数据差异, **投影之后方差最大**

规范化长度, 然后求内积, 就是投影了. 投影到一个向量上面.

方差做成它自己的平方, 方差取逆展开之后就是协方差矩阵

想让方差最大, 其实就是解优化式子, 但是要保证$w^T w = 1$ 带约束的优化, 用拉格朗日乘子法

The Matrix Cookbook 看矩阵如何做拉格朗日, 

![img](file:///E:\QQ消息记录\645064582\Image\C2C\927B95AF704BA462A43F2054924249B1.jpg)

然后就是解特征值, 做一次特征值分解, 然后找第二个, 这时候就要强制 $w_2 w = 0$ , 每一个特征值对应一个特征向量, 按照特征值大小排序, 找前 k 个就可以了, 他们本身就是正交的.

求解 $w$ 最大特征值对应特征向量, 就是答案了.



### 损失

降维之后信息损失要很少, 有些点可能会变成一样的, cluster到一起去了, 所以在降维之后恢复不能完全恢复. 压缩过的信息损失不超过 $5\%​$ .

PPT里有PCA具体操作, 先中心化, 求协方差, 求特征值, 排序拿最大, 得到了新空间中 d 维的坐标

### 应用

降维, 人脸识别, 先紧致化, 压缩数据是服务于后续挖掘算法.

所有像素点排成一行, 用PCA降维一下, 在低维的空间算距离算一些其他东西. 用Eigen face 加权求和 用来识别这个脸是不是你的脸( 这只是PCA很古老的做法 )

**PCA其实就是找到空间中最广的延展方向**

### 流形学习

#### Isometric feature mapping (ISOMAP)

前期都是降维的思路.



## Histogram

希望里面的数字多, 注意这里怎么算法variance.

自己评估自己方法的时候, 要用分层采样的方法.

## 离散化

连续属性 还要给他 离散化.

记录下每一个划分所有的信息.

数据用来: 描述型 用简单的方式说明数据长什么样子. 用一些特定含义的东西.

​		预测型...























