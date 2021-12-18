// build cost O(n)
struct Node {
    int len, sufflink, next[26];
};
struct PalindromicTree {
    int currNode, ptr;
    Node tree[N];
    string s;
    PalindromicTree (string s) : s(s){
        initTree();
    }
 
    int getMaxPalin() {
        int ans = 0;
        for (int i = 2; i<=ptr; i++) {
            ans = max(ans, tree[i].len);
        }
        return ans;
    }
private:
    void initTree() {
        currNode = 1;ptr = 1;
        tree[0].len = -1; tree[0].sufflink = 0;
        tree[1].len = 0; tree[1].sufflink = 0;
        for(int i = 0; i<(int) s.size(); i++)
            insert(i);
    }
 
    void insert(int pos) {
        int cur = currNode;
        int letter = s[pos] - 'a';
        while (true) {
            int curLen = tree[cur].len;
            if (pos - curLen >= 1 && s[pos] == s[pos - curLen - 1]) break;
            cur = tree[cur].sufflink;
        }
 
        if (tree[cur].next[letter]) {
            currNode = tree[cur].next[letter];
            return;
        }
        tree[cur].next[letter] = ++ptr;
        currNode = ptr;
        tree[ptr].len = tree[cur].len + 2;
        //
        if (tree[ptr].len == 1) {
            tree[ptr].sufflink = 1;
            return;
        }
 
        while (true) {
            cur = tree[cur].sufflink;
            int curLen = tree[cur].len;
            if (pos - curLen >= 1 && s[pos] == s[pos - 1 - curLen]) {
                tree[ptr].sufflink = tree[cur].next[letter];
                return;
            }
        }
    }
 
};