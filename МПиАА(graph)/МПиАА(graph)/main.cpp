#include <fstream>
#include <vector>
#include <stack>
#include <ctime>

using namespace std;

int main()
{
   int n, m, v1, v2, l;
   ifstream fin;
   ofstream fout;
   fout.open("ou.txt", ios::out);
   fin.open("in.txt", ios::in);
   fin >> n >> m;
   vector< vector < int > > g(n);
   for (int i = 0; i < m; i++)
   {
      fin >> v1 >> v2;
      g[v1 - 1].push_back(v2 - 1);
      g[v2 - 1].push_back(v1 - 1);
   }
   int s = 0;
   vector<int> p(n, 0);
   stack  <int> q;
   q.push(s);
   while (!q.empty())
   {
      l = q.top();
      q.pop();
      if (p[l] == 0)
      {
         p[l] = 1;
         fout << l << ' ';
         for (int i = 0; i < g[l].size(); i++)
            if (p[g[l][i]] == 0)
               q.push(g[l][i]);
      }
   }
}
