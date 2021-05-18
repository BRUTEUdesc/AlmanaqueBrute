template <typename T>
struct op_queue{
    stack<pair<T, T>> s1, s2;
    T result;
    
    T op(T a, T b){
        return a; // TODO: op to compare
        // min(a, b);
        // gcd(a, b);
        // lca(a, b);
    }
    
    T get(){
        if (s1.empty() || s2.empty()) 
            return result = s1.empty() ? s2.top().second : s1.top().second;
        else
            return result = op(s1.top().second, s2.top().second);
    }
    
    void add(T element){
        result = s1.empty() ? element : op(element, s1.top().second);
        s1.push({element, result});
    }
    
    void remove(){
        if (s2.empty()) {
            while (!s1.empty()) {
                T elem = s1.top().first;
                s1.pop();
                T result = s2.empty() ? elem : op(elem, s2.top().second);
                s2.push({elem, result});
            }
        }
        T remove_elem = s2.top().first;
        s2.pop();
    }
};
