#include <stdio.h>
#pragma warning(disable:4996)
typedef struct edge {
    unsigned short end;
    unsigned short necessity;
};
int hash[65536];
edge edges[1048576];
unsigned short visited[65536];
unsigned short DFS(unsigned short node) 
{
    if (visited[node] >= 1) return 0;
    visited[node] = 1;
    for (int i =hash[node] ; i <hash[node+1]; i++) 
    {
        unsigned short p = edges[i].end;
        edges[i].necessity=DFS(p);
    }
     return 1;
}
unsigned short DFS1(unsigned short node,unsigned short damaged_i,unsigned short damaged_j)
{
    if (visited[node] >= 1) return 0;
    visited[node] = 1;
    if (node == damaged_i)
    {
        for (int i = hash[node]; i < hash[node+1]; i++)
        {
            if (edges[i].end == damaged_j)
            {
                continue;
            }
            DFS1(edges[i].end, damaged_i, damaged_j);
        }
    }
    else
    {
        for (int i = hash[node]; i < hash[node + 1]; i++)
        {
            unsigned short p = edges[i].end;
            DFS1(p, damaged_i, damaged_j);
        }
    }
    return 1;
}
int main() {
    int N, M;
    unsigned short flag = 0;
    scanf("%d %d", &N, &M);
    int mr = 0;
    for (int i = 0; i < N; i++) {
        int number=0;
        scanf("%d", &number);
        for (int j = 0; j <number; j++)
        {
            int me = j + hash[i];
            scanf("%hu", &edges[me].end);
            mr = me;
            edges[me].necessity = 0;
        }
        hash[i + 1] = mr+1; 
    }
    DFS(0);
    for (int i = 1; i < N; i++)
    {
        if (visited[i] == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        for (int i = 0; i < M+1; i++)
        {
            printf("%d\n", 0);
        }
    }
    else 
    {
       printf("%d\n", 1);
       for (int i = 0; i < M; i++)
       {
          int damaged_i, damaged_j;
           scanf("%d", &damaged_i);
           scanf("%d", &damaged_j);
           for (int j =hash[damaged_i]; j < hash[damaged_i+1]; j++)
           {
               if (edges[j].end == damaged_j)
               {
                   if (edges[j].necessity == 1)
                   {
                       unsigned flag1 = 0;
                       for (int i = 0; i < N; i++)
                       {
                           visited[i] = 0;
                       }
                       DFS1(0, damaged_i, damaged_j);
                       for (int i =1; i < N; i++)
                       {
                           if (visited[i] == 0)
                           { 
                               flag1=1;
                               break;
                           }
                       }
                       if (flag1 == 0)
                       {
                           printf("%d\n", 1);
                       }
                       else
                       {
                           printf("%d\n", 0);
                       }
                   }
                   else
                   {
                       printf("%d\n", 1);
                   }
               }
           }
       }
    }
    return 0;
}
