bool inside(pt a) {
    int l = 0, r = up.size() - 1, res1 = -1, res2 = -1;
    if (up.back() == a) return true;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (up[mid] > a) {
            res1 = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    if (res1 <= 0) return false;
    
    l = 0, r = down.size() - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (down[mid] > a) {
            res2 = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    
    double wtf = getcw(up[res1 - 1], a, up[res1]) * getcw(down[res2 - 1], a, down[res2]);
    return wtf <= 0;
}