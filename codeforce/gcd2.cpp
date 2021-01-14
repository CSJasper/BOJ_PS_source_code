#include <iostream>

using namespace std;

int gcd_tree_input(int a, int b, int c);
int gcd (int a, int b);

int main(void)
{
    int a, b, c;
    cin >> a; cin >> b; cin >> c;
    cout << gcd_tree_input(a,b,c);
    return 0;
}

int gcd_tree_input(int a, int b, int c)
{
    // g = gcd(a,b,c) is the greatest number s.t. g|a, g|b and g|c
    // Let  g1 = gcd(a,b) and g2 = gcd(c, g1). Then g2 | g1 and g2 | c.
    // Since g2 | g1, then g2 | a and g2 | b.
    // Therefore g2 is a common divisor of a, b, c.
    // Suppose there is integer g which is a common divisor of a,b,c and
    // greater than g2.
    // Note that g | a and g | b so that g is the common divisor of a and b
    // which is greater than g2 which is contradiction.
    int g2 = gcd(a,b);
    return gcd(g2, c);
}

int gcd(int a, int b)
{
    int r = a % b;
    if (r == 0) return b;
    return gcd(b,r);
}
