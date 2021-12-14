typedef pair<double, double> pt;

double getcw(pt p1, pt p2, pt p3) {
  return p1.first * (p3.second - p2.second) + p2.first * (p1.second - p3.second) + p3.first * (p2.second - p1.second);
}

bool cw(pt p1, pt p2, pt p3) {
  return getcw(p1, p2, p3) >= 0;
}

bool ccw(pt p1, pt p2, pt p3) {
  return getcw(p1, p2, p3) <= 0;
}

vector<pt> monotone(vector<pt> &a) {
  if (a.size() == 1) return vector<pt>(a);
  sort(a.begin(), a.end()); // sort x then y
  pt p1 = a[0];
  pt p2 = a.back();

  vector<pt> up, down;
  up.push_back(a[0]);
  down.push_back(a[0]);

  for (int i = 1; i < a.size(); ++i) {
    if (i == a.size() - 1 || cw(p1, a[i], p2)) {
      while (up.size() >= 2 && !cw(up[up.size() - 2], up.back(), a[i]))
        up.pop_back();
      up.push_back(a[i]);
    }
    if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
      while (down.size() >= 2 && !ccw(down[down.size() - 2], down.back(), a[i]))
        down.pop_back();
      down.push_back(a[i]);
    }
  }

  vector<pt> res(up);
  for (int i = down.size() - 2; i > 0; --i)
    res.push_back(down[i]);
  return res;
}