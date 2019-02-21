# 大创

[TOC]

## PDB调试

使用 pdb 进行调试
pdb 是 python 自带的一个包，为 python 程序提供了一种交互的源代码调试功能，主要特性包括设置断点、单步调试、进入函数调试、查看当前代码、查看栈片段、动态改变变量的值等。pdb 提供了一些常用的调试命令

![1550738578553](C:\Users\Kai\AppData\Roaming\Typora\typora-user-images\1550738578553.png)

## `subprocess.Popen `

```python
subprocess.Popen(args, bufsize=0, executable=None, stdin=None, stdout=None, stderr=None, preexec_fn=None, close_fds=False, shell=False, cwd=None, env=None, universal_newlines=False, startupinfo=None, creationflags=0)
```


> **参数args** `可以是字符串或者序列类型（如：list，元组），用于指定进程的可执行文件及其参数。如果是序列类型，第一个元素通常是可执行文件的路 径。我们也可以显式的使用executeable参数来指定可执行文件的路径。在windows操作系统上，Popen通过调用 CreateProcess()来创建子进程,CreateProcess接收一个字符串参数，如果args是序列类型，系统将会通过 list2cmdline()函数将序列类型转换为字符串。`

> **参数bufsize**：`指定缓冲`

> 参数executable: `用于指定可执行程序。一般情况下我们通过args参数来设置所要运行的程序。如果将参数shell设为 True，executable将指定程序使用的shell。在windows平台下，默认的shell由COMSPEC环境变量来指定。`

> 参数stdin, stdout, stderr `分别表示程序的标准输入、输出、错误句柄。他们可以是PIPE，文件描述符或文件对象，也可以设置为None，表示从父进程继承。`

> 参数preexec_fn `只在Unix平台下有效，用于指定一个可执行对象（callable object），它将在子进程运行之前被调用。`

> 参数Close_sfs： `在windows平台下，如果close_fds被设置为True，则新创建的子进程将不会继承父进程的输入、输出、错误管 道。我们不能将close_fds设置为True同时重定向子进程的标准输入、输出与错误(stdin, stdout, stderr)。`

> 参数shell `设为true，程序将通过shell来执行。`

> 参数cwd `用于设置子进程的当前目录。`

> 参数env `字典类型，用于指定子进程的环境变量。如果env = None，子进程的环境变量将从父进程中继承。`

> 参数Universal_newlines: `不同操作系统下，文本的换行符是不一样的。如：windows下用’/r/n’表示换，而Linux下用 ‘/n’。如果将此参数设置为True，Python统一把这些换行符当作’/n’来处理。`

> 参数startupinfo与createionflags `只在windows下用效，它们将被传递给底层的CreateProcess()函数，用 于设置子进程的一些属性，如：主窗口的外观，进程的优先级等等。`

**有用到的: **

> 参数cwd `用于设置子进程的当前目录。`

> 参数shell `设为true，程序将通过shell来执行。`

>**subprocess.PIPE**
>在创建Popen对象时，subprocess.PIPE可以初始化stdin, stdout或stderr参数。**表示与子进程通信的标准流。**

## `p.communicate()`

使用 `subprocess` 模块的 `Popen` 调用外部程序，如果 `stdout` 或 `stderr` 参数是 pipe，并且程序输出超过操作系统的 pipe size时，如果使用 `Popen.wait()` 方式等待程序结束获取返回值，会[导致死锁](http://docs.python.org/release/2.7.3/library/subprocess.html#subprocess.Popen.wait)，程序卡在 `wait()` 调用上。

官方文档里推荐使用` Popen.communicate()`。这个方法会把输出放在内存，而不是管道里，所以这时候上限就和内存大小有关了，一般不会有问题。而且如果要获得程序返回值，可以在调用 `Popen.communicate() `之后取` Popen.returncode` 的值。

结论：如果使用 `subprocess.Popen`，就不使用 `Popen.wait()`，而使用` Popen.communicate() `来等待外部程序执行结束。

`Popen. communicate`(*input=None*)[¶](http://docs.python.org/2/library/subprocess.html#subprocess.Popen.communicate)

## profile 文件只读

`sudo chmod 700 /etc/profile`

## JAVA_HOME environment variable is not set.

JAVA_HOME 第一行是之前的, 第二行是更改的

![1550745564669](C:\Users\Kai\AppData\Roaming\Typora\typora-user-images\1550745564669.png)

下面是 蜜汁 dollar 大写错误..... /xk /xk /xk

![1550746072768](C:\Users\Kai\AppData\Roaming\Typora\typora-user-images\1550746072768.png)



各种目录找到疯了...

`/usr/lib/jvm/java-8-openjdk-amd64/jre`

`/usr/lib/jvm`

`sudo vi /root/.bashrc`

`sudo vim /etc/profile`

## sudo: source：找不到命令

切换到root用户, 用 `sudo su` 解决

`sudo su`环境用的是目标用户(root)的环境

`sudo -s `环境用的是当前用户本身的环境

![1550750110507](C:\Users\Kai\AppData\Roaming\Typora\typora-user-images\1550750110507.png)

## 查找文件

`which` 查看可执行文件的位置,从全局环境变量PATH里面查找对应的路径,默认是找 bash内所规范的目录

`whereis `查看文件的位置,配合参数-b，用于程序名的搜索，从`linux`数据库查找。

`locate` 配合数据库查看文件位置。

```
find -name april*                     在当前目录下查找以april开始的文件
find -name april* fprint file        在当前目录下查找以april开始的文件，并把结果输出到file中
find -name ap* -o -name may*   查找以ap或may开头的文件
find /mnt -name tom.txt   -ftype vfat   在/mnt下查找名称为tom.txt且文件系统类型为vfat的文件
find /mnt -name t.txt ! -ftype vfat   在/mnt下查找名称为tom.txt且文件系统类型不为vfat的文件
find /tmp -name wa* -type l            在/tmp下查找名为wa开头且类型为符号链接的文件
find /home -mtime   -2                 在/home下查最近两天内改动过的文件
find /home -atime -1                  查1天之内被存取过的文件
find /home -mmin    +60                  在/home下查60分钟前改动过的文件
find /home -amin   +30                  查最近30分钟前被存取过的文件
find /home -newer   tmp.txt             在/home下查更新时间比tmp.txt近的文件或目录
find /home -anewer   tmp.txt            在/home下查存取时间比tmp.txt近的文件或目录
```