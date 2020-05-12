
format long

vol_mv = [
76.37 
106.62 
146.86 
199.44 
266.84 
351.43 
455.18 
579.27 
723.72 
887.07 
1066.27 
1256.86 
1453.38 
1650.00 
1841.29 
2022.47 
2190.12 
2342.02 
2477.57 
2596.56 
2699.96 
2788.98 
2864.98 
2929.82 
2984.64 
3031.05 
3070.31 
3103.34 
3131.41 
3155.06 
3175.09 
3192.11 
3206.50 
3218.82 
      ];
  
temp = [  
-40
-35
-30
-25
-20
-15
-10
-5
0
5
10
15
20
25
30
35
40
45
50
55
60
65
70
75
80
85
90
95
100
105
110
115
120
125
] ;            

temp_buf  = temp;

%拟合的阶数
orderSum = 30;

y1=polyfit(vol_mv,temp_buf,orderSum);
vol_mv_buf=70:1:3250;
temp=polyval(y1,vol_mv_buf);


%拟合irms=f(fg)
plot(vol_mv_buf,temp,'-');
hold on

%标出用来拟合的点
plot(vol_mv,temp_buf,'*');
hold on

%生成“nihe_c”源文件
nihe_c = fopen('.\Nihe\nihe.c','w');
    fprintf(nihe_c,'#include "nihe.h"\n');
    fprintf(nihe_c,'#include "math.h"\n\n');
    
    fprintf(nihe_c,'void nihe(double vol , double* tem )\n{\n');
    fprintf(nihe_c,'\t*tem = 0;\n');
    for i= 1:orderSum-1
           fprintf(nihe_c,'\t*tem +=  FACTOR_%d  * pow(vol, %d);\n',i,orderSum+1-i);             
    end
   fprintf(nihe_h,'\t*tem +=  FACTOR_%d * vol;\n',orderSum);
   fprintf(nihe_h,'\t*tem +=  FACTOR_%d;\n',orderSum + 1);
   
    fprintf(nihe_c,'\n}\n');

fclose(nihe_c);

%生成“nihe_h”头文件
nihe_h = fopen('.\Nihe\nihe.h','w');
    fprintf(nihe_h,'#ifndef __NIHE_H\n#define __NIHE_H\n\n');
    fprintf(nihe_h,'extern void nihe(double vol , double* tem );\n\n');

    for i= 1:orderSum+1
           fprintf(nihe_h,'#define FACTOR_%d  %5.400f\n',i,y1(i));
    end
    fprintf(nihe_h,'\n#endif\n');

fclose(nihe_h);

%计算一些点，用于验证
sss0=polyval(y1,1453.38)
sss3=polyval(y1,1650.00)


