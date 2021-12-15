 
struct node{
    int _time, ans;
    node *l, *r;
    node(): l(r=nullptr), _time(0), ans(1){}
};
 
int last[N], Local_time;
vector <int> step[N];
node *root[N];
vector <pii> p[N];
 
void build(node *v, int tl, int tr){
    if(tl != tr){
        v -> l = new node();
        v -> r = new node();
        int tm = (tl + tr) >> 1;
        build(v -> l, tl, tm);
        build(v -> r, tm + 1, tr);
    }
}
 
void modify(node *v, int tl, int tr, int pos, pii fraction){
    if(tl == tr){
        v -> ans *= fraction.fi;
        v -> ans /= fraction.se;
    }else{
        int tm = (tl + tr) >> 1;
        if(pos <= tm){
            if((v -> l) -> _time != Local_time){
                node *old = v -> l;
                v -> l = new node();
                (v -> l) -> ans = old -> ans;
                (v -> l) -> l = old -> l;
                (v -> l) -> r = old -> r;
                (v -> l) -> _time = Local_time;
            }
            modify(v -> l, tl, tm, pos, fraction);
        }else{
            if((v -> r) -> _time != Local_time){
                node *old = v -> r;
                v -> r = new node();
                (v -> r) -> ans = old -> ans;
                (v -> r) -> l = old -> l;
                (v -> r) -> r = old -> r;
                (v -> r) -> _time = Local_time;
            }
            modify(v -> r, tm + 1, tr, pos, fraction);
        }
        v -> ans = mul((v -> l) -> ans, (v -> r) -> ans);
    }
}
 
int get(node *v,  int tl, int tr, int l, int r){
    if(l > r)return 1;
    if(tl == l && tr == r)return v -> ans;
    int tm = (tl + tr) >> 1;
    return mul(get(v -> l, tl, tm, l, min(r, tm)), get(v -> r, tm + 1, tr, max(l, tm + 1), r));
}
 
//for first version:
root[0] = new node();
build(root[0], 1, n);
//when creating new version
Local_time++;
        root[i] = new node();
        root[i] -> ans = root[i - 1] -> ans;
        root[i] -> l = root[i - 1] -> l;
        root[i] -> r = root[i - 1] -> r;
        root[i] -> _time = Local_time;
//when calling: modify(root[i], 1, n, pos, {vals});
//when query: get(root[r], 1, n, l, r);