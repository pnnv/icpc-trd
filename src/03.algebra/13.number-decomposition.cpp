// Theme: Integer Numbers Decomposition With Composite Module

// Module
// m = (p1 ^ m1) * (p2 ^ m2) * ... * (pn ^ mn)
int m;                  
// Prime Divisors Of Module
vector<int> p;          
 

struct num {
	// GCD(x, m) = 1
    int x;    
	// Powers Of Primes
    vector<int> a;       
                       
    num() : x(0), a(vector<int>(p.size())) { }

	// n = (p1 ^ a1) * (p2 ^ a2) * ... * (pn ^ an) * x
    num(int n) : x(0), a(vector<int>(p.size())) {
        if (!n) return;
        for (int i = 0; i < p.size(); i++) {
            int ai = 0;
            while (n % p[i] == 0) {
                n /= p[i];
                ai++;
            }
            a[i] = ai;
        }
        x = n;
    }

    num operator*(const num &nm) {
        vector<int> new_a(p.size());
        for (int i = 0; i < p.size(); i++)
            new_a[i] = a[i] + nm.a[i];
        num res; res.a = new_a;
        res.x = x * nm.x % m;
        return res;
    }

    num operator/(const num &nm) {
        vector<int> new_a(p.size());
        for (int i = 0; i < p.size(); i++)
            new_a[i] = a[i] - nm.a[i];
        num res; res.a = new_a;
        int g = euclid(nm.x, m)[1];
        g += m; g %= m;
        res.x = x * g % m;
        return res;
    }

    int toint() {
        int res = x;
        for (int i = 0; i < p.size(); i++)
            res = res * binpow(p[i], a[i], m) % m;
        return res;
    }
};