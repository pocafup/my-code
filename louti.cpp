Mou~~

题目描述
牛棚里有 NN 头奶牛 (11≤NN≤20,00020,000)，它们对室内温度非常敏感。其中奶牛 ii 只能适应 A(i)A(i) 到 B(i)B(i) 这一区间的室温 (00≤A(i)A(i)≤B(i)B(i)≤1,000,000,0001,000,000,000)。管理员通过设定恒温器的温度来控制室温，显然管理员可以任意设定恒温器温度（温度值一定为整数）。如果管理员设定的室温 TT 小于 A(i)，奶牛 i 就会觉得冷，相应的产奶量就会变为 XX ；如果管理员设定的室温T正好在A(i)A(i)到B(i)B(i)这一区间，即A(i)A(i)≤TT≤B(i)B(i)。奶牛i就会觉得很舒适，相应的产奶量就会变为 YY；如果管理员设定的室温T大于 B(i)，奶牛ii就会觉得热，相应的产奶量就会变为 ZZ。当然，YY 一定大于XX和ZZ。 现在告诉你XX、YY 和 ZZ 的值以及每头奶牛能适应的室温区间，请帮助管理员设定好牛棚内的最佳室温以获得最大的产奶量。XX、YY 和 ZZ 都是范围在00到10001000之内的整数。

输入格式
第一行，四个用空格隔开的整数NN,XX,YY,ZZ；第二行到第N+1N+1行，每行两个用空格隔开的整数A(i)A(i)和B(i)B(i)。

输出格式
输出一个整数，表示设定好牛棚内的最佳室温后获得的最大的产奶量。

输入输出样例
输入 #1复制
4 7 9 6
5 8
3 4
13 20
7 10
输出 #1复制
31
