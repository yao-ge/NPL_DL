## pits in NPL

1. print 打印出来的数字和十六进制转换不同,添加do_egress_pkt_modify之后恢复正常
2. 不支持负数
3. &运算符只支持packet\bus fields, 不支持register
4. &运算结果需要用括号括起来，然后进行数值比较
5. value是一个关键字
