#include <fstream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main2()
{
   int n, m, v1, v2, l, s, find;
   bool flag = false;
   ifstream fin;
   ofstream fout;
   fout.open("ou.txt", ios::out);
   fin.open("in.txt", ios::in);
   fin >> n >> m >> s >> find;
   s--, find--;
   vector< vector < int > > g(n);
   for (int i = 0; i < m; i++)
   {
      fin >> v1 >> v2;
      g[v1 - 1].push_back(v2 - 1);
      g[v2 - 1].push_back(v1 - 1);
   }


      vector <bool> is_visited(n, false);
      vector <int> parents(n, 0);

      queue  <int> q;
      q.push(s);
      is_visited[s] = true;
      while (!q.empty())
      {
         l = q.front();
         q.pop();
         //fout << l + 1 << " ";
         /*if (l == find)
            break;*/

         for (int i = 0; i < g[l].size(); i++)
            if (is_visited[g[l][i]] == false)
            {
               q.push(g[l][i]);
               is_visited[g[l][i]] = true;
               parents[g[l][i]] = l;
            }

      }
      int z = 0;
      fout << l + 1 << ' ';
      for (int i = 0; i < n; i++)
         for (int j = parents[i]; j < n; j++)
         {
            l = j;
            s = i;
            while (l != s)
            {
               z++;
               l = parents[l];
               fout << l + 1 << ' ';
            }
            fout << endl << z << endl;
         }
   return 0;
}
