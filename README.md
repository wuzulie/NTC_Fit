# NTC_STM32F103
用拟合的方式计算温度，基于STM32F103

如果拟合除数很大，计算耗时会达到ms级别。如本程序中，用了30阶的拟合，F103计算一次耗时约7.71ms，F405计算一次约3.46ms。一次与查表方式相比，这种方法的优点是不费flash，查表方式甚至占用了几十kbyte的flash空间。而且查表方式优点就是，速度快，不占用太多CPU时间资源。当然，如果一般情况下，4阶拟合也已经很准确了，计算耗时也就10次乘法的时间，不会造成很大的CPU资源的占用。

程序里面的NTC器件型号是：NCP15WF104D03RC
