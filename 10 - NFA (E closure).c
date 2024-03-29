#include <stdio.h>
#define MAX_STATES 10
// Function to add an edge to the adjacency list
void addEdge(int adjList[][MAX_STATES], int src, int dest)
{
    adjList[src][dest] = 1;
}
// Function to compute e-closure for a given state
void computeEpsilonClosure(int state, int numStates, int adjList[][MAX_STATES], int visited[])
{
	int i;
    if (visited[state])
		return;
    printf("q%d ", state);
    visited[state] = 1;
    for (i = 0; i < numStates; i++)
	{
        if (adjList[state][i])
            computeEpsilonClosure(i, numStates, adjList, visited);
    }
}
int main()
{
    int numStates, numTransitions,i;
    printf("Enter the number of states: ");
    scanf("%d", &numStates);
    printf("Enter the number of transitions: ");
    scanf("%d", &numTransitions);
    int adjList[MAX_STATES][MAX_STATES] = {0};
    printf("Enter transitions in the format (source destination):\n");
    for (i = 0; i < numTransitions; i++)
	{
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(adjList, src, dest);
    }
    printf("Epsilon-Closure of States:\n");
    for (i = 0; i < numStates; i++)
	{
        printf("e-closure(q%d) = { ", i);
        int visited[MAX_STATES] = {0};
        computeEpsilonClosure(i, numStates, adjList, visited);
        printf("}\n");
    }
    return 0;
}
