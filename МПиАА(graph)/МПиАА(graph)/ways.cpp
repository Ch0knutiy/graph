#include <fstream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main3()
{
   int n, m, v1, v2, l, s, find;
   bool flag = false;
   ifstream fin;
   ofstream fout;
   fout.open("ou.txt", ios::out);
   fin.open("in.txt", ios::in);
   fin >> n >> m;
   vector< vector < int > > g(n);
   for (int i = 0; i < m; i++)
   {
      fin >> v1 >> v2;
      v1--, v2--;
      g[v1].push_back(v2);
      g[v2].push_back(v1);
   }

   for (int i = 0; i < n; i++)
   {
      flag = false;
      vector <bool> is_visited(n, false);
      vector <int> parents(n, 0);
      queue  <int> q;

      q.push(s);
      is_visited[s] = true;
      while (!q.empty())
      {
         l = q.front();
         q.pop();
         for (int i = 0; i < g[l].size(); i++)
            if (is_visited[g[l][i]] == false)
            {
               q.push(g[l][i]);
               is_visited[g[l][i]] = true;
               parents[g[l][i]] = l;
            }

      }
      for (int j = i + 1; j < n; j++)
      {
         int z = 0;
         l = j;
         fout << l + 1 << " -> " << s + 1 << " : ";
         fout << l + 1;
         while (l != s)
         {
            z++;
            l = parents[l];
            fout << " -> " << l + 1;
         }
         fout << " | " << z << endl;
      }
   }
   return 0;
}