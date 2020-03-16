#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int p[300001];

int find(int x)
{
   if (p[x] < 0) return x;
   return p[x]=find(p[x]);
}

void connect(int x, int y)
{
   x = find(x);
   y = find(y);
   
   if (x == y)
   {
      p[x] = 0;
      return;
   }
   p[x]= y;

}

int main()
{
   int n, l; cin >> n >> l;
   
   fill(p, p + 300001, -1);

   while (n--)
   {
      int x, y; cin >> x >> y;

      if (p[x] == -1)
      {
         cout << "LADICA" << "\n";
         connect(x, y);
      }
      else if (p[y] == -1)
      {
         cout << "LADICA" << "\n";
         connect(y, x);
      }
      else 
      {
         int xx = find(p[x]);
         int yy = find(p[y]);

         //cout<<xx<<" "<<yy<<"\n";

         if (xx != 0)
         {
            cout << "LADICA" << "\n";
            connect(xx, 0);
         }
         else if (yy != 0)
         {
            cout << "LADICA" << "\n";
            connect(yy,0);
         }
         else cout << "SMECE" << "\n";
      }
   }
}