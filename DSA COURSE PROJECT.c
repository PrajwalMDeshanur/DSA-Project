#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define size 48
struct place
{
    char name[20];
    int pop;
};
typedef struct place P;
/*P m[200]={{"Chadchan",18961},
           {"Dhulakhed",5966},
           {"Nibargi",6278},
           {"Zalaki",3277},
           {"Lachyan",5595},
           {"Bhatagunaki",5493},
           {"Indi",31485},
           {"Horti",10943},
           {"Salotgi",15823},
           {"Nimbal",4349},
           {"Kannur",12080},
           {"Atharga",12292},
           {"Tamba",13063},
           {"Balaganur",9034},
           {"Moratgi",7302},
           {"Agarkhed",6978},
           {"Kanamadi",8436},
           {"Arkeri",8148},
           {"Sindgi",37226},
           {"Honawad",10909},
           {"Tikota",14620},
           {"Vijapura",47387},
           {"Honnutagi",4795},
           {"Kamatagi",14380},
           {"Halagani",2819},
           {"Devara-Hippargi",16554},
           {"Kannolli",6507},
           {"Babaleshwar",22528},
           {"Managuli",15109},
           {"Ingaleshwar",10205},
           {"Kondguli",2856},
           {"Gundal",3420},
           {"Mamadapur",5873},
           {"Mulawad",7997},
           {"Basavana-Bagevadi",33198},
           {"Huvin-Hippargi",39789},
           {"Wadawadagi",4600},
           {"Tumbagi",3256},
           {"Kolhar",20213},
           {"Telgi",5200},
           {"Kaulgi",2586},
           {"Talikota",34217},
           {"Dhavalagi",3944},
           {"Nidagundi",15291},
           {"Chimmalgi",3907},
           {"Muddebihal",34217},
           {"Nalatawad",16043},
           {"Tangadagi",3858}};*/
struct graph
{
    int u;
    int v;
    float w;
};
typedef struct graph GH;
/*GH g[200]={{1,2,13},
           {1,3,6},
           {1,4,10},
           {3,8,11},
           {8,4,9.5},
           {8,11,8.3},
           {8,10,4},
           {5,6,4.5},
           {4,6,11},
           {6,7,3.4},
           {7,9,5},
           {7,10,9},
           {10,12,9.5},
           {10,13,12},
           {12,13,7},
           {12,25,11},
           {13,14,9.8},
           {14,15,18},
           {14,19,9.5},
           {19,27,7},
           {27,26,6.2},
           {26,27,8},
           {25,24,4},
           {24,23,9},
           {23,22,1.5},
           {18,21,6},
           {21,17,6},
           {21,20,4},
           {17,20,5},
           {28,32,7},
           {32,33,3.2},
           {33,34,4},
           {28,29,6.7},
           {34,29,3},
           {28,34,6},
           {34,35,7},
           {30,35,1.8},
           {30,31,4.6},
           {31,37,2.9},
           {37,38,1.4},
           {37,36,5},
           {36,35,4},
           {30,36,4},
           {35,40,6},
           {34,40,4.9},
           {40,41,1},
           {41,45,4},
           {40,44,4.5},
           {35,43,6.7},
           {36,43,5},
           {44,43,4},
           {43,46,3.8},
           {44,48,8},
           {46,48,5},
           {46,47,5},
           {43,42,6},
           {5,16,5.7},
           {20,28,8.5},
           {24,29,9.3},
           {11,18,6},
           {18,22,4},
           {26,31,10.8}};*/
//int arr[52]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52};

int sort(GH g[size])
{
    struct graph temp;
    for(int i=0;i<=size-2;i++)
    {
        for(int j=0;j<=size-i-2;j++)
        {
            if(g[j].w > g[j+1].w)
            {
                temp=g[j];
                g[j]=g[j+1];
                g[j+1]=temp;
            }
        }
    }
}
void display(GH  p[100])
{

    for(int i=0;i<size;i++)
    {
        printf("\n%d %d %.2f \n",p[i].u,p[i].v,p[i].w);
    }
}


void display_pop()
{
       FILE *fp;
          P  m[100];
          fp=fopen("details.txt","r");
     for(int i=0;i<48;i++)
     {
          fscanf(fp,"%s %d",m[i].name,&m[i].pop);
          //printf("%s  %d",m[i].name,m[i].pop);
          //printf("\n");
     }
    for(int i=0;i<size;i++)
    {
        printf("\n%s %d \n",m[i].name,m[i].pop);
    }
}

int find(int arr[52],int n,int u,int v)
{
    if(arr[u]==arr[v])
        return 1;
    else
    {
       return 0;
    }
}

void un(int arr[52],int n,int u,int v)
{
    int temp=arr[u];
    int i;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==temp)
        {
            arr[i]=arr[v];
        }
    }
}
void krushkal()
{

    printf("OUTPUT\n");
          FILE *fp;
          GH  p[100];
          fp=fopen("pajju.txt","r");
     for(int i=0;i<48;i++)
     {
          fscanf(fp,"%d %d %f",&p[i].u,&p[i].v,&p[i].w);
          // printf("%d  %d  %.2f",p[i].u,p[i].v,p[i].w);
          //rintf("\n");
     }

    float sum=0;
    int n=52;
    sort(p);
    display(p);
            FILE *fp1;
            int arr[100];
          fp=fopen("array.txt","r");
     for(int i=0;i<48;i++)
     {
          fscanf(fp,"%d",&arr[i]);
          // printf("%d  %d  %.2f",p[i].u,p[i].v,p[i].w);
          //rintf("\n");
     }

    for(int i=0;i<size;i++)
    {
        int u=p[i].u;
        int v=p[i].v;
        int z=find(arr,n,u,v);
        if(z==0)
        {
            printf("\n%d %d\n",u,v);
            sum=sum+p[i].w;
            un(arr,n,u,v);
        }
        else
        {
            printf("\nDiscard\n");
        }
    }
    printf("Value is %.2f",sum);
    fclose(fp);
    fclose(fp1);
}

void population()
{
   int i;
   int j;
   int v;
   int k;
   P z;
     FILE *fp;
          P  m[100];
          fp=fopen("details.txt","r");
     for(int i=0;i<48;i++)
     {
          fscanf(fp,"%s %d",m[i].name,&m[i].pop);
          printf("%s  %d",m[i].name,m[i].pop);
          printf("\n");
     }
    printf("Output\n");
   int temp=0;

   for(i=0;i<size;i++)
   {
       j=i-1;
       v=m[i].pop;
       z=m[i];
       while(j>=0 && m[j].pop>v)
       {
           m[j+1]=m[j];
           j=j-1;
       }
        m[j+1]=z;
   }


    for(int i=0;i<size;i++)
    {
        printf("\n%s %d \n",m[i].name,m[i].pop);
    }
    fclose(fp);
}

int sort_weight()
{
           GH temp;
         FILE *fp;
          GH  p[100];
          fp=fopen("pajju.txt","r");
     for(int i=0;i<size;i++)
     {
          fscanf(fp,"%d %d %f",&p[i].u,&p[i].v,&p[i].w);
          printf("%d  %d  %f",p[i].u,p[i].v,p[i].w);
          printf("\n");
     }
   for(int i=0;i<=size-2;i++)
    {
        for(int j=0;j<=size-i-2;j++)
        {
            if(p[j].w > p[j+1].w)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    fclose(fp);
      for(int i=0;i<size;i++)
    {
        printf("\n%d %d %.2f \n",p[i].u,p[i].v,p[i].w);
    }
}
void sort_name()
{
  char temp[200];
  int c;
  int i;
  int j;
        FILE *fp;
          P  m[100];
          fp=fopen("details.txt","r");
     for(int i=0;i<48;i++)
     {
          fscanf(fp,"%s %d",m[i].name,&m[i].pop);
          printf("%s  %d",m[i].name,m[i].pop);
          printf("\n");
     }
     fclose(fp);
  for(i=0;i<size;i++){
   for(j=i+1;j<size;j++)

{
      if(strcmp(m[i].name,m[j].name)>0){
         strcpy(temp,m[i].name);
          c=m[i].pop;
         strcpy(m[i].name,m[j].name);
         m[i].pop=m[j].pop;
         strcpy(m[j].name,temp);
         m[j].pop=c;
      }
   }
}
 for(int i=0;i<size;i++)
    {
        printf("\n%s  %d\n",m[i].name,m[i].pop);
    }

}


int main()
{

    int  graph[10][10];
    int words[20][20];

         FILE *fp;
          GH  p[100];
          fp=fopen("pajju.txt","r");
          for(int i=0;i<48;i++)
         {
          fscanf(fp,"%d %d %f",&p[i].u,&p[i].v,&p[i].w);

          }
          fclose(fp);
    int choice;
    while(1)
    {
        printf("\n\t MENU \t\n");
        printf("1 - Find the Minimum spanning tree and the total weight\n");
        printf("2 - Sort the names of the villages and towns based on population\n");
        printf("3 -Display the matrix of graph\n");
        printf("4 -Display the the village information\n");
        printf("5 -Display sorted matix based on weight of graph\n");
        printf("6 -Sort based on name of villages\n");
        printf("\nEnter your choice= ");
        scanf("%d",&choice);
        switch(choice)
        {
             case 1:krushkal();
            break;
            case 2:population();
            break;
           case 3:
                  display(p);
            break;
           case 4:display_pop();
            break;
            case 5:sort_weight();
            break;
            default:exit(0);
            case 6:sort_name();
            break;
        }
    }
    return 0;
}
