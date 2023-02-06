#include<bits/stdc++.h>
using namespace std;

#define LOCAL

#define BIT(n)                    ( 1<<(n) )
#define BITTEST(var,pos)          ((var) & BIT(pos))
#define BITBOOL(var,pos)          (((var) & BIT(pos)) > 0)
#define BITSET(var,pos)           ((var) | BIT(pos))
#define BITUNSET(var,pos)         ((var) & (~BIT(pos)))
#define BITFLIP(var,pos)          ((var) ^ (~BIT(pos)))

// Create a bitmask of length len.
#define BIT_MASK(len)             ( BIT(len)-1 )
// Create a bitfield mask of length starting at bit 'start'.
#define BF_MASK(start, len)       ( BIT_MASK(len)<<(start) )

// Prepare a bitmask for insertion or combining.
#define BF_PREP(x, start, len)    ( ((x)&BIT_MASK(len)) << (start) )
// Extract a bitfield of length len starting at bit 'start' from y.
#define BF_GET(y, start, len)     ( ((y)>>(start)) & BIT_MASK(len) )
// Insert a new bitfield value x into y.
#define BF_SET(y, x, start, len)  ( y= ((y) &~ BF_MASK(start, len)) | BF_PREP(x, start, len) )

const int INF = 1e9;

typedef vector<int> vi;
typedef pair<int, string> pis;
map<string, vi> catGene;
vector<string> catColor(64, "");

#define c_it        map<string, vi>::iterator 

int cmp(const pis a , const pis b) {
    if(a.first > b.first) return 1;
    else if(a.first == b.first) return(a.second < b.second);
    return 0;
} 

void InitCatColorGeneLib() {
    vi gene;
    c_it it;
    string color;
    for(int i = 0; i < 64; i++) {
        color = "none";
        if(BF_GET(i, 0, 2) == 0) {
            // no dominant red
            if(BF_GET(i, 2, 2) > 0x00 && BF_GET(i, 4, 2) > 0x00) {
                // Black(B-D-oo)
                color = "Black";
            } else if(BF_GET(i, 2, 2) == 0x00 && BF_GET(i, 4, 2) > 0x00) {
                // Blue(B-ddoo)
                color = "Blue";
            } else if(BF_GET(i, 2, 2) > 0x00 && BF_GET(i, 4, 2) == 0x00) {
                // Chocolate(bbD-oo)
                color = "Chocolate";
            } else if(i == 0) {
                // Lilac(bbddoo)
                color = "Lilac";
            }
        } else if(BF_GET(i, 0, 2) == 3) {
            // Red(--D-O/OO) or Cream(--ddO/OO)
            if(BF_GET(i, 2, 2) > 0x00) color = "Red";
            else color = "Cream";
        } else {
            // Torties (Oo or oO) must be female cat
            if(BF_GET(i, 2, 2) > 0x00 && BF_GET(i, 4, 2) > 0x00) {
                // Black-Red Tortie(B-D-Oo)
                color = "Black-Red Tortie";
            } else if(BF_GET(i, 2, 2) == 0x00 && BF_GET(i, 4, 2) > 0x00) {
                // Blue-Cream Tortie(B-ddOo)
                color = "Blue-Cream Tortie";
            } else if(BF_GET(i, 2, 2) > 0x00 && BF_GET(i, 4, 2) == 0x00) {
                // Chocolate-Red Tortie(bbD-Oo)
                color = "Chocolate-Red Tortie";
            } else if(BF_GET(i, 2, 4) == 0) {
                // Lilac-Cream Tortie(bbddOo)
                color = "Lilac-Cream Tortie";
            }
        }
        catColor[i] = color;
        it = catGene.find(color);
        if(it == catGene.end()) {
            catGene.insert({color, {i}});
        } else {
            it->second.push_back(i);
        }
    }
    /*
    // Black(B-D-oo): 01 01 00, 01 10 00, 01 11 00,
    //                10 01 00, 10 10 00, 10 11 00,
    //                11 01 00, 11 10 00, 11 11 00
    gene.push_back(0x14); catColor[0x14] = "Black";
    gene.push_back(0x18); catColor[0x18] = "Black";
    gene.push_back(0x1C); catColor[0x1C] = "Black";
    gene.push_back(0x24); catColor[0x24] = "Black";
    gene.push_back(0x28); catColor[0x28] = "Black";
    gene.push_back(0x2C); catColor[0x2C] = "Black";
    gene.push_back(0x34); catColor[0x34] = "Black";
    gene.push_back(0x38); catColor[0x38] = "Black";
    gene.push_back(0x3C); catColor[0x3C] = "Black";
    catGene.insert({"Black", gene});
    // Blue(B-ddoo): 01 00 00, 10 00 00, 11 00 00
    gene.clear();
    gene.push_back(0x10); catColor[0x10] = "Blue";
    gene.push_back(0x20); catColor[0x20] = "Blue";
    gene.push_back(0x30); catColor[0x30] = "Blue";
    catGene.insert({"Blue", gene});
    // Chocolate(bbD-oo): 00 01 00, 00 10 00, 00 11 00
    gene.clear();
    gene.push_back(0x04); catColor[0x04] = "Chocolate";
    gene.push_back(0x08); catColor[0x08] = "Chocolate";
    gene.push_back(0x0C); catColor[0x0C] = "Chocolate";
    catGene.insert({"Chocolate", gene});
    // Lilac(bbddoo): 00 00 00
    gene.clear();
    gene.push_back(0x00); catColor[0x00] = "Lilac";
    catGene.insert({"Lilac", gene});
    // Red(--D-O/OO): 00 01 11, 00 10 11, 00 11 11,
    //                01 01 11, 01 10 11, 01 11 11,
    //                10 01 11, 10 10 11, 10 11 11,
    //                11 01 11, 11 10 11, 11 11 11
    gene.clear();
    gene.push_back(0x07); catColor[0x07] = "Red";
    gene.push_back(0x0B); catColor[0x0B] = "Red";
    gene.push_back(0x0F); catColor[0x0F] = "Red";
    gene.push_back(0x17); catColor[0x17] = "Red";
    gene.push_back(0x1B); catColor[0x1B] = "Red";
    gene.push_back(0x1F); catColor[0x1F] = "Red";
    gene.push_back(0x27); catColor[0x27] = "Red";
    gene.push_back(0x2B); catColor[0x2B] = "Red";
    gene.push_back(0x2F); catColor[0x2F] = "Red";
    gene.push_back(0x37); catColor[0x37] = "Red";
    gene.push_back(0x3B); catColor[0x3B] = "Red";
    gene.push_back(0x3F); catColor[0x3F] = "Red";
    catGene.insert({"Red", gene});
    // Cream(--ddO/OO): 00 00 11, 01 00 11, 10 00 11, 11 00 11
    gene.clear();
    gene.push_back(0x03); catColor[0x03] = "Cream";
    gene.push_back(0x13); catColor[0x13] = "Cream";
    gene.push_back(0x23); catColor[0x23] = "Cream";
    gene.push_back(0x33); catColor[0x33] = "Cream";
    catGene.insert({"Cream", gene});
    // Torties must be female cat
    // Black-Red Tortie(B-D-Oo): 01 01 01, 01 01 10, 01 10 01, 01 10 10, 01 11 01, 01 11 10,
    //                           10 01 01, 10 01 10, 10 10 01, 10 10 10, 10 11 01, 10 11 10,
    //                           11 01 01, 11 01 10, 11 10 01, 11 10 10, 11 11 01, 11 11 10
    gene.clear();
    gene.push_back(0x15); catColor[0x15] = "Black-Red Tortie";
    gene.push_back(0x16); catColor[0x16] = "Black-Red Tortie";
    gene.push_back(0x19); catColor[0x19] = "Black-Red Tortie";
    gene.push_back(0x1A); catColor[0x1A] = "Black-Red Tortie";    
    gene.push_back(0x1D); catColor[0x1D] = "Black-Red Tortie";
    gene.push_back(0x1E); catColor[0x1E] = "Black-Red Tortie";   
    gene.push_back(0x25); catColor[0x25] = "Black-Red Tortie";
    gene.push_back(0x26); catColor[0x26] = "Black-Red Tortie";
    gene.push_back(0x29); catColor[0x29] = "Black-Red Tortie";
    gene.push_back(0x2A); catColor[0x2A] = "Black-Red Tortie";
    gene.push_back(0x2D); catColor[0x2D] = "Black-Red Tortie";
    gene.push_back(0x2E); catColor[0x2E] = "Black-Red Tortie";
    gene.push_back(0x35); catColor[0x35] = "Black-Red Tortie";
    gene.push_back(0x36); catColor[0x36] = "Black-Red Tortie";
    gene.push_back(0x39); catColor[0x39] = "Black-Red Tortie";
    gene.push_back(0x3A); catColor[0x3A] = "Black-Red Tortie";
    gene.push_back(0x3D); catColor[0x3D] = "Black-Red Tortie";
    gene.push_back(0x3E); catColor[0x3E] = "Black-Red Tortie";
    catGene.insert({"Black-Red Tortie", gene});
    // Blue-Cream Tortie(B-ddOo): 01 00 01, 01 00 10, 10 00 01, 10 00 10, 11 00 01, 11 00 10
    gene.clear();
    gene.push_back(0x11); catColor[0x11] = "Blue-Cream Tortie";
    gene.push_back(0x12); catColor[0x12] = "Blue-Cream Tortie";
    gene.push_back(0x21); catColor[0x21] = "Blue-Cream Tortie";
    gene.push_back(0x22); catColor[0x22] = "Blue-Cream Tortie";
    gene.push_back(0x31); catColor[0x31] = "Blue-Cream Tortie";
    gene.push_back(0x32); catColor[0x32] = "Blue-Cream Tortie";
    catGene.insert({"Blue-Cream Tortie", gene});        
    // Chocolate-Red Tortie(bbD-Oo): 00 01 01, 00 01 10, 00 10 01, 00 10 10, 00 11 01, 00 11 10
    gene.clear();
    gene.push_back(0x05); catColor[0x05] = "Chocolate-Red Tortie";
    gene.push_back(0x06); catColor[0x06] = "Chocolate-Red Tortie";
    gene.push_back(0x09); catColor[0x09] = "Chocolate-Red Tortie";
    gene.push_back(0x0A); catColor[0x0A] = "Chocolate-Red Tortie";   
    gene.push_back(0x0D); catColor[0x0D] = "Chocolate-Red Tortie";
    gene.push_back(0x0E); catColor[0x0E] = "Chocolate-Red Tortie";
    catGene.insert({"Chocolate-Red Tortie", gene});
    // Lilac-Cream Tortie(bbddOo): 00 00 01, 00 00 10
    gene.clear();
    gene.push_back(0x01); catColor[0x01] = "Lilac-Cream Tortie";
    gene.push_back(0x02); catColor[0x02] = "Lilac-Cream Tortie";
    catGene.insert({"Lilac-Cream Tortie", gene});
    */
}

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Cat Coat Colors.02";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    InitCatColorGeneLib();
    string mom, dad;
    getline(cin, mom);
    getline(cin, dad);
    vi mG = catGene.find(mom)->second;
    vi dG = catGene.find(dad)->second;
    
    // Mate
    map<string, int> catCount;
    int sum = 0;
    int mgSize = mG.size();
    int dgSize = dG.size();
    for(int i = 0; i < mgSize; i++) {
        // 01 equivalent to 10
        if(BF_GET(mG[i], 0, 2) == 1) continue;
        if(BF_GET(mG[i], 2, 2) == 1) continue;
        if(BF_GET(mG[i], 4, 2) == 1) continue; 
        for(int j = 0; j < dgSize; j++) {
            // mom: 2 * 2 * 2, dad: 2 * 2 * 2
            if(BF_GET(dG[j], 0, 2) == 1) continue;
            if(BF_GET(dG[j], 2, 2) == 1) continue;
            if(BF_GET(dG[j], 4, 2) == 1) continue; 
            int kitten, momR;
            for(int m = 0; m < 8; m++) {
                kitten = 0;
                momR = BITBOOL(mG[i], BITBOOL(m, 0));   // 0 or 1
                kitten = BF_SET(kitten, momR, 0, 1);
                kitten = BF_SET(kitten, BITBOOL(mG[i], 2 + BITBOOL(m, 1)), 2, 1);
                kitten = BF_SET(kitten, BITBOOL(mG[i], 4 + BITBOOL(m, 2)), 4, 1);
                for(int d = 0; d < 8; d++) {
                    if(BITBOOL(d, 0) == 1) {
                        // female kitten: also gets red-gene from dad
                        kitten = BF_SET(kitten, BITBOOL(dG[j], 0), 1, 1);
                    } else {
                        // Copy mom's red-gene
                        kitten = BF_SET(kitten, momR, 1, 1);
                    }
                    kitten = BF_SET(kitten, BITBOOL(dG[j], 2 + BITBOOL(d, 1)), 3, 1);
                    kitten = BF_SET(kitten, BITBOOL(dG[j], 4 + BITBOOL(d, 2)), 5, 1);
                    string color = catColor[kitten];
                    map<string, int>::iterator it = catCount.find(color);
                    if(it == catCount.end()) {
                        catCount.insert({color, {1}});
                    } else {
                        it->second++;
                    }
                    sum++;                 
                }
            }
        }
    }

    vector<pis> sortCnt;
    for(auto i : catCount) {
        sortCnt.push_back({i.second, i.first});
    }
    sort(sortCnt.begin(), sortCnt.end(), cmp);

    // Output
    for(auto i : sortCnt) {
        printf("%s %0.9lf\n", i.second.c_str(), (double)i.first / (double)sum);
    }
    return 0;
}