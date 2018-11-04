---
title: Linux下的基础命令
categories: Linux
tags: 

---

## 目录操作命令
>首先要说明的是linux下一切皆文件，并且linux下并不以文件后缀区分文件类型。而我们所说了目录其实就是文件夹。
### ls
>语法：ls[选项][目录或文件]
>功能：对于目录，该命令列出该目录下的所有子目录与文件；对于文件，将列出文件名以及其他信息。
常用选项：

```linux
    -l  //列出文件的详细信息
    -a  //列出文件目录下的所有文件，包括以.开头的隐藏文件
    -d  //将目录像文件一样显示，而不是显示其下的文件(ls -d 指定目录)
    -i  //输出文件的i节点的索引信息(ls -ai 指定文件)
    -k  //以k字节的形式表示文件的大小
    -r  //对原先的排序进行逆序显示
    -t  //以时间排序
    -s  //在文件名后输出该文件的大小
    -S  //按文件大小排序
    -R  //列出所有子目录下的文件(递归)
    -1  //一行只输出一个文件
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/20181104143259710.png)
### pwd
>语法：pwd
>功能：显示用户当前所在的绝对路径

![在这里插入图片描述](https://img-blog.csdnimg.cn/2018110414334816.png)
### cd
>linux下的目录结构是一个树形结构，最上层的目录是根目录/

![在这里插入图片描述](https://img-blog.csdnimg.cn/20181104144231554.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQwNTUwMDE4,size_16,color_FFFFFF,t_70)
>语法：cd 目录名
>功能：改变当前目录，将当前目录改变到指定目录下

eg：

```linux
cd .. //返回上级目录
cd /home/waiting/workspace    //(绝对路径)
cd ../tools  //（相对路径）
cd ~   //进入用户的家目录
cd -    //返回最近访问的目录
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/20181104144023408.png)
### mkdir
>语法：mkdir [选项] dirname
>功能：在当前目录下创建一个名为“dirname”的目录

常用选项：

```linux
mkdir -p ./test/test2   //若创建的目录不存在，递归建立多个目录（从外向内）
```
### rmdir
>rmdir 和 mkdir相对应。
语法：rmdir [选项] dirname
功能：删除空目录
适用对象：具有当前目录操作权限的所有使用者

常用选项：

```linux
-p  //递归删除，从内往外递归删除空目录
```
### rm
>语法：rm [选项] dir/dirname
>功能：删除文件或目录
适用对象：所有使用者

常见选项：

```linux
rm -f   //忽略提示信息，强制删除（慎用，尤其是在root用户下！！！！！！）
   -r   //删除所有文件，包含目录型文件
   -i   //删除前逐一询问确认
```
### cp
>语法：cp [选项] 源文件目录 目标文件目录
功能：默认只能拷贝普通文件，拷贝指定文件到指定位置
说明：cp指令用于复制文件或目录，如果同时指定两个以上的目录，且最后一个是已存在的目录，则它会把前面所指定的所有文件或目录全部复制到此目录中。若同时指定多个目录，而最后一个目录是一个不存在的目录，则会提示错误信息。

常用选项

```linux
cp -r   //递归拷贝指定目录下的所有文件
cp  -f   //忽略提示信息，强行复制文件或目录
cp  -i    //复制有提示信息
```

### mv
>语法：mv [选项] 源文件目录 目标文件目录
>功能：移动指定文件到指定位置

常用选项:

```linux
mv -f   //忽略提示信息
   -i   //增加提示信息

```
## 文件操作命令
### touch
>语法：touch [选项] 文件
功能：若文件不存在则创建新文件，存在则刷新时间属性

常用选项:

```linux
 -r 以一个文件的时间属性来刷新另一个文件
 -t 以一个指定的时间来刷新文件的时间属性 （使用 man touch查看时间格式）

```
![在这里插入图片描述](https://img-blog.csdnimg.cn/2018110415132225.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQwNTUwMDE4,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20181104151509322.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQwNTUwMDE4,size_16,color_FFFFFF,t_70)
### cat
>语法：cat [选项] 文件
>功能：打印文件内容到终端显示

常用选项:

```linux
cat -n   //打印文件内容到显示终端并显示行号
```
### tac
>我们会发现tac刚好是cat反着的，它是按行逆序打印文件内容到显示终端。

### more
>more [选项] 文件
功能：对文件内容进行分页显示

常用选项：
```linux
-n     //对输出的所有行进行编号
-p    //退出more
```
### less
>less [选项] 文件
功能：对文件内容进行分页显示

>less和more的功能一样，但是我们用more对文件进行分页查看的时候不能向前翻页，只能向后看，而如果用了less之后，便可以使用Pgup和Pgdown向上向下看了，所有less的功能比more的功能更加的强大，一般情况下我们对文件内容进行分页显示的时候多用less。

常用选项：

```linux
f   空格   pgdown  //向下翻页
b   pgup               //向上翻页
上   下                  //按行走
q                          //退出
/string 向下匹配字符串
?string 向上匹配字符串
n 重复前一个搜索（/ OR ?）
```
### head
>语法：head [参数] 文件
功能：显示文件的前n行内容（默认10行）

常见选项：

```linux
-n(行数)    //行数输的几就显示前几行
```
### tail

>语法：tail [参数] 文件
功能：显示文件的末尾（默认10行）

常见选项：

```linux
-n （行数）    //行数输的几就显示末尾几行的内容到终端
-f                   //动态刷新显示文件末尾内容，常用于看日志
```
### 压缩

```linux
zip/unzip                // 按zip格式进行压缩/解压缩
eg:	zip a.zip a.txt   //将a.txt压缩，压缩后命名为a.zip
	unzip a.zip         //解压a.zip
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/20181104155602914.png)
```linux
gzip/gunzip       //按gzip格式进行压缩/解压缩
	gzip a.txt
	gunzip a.txt.gz
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/20181104155648819.png)
```linux
bzip2/bunzip2     // 按bzip2格式进行压缩/解压缩
	bzip2 a.txt
	bunzip2 a.txt.bz2
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/2018110415573553.png)
### tar打包

```linux
tar 文件打包
	-c 打包
	-x 解包
	-v 显示详细的打包/解包信息
	-f 指定包名，所以-f通常是最后一个选项
	-z 打包/解包同时以gzip格式  .tar.gz
	-j 打包/解包同时以bzip2格式 .tar.bz2

```
### 查找匹配操作
#### grep
>功能：grep   字符串匹配命令
```linux
grep  -i    //忽略大小写进行匹配
grep  -v  // 反向匹配（匹配到的行不显示，没有匹配到的显示）
-R         // 这个选项的目标对象是目录，对目录下的所有文件匹配
```

#### find 
>语法： find  目录  查找方式
```linux
   -name   按名称进行查找
   -type   按文件类型查找（-f  -d）
   -size   按文件大小查找（+/-n）
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/20181104160547977.png)
## 其他操作命令

```linux
ifconfig       //查看主机IP地址信息
date   //查看系统时间
man   //用于查看命令/函数手册
echo   //打印内容到显示终端上
su    // 切换当前用户（但是不切换当前所在路径）上一个用户在什么路径下，那么切换后还在这个路径下。
```
### 时间命令

```linux
//时间操作命令：
cal  // 显示linux下的日历
cal -3 // 显示三个月的日历
cal  -y  //显示一年的日历
cal  -j  //显示当前是一年中的第几天
bc   //计算器
>>  //输出重定向
date
-s   "2018-10-12  19:50:20" // 已制定的形式设置系统时间
date  +%s  //显示从1970年1月1日到0时0分0秒到当前秒经过的描述
date  +%F   //显示年月日
date  +%T   // 显示时间
date +'%Y %m %d %H %M %S'     //以规定的格式输出
```

