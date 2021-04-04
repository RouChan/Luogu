#include <stdio.h>
int a[100000000];//在主函数外定义全局变量数值上限高，自行修改到3、4亿也行，主函数里可定义不到这么大
int main()
{
	int n,i,k,v=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a[i]=i+1;
	}
	for(i=1;i<n;i++)
	{
		if(a[i]!=0)//晒过后的第一个非零值一定是素数
		{
			for(k=2;k*(i+1)<=n;k++)
			{
				a[k*(i+1)-1]=0;//将a[i]的整数倍筛掉
			}
			//printf("%d、",a[i]);打印太慢，这里屏蔽了
			v++;		
		}
	}
	printf("共%d个素数\n",v);
	return 0;
}
