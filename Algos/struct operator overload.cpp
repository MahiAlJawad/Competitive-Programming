//sample code snippet for structure operator overloading
struct node
{
    ll a, b;
    bool operator <(const node &x) const
    {
        return a<x.a;
    }
};
