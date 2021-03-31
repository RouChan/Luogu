#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

inline bool IsPrime(int n);
inline void Generate(int n);

int a, b;

int main () {
    ios::sync_with_stdio(false);
    cin >> a >> b;

    for(int i = 1; i <= 9; ++i) {
        Generate(i);
    }

    return 0;
}

inline bool IsPrime(int n) {
    int max = sqrt(n);
    bool flag = true;

    for(int i = 3; i <= max; i += 2) {
        if(n % i == 0) {
            flag = false;
            break;
        }
    }
    return flag;
}

inline void Generate(int n) {
    if(n == 1) {
        if(a <= 5 && 5 <= b) cout << 5 << endl;
        if(a <= 7 && 7 <= b) cout << 7 << endl;
    } else if (n == 2) {
        for(int d = 1; d <= 9; d += 2) {
            int tmp = d * 10 + d;
            if(a <= tmp && tmp <= b && IsPrime(tmp)) cout << tmp << endl;
        }
    } else if (n == 3) {
        for(int d1 = 1; d1 <= 9; d1 += 2) {
            for(int d2 = 0; d2 <= 9; ++d2) {
                int tmp = d1 * 100 + d2 * 10 + d1;
                if(a <= tmp && tmp <= b && IsPrime(tmp)) cout << tmp << endl;
            }
        }
    } else if (n == 4) {
        for(int d1 = 1; d1 <= 9; d1 += 2) {
            for(int d2 = 0; d2 <= 9; ++d2) {
                int tmp = d1 * 1000 + d2 * 100 + d2 * 10 + d1;
                if(a <= tmp && tmp <= b && IsPrime(tmp)) cout << tmp << endl;
            }
        }
    } else if (n == 5) {
        for(int d1 = 1; d1 <= 9; d1 += 2) {
            for(int d2 = 0; d2 <= 9; ++d2) {
                for(int d3 = 0; d3 <= 9; ++d3) {
                    int tmp = 10000 * d1 + 1000 * d2 + 100 *d3 + 10 * d2 + d1;
                    if(a <= tmp && tmp <= b && IsPrime(tmp)) cout << tmp << endl;
                }
            }
        }
    } else if (n == 6) {
        for(int d1 = 1; d1 <= 9; d1 += 2) {
            for(int d2 = 0; d2 <= 9; ++d2) {
                for(int d3 = 0; d3 <= 9; ++d3) {
                    int tmp = 100000 * d1 + 10000 * d2 + 1000 *d3 + 100 * d3 + 10 * d2 + d1;
                    if(a <= tmp && tmp <= b && IsPrime(tmp)) cout << tmp << endl;
                }
            }
        }
    } else if (n == 7) {
        for(int d1 = 1; d1 <= 9; d1 += 2) {
            for(int d2 = 0; d2 <= 9; ++d2) {
                for(int d3 = 0; d3 <= 9; ++d3) {
                    for(int d4 = 0; d4 <= 9; ++d4) {
                        int tmp = 1000000 * d1 + 100000 * d2 + 10000 *d3 + 1000 * d4 + 100 * d3 + 10 * d2  + d1;
                        if(a <= tmp && tmp <= b && IsPrime(tmp)) cout << tmp << endl;
                    }
                    
                }
            }
        }
    } else if (n == 8) {
        for(int d1 = 1; d1 <= 9; d1 += 2) {
            for(int d2 = 0; d2 <= 9; ++d2) {
                for(int d3 = 0; d3 <= 9; ++d3) {
                    for(int d4 = 0; d4 <= 9; ++d4) {
                        int tmp = 10000000 * d1 + 1000000 * d2 + 100000 *d3 + 10000 * d4 + 1000 * d4 + 100 * d3 + 10 * d2  + d1;
                        if(a <= tmp && tmp <= b && IsPrime(tmp)) cout << tmp << endl;
                    }
                    
                }
            }
        }
    } else if (n == 9) {
        for(int d1 = 1; d1 <= 9; d1 += 2) {
            for(int d2 = 0; d2 <= 9; ++d2) {
                for(int d3 = 0; d3 <= 9; ++d3) {
                    for(int d4 = 0; d4 <= 9; ++d4) {
                        for(int d5 = 0; d5 <= 9; ++d5) {
                            int tmp = 100000000 * d1 + 10000000 * d2 + 1000000 *d3 + 100000 * d4 + 10000 * d5 + 1000 * d4 + 100 * d3 + 10 * d2  + d1;
                            if(a <= tmp && tmp <= b && IsPrime(tmp)) cout << tmp << endl;
                        }
                        
                    }  
                }
            }
        }
    }
}