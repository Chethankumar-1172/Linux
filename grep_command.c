#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main(int a,char **b)  // command line arguments 
{
	if(a<3)
	{
		printf("usuage error : please enter ./a.out string or char filename.txt \n");
		return;
	}
	FILE *fp; // creating the file pointer 
	fp=fopen(b[2],"r");   // opening the file
	if(fp==0) 
	{
		printf("file not present\n");
		return;
	}
	printf("file present\n");

	int c=0,c1=0;
	char ch;
	while((ch=fgetc(fp))!=-1)
	{
		c++;
		if(ch=='\n')
		{
			if(c>c1)
			{
			  c1=c;
			  c=0;
			}
		}
	}
	rewind(fp);
	char*s=malloc(c1+1);  // allocating memory dynamically
	while(fgets(s,c1+1,fp))
	{
		if(strstr(s,b[1]))       // searching or locating the string
			printf("%s\n",s);
	}
}
