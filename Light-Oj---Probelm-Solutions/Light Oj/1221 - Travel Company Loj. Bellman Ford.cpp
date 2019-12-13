#include<bits/stdc++.h>
using namespace std;


int bellmanFord( vector< list< pair<int, int> > > adjacencyList,int vertices,int startVertex,vector<int> & shortestDistances)
{
    list< pair<int, int> >::iterator traverse;
    int i, j, k;

    // Initialisation
    for (i = 0; i <= vertices; ++i)
    {
        shortestDistances[i] = INT_MAX;
    }


    shortestDistances[startVertex] = 0;

    for (i = 0; i < vertices - 1; ++i)      // Runs 'vertices - 1' times = O(|V|)
    {
        for (j = 0; j < vertices; ++j)      // Runs as many times as the edges = O(|E|)
        {

            traverse = adjacencyList[j].begin();

            while (traverse != adjacencyList[j].end())
            {
                if (shortestDistances[j] == INT_MAX)
                {
                    // Important...!
                    //traverse = traverse->next;
                    ++traverse;
                    continue;
                }

                // Checking for Relaxation
                if ((*traverse).second + shortestDistances[j] < shortestDistances[(*traverse).first])
                {
                    // Relaxation
                    shortestDistances[(*traverse).first] = (*traverse).second + shortestDistances[j];
                }

                ++traverse;
            }
        }
    }


     // Checking for Negative Cycles
    for (j = 0; j < vertices; ++j)
    {
        traverse = adjacencyList[j].begin();

        while (traverse != adjacencyList[j].end())
        {
            // Checking for further relaxation
            if ((*traverse).second + shortestDistances[j] < shortestDistances[(*traverse).first])
            {
                // Negative Cycle found as further relaxation is possible
                return j;
            }

            ++traverse;
        }
    }


    return -1;
}


int main()
{
    int t,cs=0;
    cin >> t ;
    while(t--)
    {
        int vertices, edges, v1, v2, weight,P;

        cin >> vertices >> edges >>  P ;

        vector< list< pair<int, int> > > adjacencyList(edges+vertices + 1);

        for (int i = 1; i <= edges; ++i)
        {
            int expense , income ;
            cin >> v1 >> v2 >> income >>expense  ;
            weight = P*expense - income ;
            //     int weight1 = (ww[v1]-ww[v2])*(ww[v1]-ww[v2])*(ww[v1]-ww[v2]);
            adjacencyList[v1].push_back(make_pair(v2, weight));
            //     adjacencyList[v2].push_back(make_pair(v1, weight1));
        }


        bool flag = false ;
        for(int i=0;i<vertices;i++)
        {
            vector<int> shortestDistances(vertices+edges + 1);
            int ret = bellmanFord(adjacencyList, vertices, i, shortestDistances);
            if(ret!=-1){
                flag = true;
                cout << "YES" << endl ;
                break;
                }


        }
        if(!flag)
            cout << "NO" <<endl;


    }

    return 0;
}

