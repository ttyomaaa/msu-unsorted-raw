int f_up(double x, double y);
int f_down(double x, double y);

int f_up(double x, double y)
{
 if (x<y)return -1;
 if (x>y) return 1;
 return 0;
 }

int f_down(double x, double y)
{
 if (x>y)return -1;
 if (x<y) return 1;
 return 0;
 }

