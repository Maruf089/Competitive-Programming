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

    for (i = 1; i <= vertices - 1; ++i)      // Runs 'vertices - 1' times = O(|V|)
    {
        for (j = 1; j <= vertices; ++j)      // Runs as many times as the edges = O(|E|)
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

    return -1;
}


int main()
{
    int t,cs=0;
    cin >> t ;
    while(t--)
    {
        int vertices, edges, v1, v2, weight;

        scanf("%d", &vertices);
         vector<int>ww;
        ww.push_back(0);
        for(int i=0; i<vertices; i++)
        {
            int a ;
            cin >> a ;
            ww.push_back(a);
        }

        scanf("%d", &edges);

        vector< list< pair<int, int> > > adjacencyList(edges+vertices + 1);

        for (int i = 1; i <= edges; ++i)
        {
            scanf("%d%d", &v1, &v2);
            weight = (ww[v2]-ww[v1])*(ww[v2]-ww[v1])*(ww[v2]-ww[v1]);
            //     int weight1 = (ww[v1]-ww[v2])*(ww[v1]-ww[v2])*(ww[v1]-ww[v2]);
            adjacencyList[v1].push_back(make_pair(v2, weight));
            //     adjacencyList[v2].push_back(make_pair(v1, weight1));
        }

        vector<int> shortestDistances(vertices+edges + 1);


        int returnValue = bellmanFord(adjacencyList, vertices, 1, shortestDistances);
        int q ;

        cout << "Case "<<++cs<<":\n";

        cin >> q ;

        for(int k=1; k<=q; k++)
        {
            int p;
            cin >> p ;

                if(shortestDistances[p] <3 or shortestDistances[p] >100000)
                    cout << "?" << endl ;
                else
                    cout << shortestDistances[p]<< endl ;

        }

    }

    return 0;
}
