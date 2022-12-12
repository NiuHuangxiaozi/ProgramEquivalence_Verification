

#include<map>
using namespace std;
#include <vector>
#include<string>

class DSU
{
public:
    int* rank;
    int* parent;
    int count;
    std::map<std::string, int>path_to_index;

    int find(int p)
    {
        if (p != parent[p])
            parent[p] = find(parent[p]);
        return parent[p];
    }
public:
    DSU(std::vector<std::string>&files)
    {
        count = files.size();
        rank = new int[count];
        parent = new int[count];
        for (int i = 0; i < count; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        for (int i = 0; i < count; i++)
        {
            path_to_index[files[i]] = i;
        }
    }
    int find(std::string s) 
    {
        int p = path_to_index[s];
        if( p != parent[p] )
           parent[p] = find( parent[p] );
        return parent[p];
    }
   bool isConnected(std::string s1, std::string s2) 
   {
        int p = path_to_index[s1];
        int q = path_to_index[s2];
        return find(p) == find(q);
   }
    void unionElements(std::string s1, std::string s2) 
   {

       int p = path_to_index[s1];
       int q = path_to_index[s2];
       int pRoot = find(p);
       int qRoot = find(q);

       if (pRoot == qRoot)
           return;

       if (rank[pRoot] < rank[qRoot]) {
           parent[pRoot] = qRoot;
       }
       else if (rank[qRoot] < rank[pRoot]) {
           parent[qRoot] = pRoot;
       }
       else { // rank[pRoot] == rank[qRoot]
           parent[pRoot] = qRoot;
           rank[qRoot] += 1;   
       }
   }
};
