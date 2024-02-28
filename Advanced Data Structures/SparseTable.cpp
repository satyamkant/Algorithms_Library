// use only for range min,max or GCD
class SparseTable{
    vector<vector<int>> m;
    vector<int> bin_log;
    const int LOG = 20;

    int operation(int a,int b){
        return min(a,b);
    }
    
public:
     void build(vector<int> &arr,int n){
        m.resize(n+1,vector<int>(LOG));
        bin_log.resize(n+1);

        bin_log[1] = 0;
        for(int i = 2; i <= n; i++) {
            bin_log[i] = bin_log[i/2]+1;
        }
        for(int i = 0; i < n; i++) {
            m[i][0] = arr[i];
        }

        // 2) preprocessing, O(N*log(N))
        for(int k = 1; k < LOG; k++) {
            for(int i = 0; i + (1 << k) - 1 < n; i++) {
                m[i][k] = operation(m[i][k-1], m[i+(1<<(k-1))][k-1]);
            }
        }
    }

    int query(int L, int R) { // O(1)
        int length = R - L + 1;
        int k = bin_log[length];
        return operation(m[L][k], m[R-(1<<k)+1][k]);
    }

   
};
