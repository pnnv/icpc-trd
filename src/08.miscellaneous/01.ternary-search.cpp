// Theme: Ternary Search

// Algorithm: Continuous Search With Golden Ratio
// Complexity: O(log(N))

// Golden Ratio
// Phi = 1.618...
double phi = (1 + sqrt(5)) / 2;

double cont_tern_srch(double l, double r) {
  double m1 = l + (r - l) / (1 + phi),
    m2 = r - (r - l) / (1 + phi);

  double f1 = f(m1), f2 = f(m2);

  int count = 200;
  while (count--) {
    if (f1 < f2) {
      r = m2;
      m2 = m1;
      f2 = f1;
      m1 = l + (r - l) / (1 + phi);
      f1 = f(m1);
    }
    else {
      l = m1;
      m1 = m2;
      f1 = f2;
      m2 = r - (r - l) / (1 + phi);
      f2 = f(m2);
    }
  }

  return f((l + r) / 2);
}

// Algorithm: Discrete Search 
// Complexity: O(log(N))

double discr_tern_srch(int l, int r) {
  while (r - l > 2) {
    int m1 = l + (r - l) / 3,
      m2 = r - (r - l) / 3;
    if (f(m1) < f(m2))
      r = m2;
    else
      l = m1;
  }

  return min(f(l), min(f(l + 1), f(r)));
}