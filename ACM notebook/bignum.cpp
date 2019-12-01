string mul(string a,string b)
{
  int m=a.length(),n=b.length(),sum=0;
  string c="";
  for (int i=m+n-1; i>=0; i--)
  {
    for (int j=0; j<m; j++) if (i-j>0 && i-j<=n) sum+=(a[j]-'0')*(b[i-j-1]-'0');
    c=(char)(sum%10+'0')+c;
    sum/=10;
  }
  while (c.length()>1 && c[0]=='0') c.erase(0,1);
  return c;
}