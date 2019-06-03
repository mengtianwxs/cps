CPS
///////////////////////////////////////////
///////////////////////////////////////////
<br/>
<img src="https://github.com/mengtianwxs/cps/blob/master/images/preview.png" height=200/>

<br/>


计算低压柜，高压柜水平排的价格，可以累加计算。包括高压柜主排，地排，低压柜主排，零排，地排和分支排。操作类型分为如下情况 :
////计算主排
@1   ABC        100*10
@2   2ABC       2*100*10

@3   ABCN       100*10+100*10
@4   ABC2N      100*10+2*100*10
@5   2ABCN      2*100*10+100*10
@6   2ABC2N     2*100*10+2*100*10

@7   ABCNPE     100*10+100*10+80*8
@8   ABCN2PE    100*10+100*10+2*80*8
@9   ABC2NPE    100*10+2*100*10+80*8
@10  ABC2N2PE   100*10+2*100*10+2*80*8

@11  2ABCNPE    2*100*10+100*10+80*8
@12  2ABCN2PE   2*100*10+100*10+2*80*8
@13  2ABC2NPE   2*100*10+2*100*10+80*8
@14  2ABC2N2PE  2*100*10+2*100*10+2*80*8

@15  4ABCN      4*100*10
@16  4ABCPE     4*100*10+80*8


/////计算分支排
@17  -pai*m        -100*10*12  //p: 100*10 m:12 p代表排的规格，m代表数量
@18  -price      -1000
@19  -price*m    -800*10
@20  -price*ms*ts -100*10*12*6 m代表米数，ts代表台数

@21 size*sl@TYPE 700*10@100*10+100*10+80*8  非标模式

hotkey

- again write **
b clear **
c sum **
enter calc **
w clear and write data to guige lineedit
r reset
ctrl+e setFoucs this
p pop method



