#include<stdio.h>
int main()
{
int i,j,k,p[10],av[100],n,allo[100][100],need[100][100],max[100][100],r,f[10],c=0,co[10],h=0,sp[10][10],req;
printf("enter no.of process:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
p[i]=i;}
printf("enter no.of resources:");
scanf("%d",&r);
printf("enter max matrix");
for(i=0;i<n;i++)
{
for(j=0;j<r;j++)
{
scanf("%d",&max[i][j]);
}}
printf("enter allocated matrix:");
for(i=0;i<n;i++)
{
for(j=0;j<r;j++)
{
scanf("%d",&allo[i][j]);
}}
printf("enter available");
for(j=0;j<r;j++)
{
scanf("%d",&av[j]);
}
printf("enter process for special req:");
scanf("%d",&req);
printf("enter request\n");

for(j=0;j<r;j++)
{
scanf("%d",&sp[req][j]);
}

for(i=0;i<n;i++)
{
for(j=0;j<r;j++)
{
need[i][j]=max[i][j]-allo[i][j];
}}
for(j=0;j<r;j++)
{
if(sp[req][j]<=need[req][j] && sp[req][j]<=av[j])
{
c++;
}}
for(j=0;j<r;j++)
{
if(c==r)
{
/*need[req][j]=need[req][j]-sp[req][j];*/
av[j]=av[j]-sp[req][j];
allo[req][j]=allo[req][j]+sp[req][j];
}


}
for(i=0;i<n;i++)
{
for(j=0;j<r;j++)
{
need[i][j]=max[i][j]-allo[i][j];
}}
printf("need matrix");
for(i=0;i<n;i++)
{
for(j=0;j<r;j++)
{
printf("%d\t",need[i][j]);
}
printf("\n");}

for(i=0;i<n;i++)
{
f[i]=0;}

for(i=0;i<n;i++)
{
for(k=0;k<n;k++)
{
c=0;
if(f[k]==0)
{
for(j=0;j<r;j++)
{
if(need[k][j]<=av[j])
{
c++;

}}
if(c==r)
{
f[k]=1;
co[h]=k;
h++;

for(j=0;j<r;j++)
{
av[j]=allo[k][j]+av[j];
need[k][j]=0;
}}
}}}



if(h==n)
{

printf("the request can be granted\n");
printf("the safe sequence is:\n");

for(i=0;i<n;i++)
{
printf("p%d\t",co[i]);
}
}
else
{
printf("the request cannot be granted\n");
}
}




