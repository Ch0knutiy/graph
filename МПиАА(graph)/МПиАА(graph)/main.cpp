#include <fstream>
#include <vector>
#include <stack>

using namespace std;

int main1()
{
   int n, m, v1, v2, l, s;
   ifstream fin;
   ofstream fout;
   fout.open("ou.txt", ios::out);
   fin.open("in.txt", ios::in);
   fin >> n >> m >> s;
   s--;
   vector< vector < int > > g(n);
   for (int i = 0; i < m; i++)
   {
      fin >> v1 >> v2;
      g[v1 - 1].push_back(v2 - 1);
      g[v2 - 1].push_back(v1 - 1);
   }
   vector <bool> is_visited(n, false);
   stack  <int> q;
   q.push(s);
   while (!q.empty())
   {
      l = q.top();
      q.pop();
      if (is_visited[l] == false)
      {
         is_visited[l] = true;
         fout << l+1 << " ";
         for (int i = 0; i < g[l].size(); i++)
            if (is_visited[g[l][i]] == 0)
               q.push(g[l][i]);
      }
   }
   return 0;
}
