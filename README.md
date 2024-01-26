# data-structure-and-algorithem
mainly used to store the code of this course's task(oj),including the description of the question and the code

## oj1 丢失的练习册
**（时间限制: 1000 ms  内存限制: 1800 KB）**

问题描述

开学了，阳光小学准备给每个学生发放三本练习册。为了方便发放，每本练习册上都印上了学生的学号。然而，运输过程中由于道路的颠簸，原本捆绑整齐的练习册散落一地，司机师傅再将练习册堆叠在一起时，学号已经完全打乱。更糟糕的是，当他清点练习册总数时，发现少了一本，为了尽快弄清楚丢失的是印有哪位学生学号的练习册，司机师傅只好拿出本子，一个个记录每个练习册上的学号。聪明的你能够通过编程的方法找到是印有哪个同学学号的练习册丢失了吗？

输入格式

第1行为学生的总数：N；

第2到第3N行为司机师傅记录的练习册上的学号；

注意：没有丢失练习册的学号会出现3次，而丢失练习册的学号只会出现2次。

输出格式

丢失练习册上对应的学号

输入样例
>3\
2021001\
2021001\
2023002\
2023003\
2023002\
2023003\
2023002\
2021001

输出样例
>2023003

提示
1. 取值范围

N的取值范围为[1, $1×10{^6}$ ]的整数；

学生学号的取值范围为[0, $2×10{^9}$ ]的整数；
 
2. 测试样例
   
1~3测试样例N< $1×10{^4}$;

4~5测试样例 $1×10{^4}$ <=N<= $5×10{^5}$ ；

6~10测试样例 $5×10{^5}$ <N<= $1×10{^6}$ ；
 
3. 时间和空间

本道OJ本身并不难，但对程序运行的时间和空间有较为严格的要求，时间需要为O(n)，空间为O(1)才能通过所有的测试样例，请同学们从算法效率的角度出发，选择合适的算法。

## **oj2 军训排队**
**（时间限制: 1000 ms   内存限制: 2000 KB）**

问题描述

军训时需要将所有同学(包括教官)排成一队，一开始只有教官(编号为1)排在第一个，之后教官会发出如下三种命令：
 
1 x y   编号为y的同学入队，排在编号为x的同学的后面，若要排在队首，则用0表示x

2 x     编号为x的同学报告其后面的同学编号，若要报告队首同学的编号，则用0表示x，若x在队尾，则报告0

3 x     编号为x的同学出队
 
要求对于每次命令2，都输出报告同学后面同学的编号，并最后从头到尾输出队列中同学的编号。

 ![oj2](resource1/oj2.png)
 
输入格式

第一行为一个正整数N，表示总共有几条命令

接下来N行中，每行表示一个命令；每行命令中，数字之间用空格隔开

输出格式

对于每次命令2，都输出一个编号，用换行隔开

最后从头到尾输出队列，用换行隔开

输入样例

>// 例如上图中的命令对应以下输入\
7\
1 1 2\
1 1 3\
2 3\
1 2 4\
3 1\
1 0 5\
2 4

输出样例
>// 例如上图中的命令会产生以下输出\
2\
0\
5\
3\
2\
4

提示
1. 同学编号为小于100000的正整数
2. 命令的条数N为小于200000的正整数
3. 队列中没有人时不会出现命令2和命令3

## **oj3 比武**
**（时间限制: 1000 ms   内存限制: 5000 KB）**\
问题描述\
N个士兵站成一列，每个士兵都有一个武力值。对于队伍中任意两个士兵X和Y，如果他们在队伍中相邻，或者他们之间没有士兵的武力值严格大于X和Y的武力值中的较小值，那么他们需要进行一次比武。请计算总共需要进行几次比武。\
输入格式\
第一行：一个整数N，代表士兵的总数\
第2到第N+1行：每行是一个整数，表示队伍中从头至尾每个士兵的武力值\
输出格式\
一个整数，表示比武的次数\
输入样例\
输入样例1：
>8\
2\
7\
1\
6\
5\
3\
4\
2

输入样例2：
>5\
4\
2\
2\
2\
5

输出样例\
输出样例1：
>9

输出样例2：
>10

提示\
请使用scanf/printf实现输入/输出\
比武的次数可能很大，超过int的范围\
不同士兵的武力值可能相等\
可能用到的结论：对于任意士兵Z，排在Z前面且武力值比Z小的士兵不会和排在Z后面的士兵比武
 
对于全部的测试点，保证1<=每个士兵的武力值<2^31\
1-2测试样例：N<= $1×10{^3}$\
3-4测试样例： $1×10{^3}$  <N<= $1×10{^4}$\
5-10测试样例：  $1×10{^4}$  <N<= $5×10{^5}$

## **oj4 缺损二叉树**
**（时间限制: 1000 ms   内存限制: 1000 KB）**\
问题描述\
输入给定一系列缺损点，将一棵无限深度的满二叉树进行重新编号，编号方式为从1开始逐行从左至右顺序编号，缺损点得到编号后，其子树被删去，后续编号中该子树的结点跳过不编号，编号后的树被称为“缺损二叉树”。例如下图为缺损点为{5，6，9}的缺损二叉树的一部分（下方可无限延长），红色数字标注了缺损点，其下方灰色子树被删去。对于输入给定的目标编号，输出缺损二叉树上根节点到目标结点的路径，该路径用经过的所有结点的编号表示。下图中，蓝色表示根结点到目标结点15的路径，路径用途径结点编号{1,3,7,10,15}表示。\
![oj4](resource1/oj4.png)
输入格式\
第一行为两个整数N和M，N表示缺损点数目，M表示目标点的数目。\
第二行为N个缺损点的编号，按从小到大顺序排列。\
第三行为M个目标点的编号，按从小到大顺序排列。\
下方给出的输入样例表示缺损点为{5,6,9}，目标点为{3,9,15,22}。\
输出格式\
每一行输出根节点到一个目标点的最短路径，路径用途径节点编号表示。\
如果该路径不存在，则输出0。\
共输出M行。\
输入样例
>3 4\
5 6 9\
3 9 15 22

输出样例
>1 3 \
1 2 4 9 \
1 3 7 10 15 \
1 3 7 10 14 22

提示\
题目假定缺损点及目标点数目不超过100个，目标节点编号均小于 $2{^{32}}$。
 
对本题，可以根据题目要求逐行构造该缺损二叉树。对于当前行，记录所有非缺损点，在下一行依次构造子节点，并排除缺损点，直到构造到目标节点为止。利用构造节点时记录的父亲节点编号，可以从目标节点搜索到回到根节点的路径，将该路径翻转，即可得到所求路径。\
上述方法在目标节点编号过大时会占用过多内存，事实上，若某棵子树或树中的某连续部分不存在缺损点，可以不必将其每个节点均储存在内存中。你可以自行设计省略表示方法以满足性能要求。
 
## **oj5 信息传递**
**（时间限制: 1000 ms   内存限制: 6000 KB）**\
问题描述\
某组织在执行任务时需要进行信息传递，为保证信息传递的安全性，每个节点只能向特定的某些节点发送消息，已知有N个节点，初始信息由0号节点开始发送，现在系统的设计师需要确认所设计的连接方式能否使得所有节点最终都收到0号节点发送的消息。为了保证系统的鲁棒性，系统设计师还需要考虑若有信道损坏是否会影响信息的传递。具体来说，给定M条可能毁坏的信道，需要依次考虑只有一条信道被毁坏时是否所有节点仍能收到0号节点发送的信息。下面是一幅与输入输出样例对应的示意图，绿色节点能收到0号节点发送的信息，橙色节点则无法收到。\
![oj5](resource1/oj5.png)
输入格式\
输入共N+M+1行\
第一行为两个正整数，第一个正整数N表示节点总数，第二个正整数M表示可能被破坏的信道数\
接下来的N行依次给出从0号节点到N-1号节点能发送消息的节点；每行第一个数n表示该节点能传递消息的节点个数，后面n个数表示能传递消息的节点编号，同一行的数之间用空格分隔。\
接下来的M行对应M个可能毁坏的信道，每行两个数i j，用空格分隔，表示从节点i到节点j的信道毁坏。

输出格式\
输出为M+1行，每行一个正整数，第一行对应原始情况，后面M行依次对应M条信道毁坏后的情况。若对应情况下所有节点都能收到0号节点发送的消息，则输出1，反之输出0。

输入样例
>4 2\
2 1 2\
2 2 3\
0\
1 0\
0 1\
0 2

输出样例
>1\
0\
1

提示
1. 测试样例情况：

    1-4测试样例：N< $2{^{10}}$，M=0

    5-7测试样例：N< $2{^{16}}$，M=0

    8-10测试样例：N< $2{^{16}}$，M< $2{^{16}}$

    对于所有测试样例，边数E< $2{^{20}}$

2. 图中无自环、重边

## **oj6 跳跳乐**
**（时间限制: 2000 ms   内存限制: 1500 KB）**\
问题描述\
有一系列相邻的台阶，每级台阶具有不同的高度，台阶间的水平距离相等，如图所示
![oj6](resource1/oj6.png)
有一只青蛙在不同台阶之间跳跃，设青蛙可以跳跃的最长水平距离为K个台阶，最大的垂直距离为H（需要注意的是，为简化问题，垂直距离只需考虑跳跃起点和终点的高度差，不需要考虑途中经过的台阶高度和起点的高度差），以上图为例，若K=5，H=2，则青蛙可以从当前位置跳跃到编号为{0, 3, 6}的三个台阶，因为这三个台阶与当前台阶的水平距离均不大于5，且垂直距离的绝对值分别为{2, 1, 1}，均不大于2。\
现在总共有M个连续台阶，并给定每个台阶的高度，试求青蛙一共可能在多少对台阶间跳跃？\
输入格式\
输入为两行\
第一行为三个整数，分别为台阶数量M，青蛙可以跳跃的最长水平距离K，可以跳跃的最大垂直距离H\
第二行为M个整数，依次为各个台阶的高度\
输出格式\
输出为一个整数，为青蛙可以跳跃的台阶对数\
输入样例
>9 5 2\
6 8 5 7 4 3 9 2 10

输出样例
>14\
// 可跳跃的台阶对编号分别为(0, 1), (0, 2), (0, 3), (0, 4), (1, 3), (1, 6), (2, 3), (2, 4), (2, 5), (3, 6), (4, 5), (4, 7), (5, 7), (6, 8)

提示\
输入数据范围：\
M< $2{^{31}}$, K< $2{^{31}}$, H< $2{^{31}}$， 每级台阶的高度也小于 $2{^{31}}$\
相邻两个台阶间的水平距离均相等且值为1，任意两个台阶的高度均不相等
 
## **oj7 带限矩阵方程组求解**
**（时间限制: 1000 ms   内存限制: 1500 KB）**\
![oj7](resource1/oj7.png)
输出格式\
输出共m行，每行为n个浮点数，分别为矩阵X的每一列的各个元素值，每个元素值结果四舍五入保留4位小数。\
输入样例
>3\
3 2\
44 62 \
44 43 30 \
3 34 \
27 63 53 \
14 52 19

输出样例
>-0.9846 1.5983 -0.0447 \
0.7073 -0.3892 1.0744

提示\
计算带限矩阵LU分解后元素间的递推表达式。

## **oj8 缺失数据恢复**
**（时间限制: 1000 ms   内存限制: 1024 KB）**\
问题描述\
一个系统的n个输入输出对为：（x1, y1）（x2, y2）, ... （xn, yn）(n≥2)，其中xi, yi均为实数。该系统的输出值被输入值所唯一确定，即xi=xj时必有yi=yj。现在小明想根据已知的n个输入输出对，计算出通过这n个点的最小阶次的多项式函数，并利用该函数计算给定的m个系统输入值所对应的系统输出值。请你帮助他完成该程序的设计。\
输入格式\
输入共n+m+3行：\
第一行包含一个整数 n（2 ≤ n ≤ 100），表示提供的输入输出对数目。\
第二行包含一个整数 m（1 ≤ m ≤1200000），表示待估计数据点的数量。\
第 3到n+2 行共n行，每行包含两个实数 xi 和 yi，分别表示一个已知的系统输入和输出值。\
第 n+3到n+m+2 行共m行，每行包含一个实数 x，表示其中一个给定的新系统输入值。\
输出格式\
输出共m+1行：\
第一行输出一个整数r，为通过给定n个点的最小阶次多项式函数的阶数\
第2行到第m+1行共m行，每行输出1个实数，依次为估计出的多项式函数 f 在第i个感兴趣系统输入x'i上的取值f(x'i)，输出误差要求控制在 $1×10{^{-6}}$之内。\
输入样例
>3\
1\
1 1\
2 4\
3 9\
1.5

输出样例
>2\
2.25

提示
1. 给定的n个系统输入输出可能有重复情况
2. 考虑到浮点数精度问题，在本题中，两个浮点数差的绝对值小于等于 $1×10{^{-6}}$ 时可视为为同一个值。

## **oj9 小明的火车旅行计划**
**（时间限制: 1000 ms   内存限制: 20000 KB）**\
问题描述\
小明计划乘坐火车去远方的城市旅游。铁路系统可以被抽象为一个有向图，其中每个节点代表一个城市的火车站，边表示不同城市之间的火车线路。每条边都有两个权重，分别表示乘坐该线路所需的时间和费用。小明需要在一定的时间之内到达目的地，并且希望尽量减少花费。请问，你能帮助小明计算在满足时间要求的情况下，到达目的地所需的最低费用是多少吗？\
![oj9](resource1/oj9.png)
输入格式\
输入共M+2行\
第1行：图的节点数、边数（N，M）\
第2到M+1行：代表N条路径的信息，每行包括4个整数，分别代表路线起点、路线终点、路线时间、路线价格（其中时间和价格为正整数）\
第M+2行：包括3个整数，分别代表小明的起点、目的地、路线最大时间限制

输出格式\
一个整数，代表满足时间条件的路线中价格最小路线的价格。如果没有符合要求的路线，请输出-1。

输入样例
>4 5\
0 1 1 1\
0 2 4 2\
1 2 1 5\
1 3 4 2\
2 3 1 1\
0 3 4

输出样例
>7

提示\
图节点数 N < $2{^{16}}$\
图边数 M < $2{^{20}}$\
每条边对应的时间和费用 < $2{^{16}}$，但最终的输出可能大于这个数

## **oj10 张量相乘的最小开销问题**
**（时间限制: 3000 ms   内存限制: 80000 KB）**\
问题描述\
张量（tensor）乘法和广播（broadcasting）是一种在张量之间进行运算的方法，它可以用来表示一些复杂的数学和物理问题，例如神经网络，图像处理，信号处理等。为了理解张量乘法和广播，我们首先需要了解什么是张量，以及它的形状和维度。\
张量（tensor）是一种可以表示多维数组的数据结构，它可以有任意的维度和形状。维度（dimension）是张量的层次，表示张量有多少个方向或轴（axis）。形状（shape）是一个表示每个维度大小的整数元组，表示张量在每个方向上有多少个元素。例如，一个标量（scalar）是一个零维张量，它只有一个数值，没有方向，也没有形状；一个向量（vector）是一个一维张量，它有一个方向，也就是一个轴，它的形状是一个单元素的元组，表示它在这个方向上有多少个元素；一个矩阵（matrix）是一个二维张量，它有两个方向，也就是两个轴，它的形状是一个双元素的元组，表示它在这两个方向上分别有多少个元素；一个立方体（cube）是一个三维张量，它有三个方向，也就是三个轴，它的形状是一个三元素的元组，表示它在这三个方向上分别有多少个元素，以此类推。我们可以用以下的图示来表示不同维度的张量：
![oj10-1](resource1/oj10-1.png)\
其中0维张量可用一个可表示为标量，1维张量可表示为向量，2维张量可表示为矩阵，更高维的张量可视为由低维张量作为元素构成的向量、矩阵等：\
如3维张量可表示为![oj10-2](resource1/oj10-2.png)。\
在张量之间进行运算时，我们需要考虑它们的形状是否匹配，以及是否需要进行广播（broadcasting）。广播是一种在支持张量的框架中，如Numpy和Pytorch，为了应对形状不同的张量进行运算所执行的操作。广播的目的是将两个不同形状的张量变成两个形状相同的张量，即先对小的张量添加轴（使其维度与较大的张量相同），再把较小的张量沿着新轴重复（使其形状与较大的相同）。例如，如果我们想要对一个形状为（2，3）的矩阵和一个形状为（3）的向量进行加法，我们可以先给向量添加一个轴，使其形状变为（1，3），然后再沿着新轴复制两份，使其形状变为（2，3），最后再与矩阵逐元素相加，得到一个形状为（2，3）的矩阵。我们可以用以下的过程来表示（注意，并非任意两个张量都能够进行广播，需要形状满足特定条件，后两段具体说明）：
![oj10-3](resource1/oj10-3.png)\
更具体而言，广播（broadcasting）是一种在支持张量的框架中，如Numpy[1] 和Pytorch[2] ，为了应对形状不同但满足某些特定条件（下一段具体说明）的张量进行运算所执行的操作。广播的目的是将两个不同形状的张量变成两个形状相同的张量，即先对小的张量添加轴（使其维度与较大的张量相同），再把较小的张量沿着新轴重复（使其形状与较大的相同）。广播兼容的张量可以进行加法，乘法等运算，运算结果的形状是两个张量形状的较大者。\
广播的原则是：如果两个张量的后缘维度（trailing dimension，即从末尾开始算起的维度）的轴长度相符，或其中的一方的长度为1，则认为它们是广播兼容的。广播会在缺失和（或）长度为1的维度上进行。例如，一个形状为（3，2，2，2）的4维张量A和一个形状为（1，1，2，2）的4维张量B是广播兼容的，它们相乘的过程如下所示，先将B在第一维方向上复制3份，第二维方向上复制2份，这样它的形状和A相同，之后进行逐元素乘。\
![oj10-4](resource1/oj10-4.png)\
结合上述张量乘法和广播机制，以及标准的线性代数中的矩阵乘法，我们考虑如下的运算：计算X1*X2*...*Xn，每个Xi代表一个K维张量。有以下说明：\
1.它们的维度数K一样，且大于等于2。例如都是三维张量或都是四维张量。\
2.将每一个K维张量看成由矩阵（2维张量) 作为元素构成的K-2维张量。前K-2维按照上述的张量乘法和广播进行运算，最后2维按照标准矩阵乘法进行运算。例如\
![oj10-5](resource1/oj10-5.png)\
3.为满足最后两维按照标准矩阵乘法，相邻两个张量的后两维必须满足矩阵乘法的要求，即X(i)的最后一维大小必须等于X(i+1)的倒数第二维大小。\
4.为满足张量乘法和广播机制的要求，对前K-2维中任意第k维，任何张量Xi在该维度的大小只能是两个取值中的一个：1或Dk。Dk为一大于1的正整数，对于不同维度k，k'，对应的Dk，Dk'可不同。前K-2维中按照可广播的逐元素乘。即相邻两个张量Xi,X(i+1)相乘时，对于任意维度k: 1≤k≤K-2，如果Xi第k维大小等于X(i+1)第k维大小, 则在该维度上逐元素相乘；如果Xi第k维大小不等于X(i+1)第k维大小，即其中一个等于1，另一个等于Dk，则进行广播并逐元素乘（将该维度等于1的张量在该维度上复制Dk份后，与另一张量在该维度上逐元素乘）。\
5.定义计算开销为需要进行的标量乘法的次数。求给定n个张量依次相乘的计算开销最小的“完全括号”方案（结合律顺序）的开销。
 
求：计算开销最小的“完全括号”方案（结合律顺序）的开销。
 
参考资料：
[1] <https://numpy.org/>\
[2] <https://pytorch.org/>

更多参考资料：
<https://zhuanlan.zhihu.com/p/499189580>\
<https://pytorch.org/docs/stable/generated/torch.bmm.html>
 
例子\
三个三维张量X1×X2×X3，维度大小为：X1=[1,1,2], X2=[1,2,3], X3=[10,3,4], 共有两种方案：\
方案1:（X1×X2）×X3, 计算复杂度=1×(1×2×3)+10×(1×3×4)=126\
方案2:  X1×(X2×X3), =10×(2×3×4)+10×(1×2×4)=320\
方案1优于方案2，应输出126

输入格式\
第一行输入两个整数n，K，代表共有n个张量相乘，每个张量都是K维。接下来n行中，每行代表一个张量，有K个由空格分隔的整数，第k个整数代表该张量第k维的大小。\
输出格式\
计算输入的n个张量依次相乘的计算开销最小的“完全括号”方案（结合律顺序）的开销，输出这一整数值。\
输入样例
>3 3\
1 1 2\
1 2 3\
10 3 4

输出样例
>126

提示\
数据范围n<2048，K<32，每个维度的大小<1000。\
本题限制主要在于时间复杂度。
