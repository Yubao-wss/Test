#include <stdio.h>
#include <stdlib.h>

int main()
{
	struct s1
	{
		char c1;
		int i;
		char c2;
	};
	printf("%d\n", sizeof(struct s1));//结果为12
	struct s2
	{
		char c1;
		char c2;
		int i;
	};
	printf("%d\n", sizeof(struct s2));//结果为8
	struct s3
	{
		double d;
		char c;
		int i;
	};
	printf("%d\n", sizeof(struct s3));//结果为16
	struct s4
	{
		char c1;
		struct s3 S3;
		double d;
	};
	printf("%d\n", sizeof(struct s4));//结果为32
	struct s5
	{
		char c;
		char f[3];
	};
	printf("%d\n", sizeof(struct s5));//结果为4
	system("pause");
	return 0;
}
