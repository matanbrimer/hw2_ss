#include <stdio.h>
#include"my_mat.h"

#define V 10
int visited[V] = {0};
#include <stdlib.h>

int main(){

    int t = 1, from = 0, to = 0;
    char choose =' ';
    while(t){

        

        scanf("%c", &choose);

        switch(choose){

            case 'A':
                enteringValues();
                initialize();
                break;
            
            case 'B':
                scanf("%d",&from);
                scanf("%d",&to);
                for (int i = 0; i < V; i++)
                {
                    visited[i] = 0;
                }
                
                if(routeExistence(from,to))printf("True\n");
                else printf("False\n");
                break;
            
            case 'C':
                FloydWarshall();
                foundShortPath();
                break;
            
            case 'D':
                t = 0;
                break;
        }

    }

   return 0;
}