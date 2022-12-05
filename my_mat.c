#include"my_mat.h"
#include<stdio.h>
#define V 10
#define INFINITY 11111
int mat[V][V]={0};
int shortPath[V][V]={0};

void enteringValues(){

    for (int i = 0; i < V; i++)
    {
        for (int y = 0; y < V; y++)
        {
           scanf("%d", &mat[i][y]);
        }
        
    }

}

void initialize()
{

    for (int i = 0; i < V; i++)
    {
        for (int y = 0; y < V; y++)
        {
            if(i == y){
                shortPath[i][y] = mat[i][y];
            }
            else{
                shortPath[i][y]= (mat[i][y])?mat[i][y]:INFINITY;
            }
        }
        
    }
}

void FloydWarshall(){

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int y = 0; y < V; y++)
            {
                
                if(shortPath[i][k] !=0  && shortPath[k][y] !=0 ){

                    if( shortPath[i][y] > shortPath[i][k] + shortPath[k][y] ){
                    
                        shortPath[i][y] = shortPath[i][k] + shortPath[k][y];

                    }
                
                }
            }
            
        }
        
        
    }
}

int routeExistence(int from,int to){
    if(from == to){
        return 0;
    }
    if(mat[from][to]){
        return 1;
    }

    for (int i = 0; i < V; i++)
    {
      if(mat[from][i] && !visited[i])
      {
            visited[i]=1;
            if (routeExistence(i,to))
            {
                return 1;
            }
            
      } 
    }
    return 0;

  
}
void foundShortPath(){
   int l=0,u=0;
    scanf("%d",&l);
    scanf("%d",&u);
    if( shortPath[l][u] != 0 && shortPath[l][u] != INFINITY) printf("%d\n", shortPath[l][u]);
    else printf("-1\n");


}
