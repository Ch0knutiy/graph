#include <fstream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

const int infinity = 1000000000;

void reconstruction_of_ways(int i, int j, vector< vector < int > > g, vector< vector < int > > p, ofstream &fout)
{
   if (p[i][j] != 0)
      reconstruction_of_ways(i, p[i][j], g, p, fout);
   fout << j + 1 << " ";
}

// Матрица смежности.

int main()
{
   int n, m, v1, v2, l, s, f, min;
   ifstream fin;
   ofstream fout;
   fout.open("ou.txt", ios::out);
   fin.open("in.txt", ios::in);
   fin >> n >> m;
   vector< vector < int > > g(n), p(n);
   for (int i = 0; i < n; i++)
   {
      p[i].resize(n);
      g[i].resize(n);
      for (int j = 0; j < n; j++)
         if (i == j)
            g[i][j] = 0;
         else 
            g[i][j] = infinity;
   }
   for (int i = 0; i < m; i++)
   {
      fin >> v1 >> v2 >> l;
      v1--, v2--;
      g[v1][v2] = l;
   }
   for (int k = 0; k < n; ++k)
      for (int i = 0; i < n; ++i)
         for (int j = 0; j < n; ++j) 
         {
            if (g[i][j] > (min = g[i][k] + g[k][j])) 
            {
               p[i][j] = k;
               g[i][j] = min;
            }
         }
   for (s = 0; s < n; s++)
      for (f = s; f < n; f++) 
      {
         fout << s + 1 << "->" << f + 1 << " way: " << s + 1 << " ";
         reconstruction_of_ways(s, f, g, p, fout);
         fout << " || " << g[s][f] << endl;
      }
   return 0;
}