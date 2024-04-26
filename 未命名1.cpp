
#include<stdio.h>
double findOneMiddle(int x[],int left,int right)//找出数组x的中位数
{
    double mid;
    int n = right - left + 1;
    if (n % 2 == 0)//数组x的个数为偶数
    {
        mid = (x[n / 2] + x[n / 2 - 1])*0.1 /2;
    }
    else//数组x的个数为奇数
    {
        mid = x[n / 2] * 0.1;
    }
    return mid;
}
int max(int a, int b)//返回max值
{
    if (a >= b) 
        return a;
    else 
        return b;
}
int min(int a, int b)//返回min值
{
    if (a >= b) 
        return b;
    else 
        return a;
}
double findmin(int x[], int y[], int xleft, int xright, int yleft, int yright)
{
    double xmid, ymid, mid;
    if (xright - xleft == 0)//如果每个数组只有一个元素
        return (x[xleft] + y[yleft])*0.1 / 2;
    xmid =findOneMiddle(x, xleft, xright);
    ymid =findOneMiddle(y, yleft, yright);
    if (xmid == ymid)
    {
        return xmid * 0.1;
    }
    //只有两个元素,也可以直接计算出两数组中位数
    if ((xright - xleft) == 1 && (xright - xleft) == 1)
    {
        return (max(x[xleft], y[yleft]) + min(x[xright], y[yright]))*1.0 / 2;
    }
    else if (xmid > ymid)//取x的左半部分，y的右半部分
    {
        if ((xright - xleft + 1) % 2 == 0)
        {
             mid = findmin(x, y,xleft, (xright - xleft) / 2+xleft,(yleft + yright) / 2 + 1, yright);
        }
        else
        {
             mid =
findmin(x, y, xleft, (xright - xleft) / 2+xleft, (yleft + yright) / 2 , yright);
        }
    }
    else if (xmid < ymid)//取y的左半部分，x的右半部分
    {
        if ((xright - xleft + 1) % 2 == 0)
        {
            mid =
findmin(x, y, (xleft + xright)/2+1, xright , yleft, (yleft + yright) / 2+yleft);
        }
        else
        {
             mid =
findmin(x, y, (xleft + xright)/2 , xright, yleft, (yleft + yright) / 2+yleft);
        }
    }
    return mid;
}
int main()
{
    int n=0, x[200],y[200], i;
    double mid;
   
    
	scanf( "%d", &n);
    
   
    for (i = 0; i < n;i++)
    {
        scanf("%d", &x[i]);
        
    }
    
   
    for (i = 0; i < n;i++)
    {
        scanf("%d", &y[i]);
        
    }
    
    mid = findmin(x,y, 0, n - 1, 0, n - 1);
    
    printf( "%.1lf\n", mid);
   
}


