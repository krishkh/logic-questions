#include <stdio.h>
#include <stdlib.h>

void printArr(int* arr, int arrSize){
    for(int i = 0; i < arrSize; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printGraph(int** graph, int graphSize, int* graphColSize){
    for(int i = 0; i < graphSize; i++){
        int colSize = graphColSize[i];
        printf("colSize is %d\n",colSize);
        printf("%d -> ", i);
        for(int j = 0; j < colSize; j++){
            printf("%d, ", graph[i][j]);
        }
        printf("\n");
    }
}
int notIn(int* arr,int arrSize, int target){
    for(int i = 0; i < arrSize; i++){
        if(target == arr[i]){
            return 0;
        }
    }
    return 1;
}
int safeNode(int node, int** graph, int* graphColSize, int* state) {
    if (state[node]>0){
        return state[node] == 2;
    }
    state[node] = 1;
    for (int i = 0; i < graphColSize[node]; i++){
        int neighbor = graph[node][i];
        if (!safeNode(neighbor, graph,graphColSize, state)){
            return 0;
        }
    }
    state[node] = 2; // marking it down as safe at this point
    return 1;    
}


int* eventualSafeNodes(int** graph, int graphSize, int* graphColSize, int* returnSize) {
    int* returnArray = NULL;
    int returnCount = 0;
    int* state = (int*)calloc(graphSize, sizeof(int));
    for(int i = 0; i < graphSize; i++){
        // if graph col Size is less than one, it means that it is a terminating node, so it must be added
        if (graphColSize[i] < 1 && notIn(returnArray, returnCount, i)){
            returnCount++;
            returnArray = (int*)realloc(returnArray,sizeof(int)*returnCount);
            returnArray[returnCount-1] = i;
        }
        // iterate over all the cols to check if they are safe nodes
        if(safeNode(i, graph,graphColSize, state) && notIn(returnArray, returnCount, i)){
            returnCount++;
            returnArray = (int*)realloc(returnArray,sizeof(int)*returnCount);
            returnArray[returnCount-1] = i;
        }
    }

    *returnSize = returnCount;
    printArr(returnArray, returnCount);
    printf("return count is: %d\n", returnCount);
    return returnArray;
}

int main(){
    int graphSize = 5;
    int** graph = (int**)malloc(sizeof(int*)*graphSize);
    int graphColSize[5] = {0,4,1,1,0};
    int tempGraph[5][4] = {{},{0,2,3,4},{3},{4},{}};
    for(int i = 0; i < graphSize; i++){
        int* tempArr =  tempGraph[i];
        graph[i] = tempArr;
    }
    printArr(graphColSize, graphSize);
    printGraph(graph, graphSize, graphColSize);

    
    int* returnSize = malloc(sizeof(int));
    int* returnArr = eventualSafeNodes(graph, graphSize, graphColSize, returnSize);
    printf("return size is: %d\n", *returnSize);
    printArr(returnArr,*returnSize);
    return 0;
}