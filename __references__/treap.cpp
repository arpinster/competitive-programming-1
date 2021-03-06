/**
 * Treap = BST + Heap
 * alternative name: - Cartesian Tree
 *                   - Randomized BST
 */

#include <bits/stdc++.h>

using namespace std;

typedef struct item * pitem;
struct item
{
  int prior, key, cnt;
  pitem l, r;
  item() {}
  item(int key, int prior) : cnt(1), key(key), prior(prior), l(NULL), r(NULL) {}
};
int cnt(pitem t) {
  return t ? t->cnt : 0;
}
void upd_cnt(pitem it) {
  if (it) {
    it->cnt = cnt(it->l) + cnt(it->r) + 1;
  }
}
void split(pitem t, int key, pitem & l, pitem & r) {
  if (!t)
    l = r = NULL;
  else if (t->key < key)
    split(t->r, key, t->r, r), l = t;
  else
    split(t->l, key, l, t->l), r = t;
  upd_cnt(l);
  upd_cnt(r);
}
void merge(pitem &t, pitem l, pitem r) {
  if (!l || !r)
    t = l ? l : r;
  else if (l->prior > r->prior)
    merge(l->r, l->r, r), t = l;
  else
    merge(r->l, l, r->l), t = r; 
  upd_cnt(t); 
}
void insert(pitem & t, pitem  it) {
  if (!t)
    t = it;
  else if (it->prior > t->prior)
    split(t, it->key, it->l, it->r), t = it;
  else
    insert(t->key > it->key ? t->l : t->r, it);
  upd_cnt(t);
}
void erase(pitem &t, int key) {
  if (!t)
    return;
  else if (t->key == key)
    merge(t, t->l, t->r);
  else
    erase(key < t->key ? t->l : t->r, key);
  upd_cnt(t);
}

void print(pitem t) {
  if (!t) return;
  printf("%d\n", t->key);
  printf("%d kiri\n", t->key);
  print(t->l);
  printf("%d kanan\n", t->key);
  print(t->r);
}

pitem unite(pitem l, pitem r) {
  if (!l || !r)
    return l ? l : r;
  if (l->prior < r->prior)
    swap(l, r);
  pitem t1, t2;
  split(r, l->key, t1, t2);
  l->l = unite(l->l, t1);
  l->r = unite(l->r, t2); 
  return l;
}

int get(pitem & t, int key) {
  if (!t)
    return 0;
  else if (t->key == key)
    return 0;
  else if (t->key > key)
    return get(t->l, key);
  else
    return cnt(t->l) + 1 + get(t->r, key);
}

int main() {
  
  return 0;
}