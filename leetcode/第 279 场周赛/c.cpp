// bitset不能动态设置大小，不可用
// 显然，不能真的去翻转
// 起初，只想到维护翻转次数
// 没想到维护0和1的个数可以直接解决判断1的个数的问题，这个纯属突然想到的，没有任何引导
// 关键就在于如何协调表现形式，实际数值和翻转次数之间的关系
class Bitset {
public:
    int ft = 0;
    int c0, c1 = 0;
    int len;
    vector<bool> s, tmp;
    vector<int> f;
    Bitset(int size) {
        s = vector<bool> (size, false);
        f = vector<int> (size, 0);
        len = size;
        c0 = size;
    }
    
    void fix(int idx) {
        // 实际数值为1则不需要修改，有下面两种情况是实际数值为1的
        // 1. 表现形式为1，翻转次数为偶数(相当于没翻转)
        // 2. 变现形式为0，翻转次数为奇数(相当于翻转1次)
        if (s[idx] == 1 && !(ft & 1)) return;
        if (s[idx] == 0 && (ft & 1)) return;
        
        // s[idx] == 1 && ft 为 奇数
        // 表现形式是1，实际数值是0
        // 要将实际数值修改为1，则表现形式应当为多少？
        // ft为奇数时，表现形式为0时，实际数值为1
        // 所以要将表现形式修改为0

        // s[idx] == 0 && ft 为 偶数
        // 同理，表现形式应当修改为1

        // 即1变0，0变1
        s[idx] = s[idx] ^ 1;
        --c0;
        ++c1;
    }
    
    void unfix(int idx) {
        // 同理
        if (s[idx] == 0 && !(ft & 1)) return;
        if (s[idx] == 1 && (ft & 1)) return;
        
        // 同理，1变0，0变1
        s[idx] = s[idx] ^ 1;
        --c1;
        ++c0;
    }
    
    void flip() {
        ++ft;
        swap(c0, c1);
    }
    
    bool all() {
        return c1 == len;
    }
    
    bool one() {
        return c1;
    }
    
    int count() {
        return c1;
    }
    
    string toString() {
        string res = "";
        for (int i = 0; i < len; ++i)
            if (!(ft & 1)) res += s[i] + '0';
            else res += (s[i] ^ 1) + '0';
        return res;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */