CPS
===
![image](https://github.com/mengtianwxs/cps/blob/master/images/preview.png)

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
        @15-1  42AB2CN     4*2*100*10+2*100*10
        @16-1  42ABC2NPE   4*2*100*10+2*100*10+80*8


        /////计算分支排
        @17  -pai*m        -100*10*12  //p: 100*10 m:12 p代表排的规格，m代表数量
        @18  -price      -1000
        @19  -price*m    -800*10
        @20  -pai*ms*ts -100*10*12*6 m代表米数，ts代表台数
        @21  -- 重复上一次的价格
        @22  -s4*4  上一段4台计算结果的值*4 段相加*次数


`hotkey`
        you can use tab key to lose focus first

        - again write **
        b clear **
        c sum **
        enter calc **
        w clear and write data to guige lineedit
        r reset
        ctrl+e setFoucs this
        p pop method
        g segment sum
        Y fb1 size
        U fb2 size
        I fb3 size
        D set danjia
        1 600 num
        2 800 num
        3 1000 num
        4 1200 num
        5 400 num
        6 fb1 num
        7 fb2 num
        8 fb3 num





