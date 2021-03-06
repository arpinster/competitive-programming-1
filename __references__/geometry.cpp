#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;
const PI = acos(-1);

// (POINT)
struct point {
  double x, y;
  point(double x = 0, double y = 0) : x(x), y(y) {}
  bool operator<(point p) const {
    if (fabs(x - p.x) > EPS)
      return x < p.x;
    return y < p.y;
  }
  bool operator==(point p) const {
    return (fabs(x - p.x) < EPS) && (fabs(y - p.y) < EPS);
  }
  point operator+(point p) const { return point(x + p.x, y + p.y); }
  point operator-(point p) const { return point(x - p.x, y - p.y); }
  point operator*(double scale) const { return point(x * scale, y * scale); }
};

double dist(point a, point b) {
  return hypot(a.x - b.x, a.y - b.y);
}

// rotate p by theta degrees CCW w.r.t origin(0, 0)
point rotate(point p, double tetha) {
  // rotate matrix R(theta0 = [cos(theta) -sin(theta)]
  //            [sin(theta)  cos(theta)]
  double rad = tehta * PI / 180.0;
  return point(p.x*cos(rad) - p.y*sin(rad), p.x*sin(rad) + p.y*cos(rad));
}
double cross(point a, point b) {
  return a.x * b.y - a.y * b.x;
}
double dot(point a, point b) {
  return a.x * b.x + a.y * b.y;
}
double norm_sq(point p) {
  return dot(p, p);
}
// return 1 = ccw, 0 = colinear, -1 = cw
int ccw(point p, point q, point r) {
  point pq = q - p, pr = r-p;
  double crs = cross(pq, pr);
  if (fabs(crs) < EPS) return 0;
  return crs > 0 ? 1 : -1;
}
bool between(point p, point q, point r) {
  return ccw(p, q, r) == 0 && (p.x-q.x) * (r.x-q.x) < EPS && (p.y-q.y) * (r.y-q.y) < EPS;
}
// calculate angle between OA and OB
double angle(point a, point o, point b) {
  point oa = a-o, ob = b-o;
  return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}


// (LINE)
struct line { double a,b,c; };
void pointToLine(point p1, point p2, line& l) {
  if(fabs(p1.x - p2.x) < EPS) {
    l.a = 1.0; l.b = 0.0; l.c = -p1.x;
  }
  else {
    l.a = -(double)(p1.y - p2.y)/(p1.x - p2.x)l
    l.b = 1.0;
    l.c = -(double)(l.a * p1.x) - (l.b * p1.y);
  }
}
bool areParallel(line l1, line l2) {
  return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}
bool areSame(line l1, line l2) {
  return areParallel(l1, l2) && (fabs(l1.c-l2.c) < EPS);
}
bool areIntersect(line l1, line l2, point& p) {
  if(areParallel(l1, l2)) return false;
  
  p.x = (l2.b*l1.c - l1.b*l2.c)/(l2.a*l1.b - l1.a*l2.b);
  if(fabs(l1.b) > EPS)
    p.y = -(l1.a*p.x + l1.c)/l1.b;
  else
    p.y = -(l2.a*p.x + l2.c)/l2.b;
  return true;
}

double distToLine(point p, point a, point b, point & c) {
  point ap = p-a, ab = b-a;
  double u = dot(ap, ab) / norm_sq(ab);
  c = a + ab * u;
  return dist(p, c);
}
double distToLineSegment(point p, point a, point b, point &c) {
  point ap = p-a, ab = b-a;
  if (a == b) {
    c = a;
    return dist(p, c);
  }
  double u = dot(ap, ab) / norm_sq(ab);
  if (u < 0.0) c = a;
  else if (u > 1.0) c = b;
  else c = a + ab * u;
  return dist(p, c);
}

// convert point and gradient/slope to line
void pointSlopeToLine(point p, double m, line& l) {
  l.a = -m;
  l.b = 1;
  l.c = -((l.a * p.x) + (l.b * p.y));
}
// find point on line l which is closest to p
void closestPoint(line l, point p, point& ans) {
  line perpendicular;
  if (fabs(l.b) < EPS) {
    ans.x = -l.c; ans.y = p.y;
    return;
  }
  if (fabs(l.a) < EPS) {
    ans.x = p.x; ans.y = -l.c;
    return;
  }
  pointSlopeToLine(p, 1/l.a, perpendicular);
  areIntersect(l, perpendicular, ans);
}
// return the reflection of point on a line
void reflectionPoint(line l, point p, point &ans) {
  point b;
  closestPoint(l, p, b);
  ans = b * 2 - p;
}



// (Circle & Triangle)
// Find two center of same size circle from its intersection and their radius
bool circle2PtsRad(point p1, point p2, double r, point &c) {
  double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y); // = norm_sq(p1-p2)
  double det = r * r / d2 - 0.25;
  if(det < 0.0) return false;
  double h = sqrt(det);
  c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
  c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
  return true;
}
vector<point> interCircle(point o1, double r1, point o2, double r2) {
  double d2 = norm_sq(o1 - o2);
  double d = sqrt(d2);
  if (d < abs(r1-r2)) return {};
  if (d > r1+r2) return {};
  point u = (o1+o2) * 0.5 + (o1-o2)*((r2*r2-r1*r1)/(2*d2));
  double A = sqrt((r1+r2+d) * (r1-r2+d) * (r1+r2-d) * (-r1+r2+d));
  point v = point(o1.y-o2.y, -o1.x+o2.x) * (A / (2*d2));
  return {u+v, u-v};
}
// Heron's formula
double heron(double a, double b, double c) {
  double s = (a + b + c) * 0.5;
  return sqrt(s * (s - a)) * sqrt((s-b) * (s-c));
}
// area by cross
double areaTriangle(point a, point b, point c) {
  return fabs(cross(a-b, c-b)) * 0.5;
}
double rInCircle(double ab, double bc, double ca) {
  return heron(ab, bc, ca) / (0.5 * (ab + bc + ca));
}
double rInCircle(point a, point b, point c) {
  return rInCircle(dist(a, b), dist(b, c), dist(c, a));
}
// return 1 if there is an inCircle center, return 0 otherwise
// if return 1, ctr will be the inCircle cnter, and r is its radius
int inCircle(point p1, point p2, point p3, point &ctr, double &r) {
  r = rInCircle(p1, p2, p3);
  if (fabs(r) < EPS) return 0;
  line l1, l2;
  double ratio = dist(p1, p2) / dist(p1, p3);
  point p = p2 + (p3-p2) * (ratio/(1 + ratio));
  pointToLine(p1, p, l1);

  ratio = dist(p2, p1) / dist(p2, p3);
  p = p1 + (p3-p1) * (ratio/(1 + ratio));
  pointToLine(p2, p, l2);

  return areIntersect(l1, l2, ctr);
}
double rCircumCircle(double ab, double bc, double ca) {// = BC / 2 sin(<ABC)
  return ab * bc * ca / (4.0 * heron(ab, bc, ca));
}
double rCircumCircle(point a, point b, point c) {
  return rCircumCircle(dist(a, b), dist(b, c), dist(c, a));
}

point inCenter(point &A, point &B, point &C) { // 内心
  double a = norm(B-C), b = norm(C-A), c = norm(A-B);
  return (A * a + B * b + C * c) / (a + b + c);
}
point circumCenter(point &a, point &b, point &c) { // 外心
  point bb = b - a, cc = c - a;
  double db = norm_sq(bb), dc = norm_sq(cc), d= 2*cross(bb, cc);
  return a-point(bb.y*dc-cc.y*db, cc.x*db-bb.x*dc) / d;
}
point othroCenter(point &a, point &b, point &c) { // 垂心
  point ba = b - a, ca = c - a, bc = b - c;
  double y = ba.y * ca.y * bc.y,
    A = ca.x * ba.y - ba.x * ca.y,
    x0= (y+ca.x*ba.y*b.x-ba.x*ca.y*c.x) / A,
    y0= -ba.x * (x0 - c.x) / ba.y + ca.y;
  return point(x0, y0);
}

point perp(const point& p) {
  return point(p.y, -p.x);
}
vector<pair<point, point> > tangent2Circle(point o1, double r1, point o2, double r2){
  vector<pair<point, point> > ret;
  double d_sq = norm_sq( o1 - o2);
  if( d_sq < EPS ) return ret;
  double d = sqrt( d_sq );
  point v = ( o2 - o1 ) / d;
  for( int sign1 = 1 ; sign1 >= -1 ; sign1 -= 2 ){
    double c = ( r1 - sign1 * r2 ) / d;
    if( c * c > 1 ) continue;
    double h = sqrt(max( 0.0 , 1.0 - c * c ) );
    for( int sign2 = 1 ; sign2 >= -1 ; sign2 -= 2 ){
      point n;
      n.x = v.x * c - sign2 * h * v.y;
      n.y = v.y * c + sign2 * h * v.x;
      point p1 = o1 + n * r1;
      point p2 = o2 + n * ( r2 * sign1 );
      if( fabs( p1.x - p2.x ) < EPS and
          fabs( p1.y - p2.y ) < EPS )
        p2 = p1 + perp( o2 - o1 );
      ret.push_back( { p1 , p2 } );
    }
  }
  return ret;
}



// (Polygon)
double area(const vector< point > & P) {
  double result = 0.0;
  for(int i = 0; i< (int)P.size()-1; i++) {
    result += (P[i].x * P[i+1].y - P[i].y*P[i+1].x); // cross(P[i], P[i+1]);
  }
  return fabs(result)/2.0;
}

// check if point p inside (CONVEX/CONCAVE) polygon vp
int inPolygon(point p, const vector< point >& vp) {
  int wn = 0, n = (int)vp.size() - 1;
  for(int i = 0; i<n; i++) {
    int cs = ccw(vp[i+1], vp[i], p);
    if(cs == 0 && p.x <= max(vp[i].x, vp[i+1].x) && p.x >= min(vp[i].x, vp[i+1].x)
      && p.y <= max(vp[i].y, vp[i+1].y) && p.y >= min(vp[i].y, vp[i+1].y))
      return 1; // between(vp[i], p, vp[i+1])
    if(vp[i].y <= p.y) {
      if(vp[i+1].y > p.y && cs > 0)
        wn++;
    }
    else {
      if(vp[i+1].y <= p.y && cs < 0)
        wn--;
    }
  }
  return wn;
}

// line segment p-q intersect with line A-B
point lineIntersectSeg(point p, point q, point A, point B) {
  double a = B.y - A.y;
  double b = A.x - B.x;
  double c = B.x * A.y - A.x * B.y;
  double u = fabs(a * p.x + b * p.y + c);
  double v = fabs(a * q.x + b * q.y + c);
  return point((p.x*v + q.x*u)/(u+v), (p.y*v + q.y*u)/(u+v));
}
// cuts polygon Q along the line formed by point a-> point b
// (note: the last point must be the same as the first point)
vector<point> cutPolygon(point a, point b, vector<point> Q) {
  vector<point> P;
  for(int i = 0; i<(int)Q.size(); i++) {
    double left1 = cross(b - a, (Q[i] - a)), left2 = 0.0;
    if(i != (int)Q.size()-1) left2 = cross(b - a, Q[i+1] - a);
    if(left1 > -EPS) P.push_back(Q[i]);
    if(left1 * left2 < -EPS)
        P.push_back(lineIntersectSeg(Q[i], Q[i+1], a, b));
    }

    if(P.empty()) return P;
    if(fabs(P.back().x - P.front().x) > EPS || fabs(P.back().y - P.front().y) > EPS)
        P.push_back(P.front());
    return P;
}

double dist2(point a, point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y); // norm_sq(b - a)
}

point pivot;
bool angle_cmp(point a, point b) {
  if(collinear(pivot, a, b))
    return dist2(a, pivot) < dist2(b, pivot);
  return ccw(pivot, a, b);
}

// hasil convexHull tidak siklik
void convexHull(vector<point> & P) {
  int i, j, n = (int) P.size();
  if(n < 3) {
    return;
  }
  int PO = 0;
  for(i = 1; i < n; i++) {
    if(P[i] < P[PO]) {
      PO = i;
    }
  }
  swap(P[0], P[PO]);
  pivot = P[0];
  sort(++P.begin(), P.end(), angle_cmp);
  // if point on boundary is included then uncomment this:
  // int k = (int)P.size()-1; while (k-1 > 0 && ccw(P[0], P[k-1], P.back()) == 0) k--;
  // reverse(P.begin() + k, P.end());
  vector<point> S;
  S.push_back(P[0]);
  S.push_back(P[1]);
  i = 2;
  while(i < n) {
    j = (int) S.size() - 1;
    // if point on boundary is included then ccw >= 0
    if(j < 1 || ccw(S[j-1], S[j], P[i]) > 0) S.push_back(P[i++]);
    else S.pop_back();
  }
  P = S;
}


//// The Great-Circle Distance (SPHERES)
double gcDistance(double plat, double plong, double qlat, double, qlong ,double radius) {
  plat *= PI/180; plong *= PI/180;
  qlat *= PI/180; qlong *= PI/180;
  return radius *  acos(cos(plat)*cos(plong)*cos(qlat)*cos(qlong) +
          cos(plat)*sin(plong)*cos(qlat)*sin(qlong) +
          sin(plat)*sin(qlat));
}

