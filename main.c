#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int i,j,k,a,b,v,u,n=10,m,s,d,ne=1,x,l,size,tem;
int visited[9],minimum_dist=0,cost[15][15],mat[15][15],sa[9];
float cpkb=1.5,cpkc=9.5,cost_bus,cost_cab, avgspd_bus=30, avgspd_cab=60;
char place[30], source[30], destination[30];
char name[50][50],names[11][30] = {"", "Baga_beach", "Aguada_fort","Basillica_of_bom_jesus","Cruise","Dona_paula_view_point","Mangeshi_temple","Colva_beach","Sunset_point","Salaulim_dam","Dudhsagar_falls"};
int min(int a, int b)
{
    return ((a<b)?a:b);
}
int floyd(int cost[15][15], int n, int s, int d)
{
    int i, j, k, mindist=0;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                {
                 cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
                }
     /*printf("The all pair shortest path is :\n");
    for(i=1;i<=n;i++)
    {
    for(j=1;j<=m;j++)
    {
        printf("%d\t",cost[i][j]);
    }
    printf("\n");
    }*/
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(i==s&&j==d)
        {
         mindist=cost[s][d];
         printf("The minimum distance traveled from %s to %s is %d kms",names[s],names[d],mindist);
        }
    }
    return mindist;
}
int prims(int mat[15][15],int size)
{
    int i, j, a, u, b, v, visited[9], ne=1, min, mindist=0;
    for(i=2;i<=size;i++)
    visited[i]=0;
    printf("\nThe shortest path to travel is:\n\n");
    printf("------------------------------------\n");
    visited[1]=1;
    while(ne<size)
        {
            for (i=1,min=999;i<=size;i++)
                {
                    for (j=1;j<=size;j++)
                        {
                            if(mat[i][j]<min)
                                {
                                    if(visited[i]==1)
                                        {
                                            min=mat[i][j];
                                            a=u=i;
                                            b=v=j;
                                        }
                                }
                        }
                }
            if(visited[u]==0||visited[v]==0)
                {
                    //printf("%d] Place(%s,%s)=%d\n",ne++,names[a],names[b],min);
                    printf("%d] %s -> %s = %d kms\n",ne++,name[a],name[b],min);
                    mindist+=min;
                    visited[b]=1;
                }
            mat[a][b]=mat[b][a]=999;
        }
    printf("\n\nThe minimum distance to travel all the places is %d kms\n",mindist);
    return mindist;
}
void calc_time(int mindist, float sbus, float scab)
    {
        float etab, etac;
        int hourb, minb, secb, hourc, minc, secc, sb, sc;
        etab = mindist/sbus;
        etac = mindist/scab;
        sb=etab*3600;
        hourb=(sb/3600);
        minb=(sb-(3600*hourb))/60;
        secb=(sb-(3600*hourb)-(minb*60));
        sc=etac*3600;
        hourc=(sc/3600);
        minc=(sc-(3600*hourc))/60;
        secc=(sc-(3600*hourc)-(minc*60));
        printf("\nEstimated Time of Arrival for Bus : %dhrs %dmin %dsec",hourb,minb,secb);
        printf("\nEstimated Time of Arrival for Cab : %dhrs %dmin %dsec",hourc,minc,secc);
    }
void main()
{
    char choice,menu;
    printf("Enter the place you want to travel!\n");
    scanf("\n%s",&menu);
    if(menu=='goa'||'Goa'||'GOA')
    {
     cost[1][1]=0;cost[1][2]=10;cost[1][3]=25;cost[1][4]=999;cost[1][5]=999;
     cost[1][6]=999;cost[1][7]=999;cost[1][8]=999;cost[1][9]=999;cost[1][10]=999;
     cost[2][1]=10;cost[2][2]=0;cost[2][3]=24;cost[2][4]=999;cost[2][5]=999;
     cost[2][6]=999;cost[2][7]=999;cost[2][8]=999;cost[2][9]=999;cost[2][10]=999;
     cost[3][1]=25;cost[3][2]=24;cost[3][3]=0;cost[3][4]=12;cost[3][5]=999;
     cost[3][6]=11;cost[3][7]=999;cost[3][8]=999;cost[3][9]=999;cost[3][10]=999;
     cost[4][1]=999;cost[4][2]=999;cost[4][3]=12;cost[4][4]=0;cost[4][5]=6;
     cost[4][6]=23;cost[4][7]=999;cost[4][8]=999;cost[4][9]=999;cost[4][10]=999;
     cost[5][1]=999;cost[5][2]=999;cost[5][3]=999;cost[5][4]=6;cost[5][5]=0;
     cost[5][6]=999;cost[5][7]=33;cost[5][8]=999;cost[5][9]=999;cost[5][10]=999;
     cost[6][1]=999;cost[6][2]=999;cost[6][3]=11;cost[6][4]=23;cost[6][5]=999;
     cost[6][6]=0;cost[6][7]=30;cost[6][8]=999;cost[6][9]=52;cost[6][10]=51;
     cost[7][1]=999;cost[7][2]=999;cost[7][3]=999;cost[7][4]=999;cost[7][5]=33;
     cost[7][6]=30;cost[7][7]=0;cost[7][8]=50;cost[7][9]=34;cost[7][10]=999;
     cost[8][1]=999;cost[8][2]=999;cost[8][3]=999;cost[8][4]=999;cost[8][5]=999;
     cost[8][6]=999;cost[8][7]=50;cost[8][8]=0;cost[8][9]=53;cost[8][10]=999;
     cost[9][1]=999;cost[9][2]=999;cost[9][3]=999;cost[9][4]=999;cost[9][5]=999;
     cost[9][6]=52;cost[9][7]=34;cost[9][8]=53;cost[9][9]=0;cost[9][10]=42;
     cost[10][1]=999;cost[10][2]=999;cost[10][3]=999;cost[10][4]=999;cost[10][5]=999;
     cost[10][6]=51;cost[10][7]=999;cost[10][8]=999;cost[10][9]=42;cost[10][10]=0;
        printf(" 1.Baga beach\n 2.Aguada fort\n 3.Basillica of bom jesus\n 4.Cruise\n 5.Dona paula view point\n 6.Mangeshi temple\n 7.Colva beach\n 8.Sunset point \n 9.Salaulim dam\n 10.Dudhsagar falls\n\n");
    }
    char so[30],des[30];
    int temp1;
    printf("Enter your choice\na. To travel between two places\nb. To travel all places\n");
    scanf("%s",&choice);
    if(choice=='a')
        printf("");
    else if(choice=='b')
        printf("");
    else
        {
            printf("You have entered an invalid option\nPlease try again\n");
            exit(0);
        }

    /*printf("Enter the number of places that you want to make a network on\n");
    scanf("%d",&n);
    printf("Enter any %d places\n",n);
    for(x=1;x<=n;x++)
    {
        printf("Enter the %dth place : ",x);
        scanf("%s",place);
        strcpy(names[x],place);
    }*/
    /*printf("Famous places are:\n");
    for(x=1;x<=n;x++)
    {
        printf("%d)%s\n",x,names[x]);
    }
    printf("\n");*/
    m=n;
    /*printf("\nEnter the distances between each places(if no route, then enter 0)\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(i==j)
            {
                cost[i][j]=0;
            }
            else if(i>j)
            {
                cost[i][j]=cost[j][i];
            }
            else if(i<j)
            {
                printf("Enter the distance from %s to %s ",names[i],names[j]);
                scanf("%d",&cost[i][j]);
                if(cost[i][j]==0)
                cost[i][j]=999;
            }
        }
    }
    /*printf("The Cost Matrix will be :\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            printf(" %d ",cost[i][j]);
            printf("\t");
        }
    printf("\n");
    }*/
    switch(choice)
    {
        case 'a' :  printf("Enter the Source place (fill the space with '_')\n");
                    //scanf("%d",&s);
                    scanf("%s",so);
                    for(i=1;i<=n;i++)
                    {
                        temp1=strcmp(names[i], so);
                        if(temp1==0)
                        {
                            s=i;
                            break;
                        }
                    }
                    printf("Source = %s\n",names[s]);
                    printf("Enter the Destination place\n");
                    //scanf("%d",&d);
                    scanf("%s",des);
                    for(i=1;i<=n;i++)
                    {
                        temp1=strcmp(names[i], des);
                        if(temp1==0)
                        {
                            d=i;
                            break;
                        }
                    }
                    printf("Destination = %s\n",names[d]);
                    minimum_dist=floyd(cost,n,s,d);
                    cost_bus=cpkb*minimum_dist;
                    cost_cab=cpkc*minimum_dist;
                    printf("\nThe minimum cost to travel from %s to %s in bus will be %f rs",names[s],names[d],cost_bus);
                    printf("\nThe minimum cost to travel from %s to %s in cab will be %f rs\n",names[s],names[d],cost_cab);
                    calc_time(minimum_dist,avgspd_bus,avgspd_cab);
                    break;
        case 'b' :  k=1;
                    printf("Enter the number of places that you want select(fill the space with '_')\n");
                    scanf("%d",&size);
                    printf("enter the places u want to select\n");
                    for(i=1;i<=size;i++)
                    {
                        scanf("%s",place);
                        strcpy(name[i],place);
                    }
                    for(i=1;i<=n;i++){
                        for(j=1;j<=size;j++){
                            temp1=strcmp(names[i], name[j]);
                            if(temp1==0){
                                sa[k]=i;
                                k++;
                            }
                        }
                    }
                    for(i=1;i<=size;i++)
                    {
                        l=1;
                        tem=sa[i];
                        for(j=1;j<=size;j++)
                        {
                            mat[i][j]=cost[tem][sa[l]];
                            l++;
                        }
                    }

                    printf("Considering %s as the source\n",name[1]);
                    minimum_dist=prims(mat,size);
                    cost_bus=cpkb*minimum_dist;
                    cost_cab=cpkc*minimum_dist;
                    printf("The minimum cost to travel in bus is %f rs",cost_bus);
                    printf("\nThe minimum cost to travel in cab is %f rs",cost_cab);
                    calc_time(minimum_dist, avgspd_bus,avgspd_cab);
                    break;
        default   : printf("Enter the correct choice next time\n");
                    exit(0);
    }
}



