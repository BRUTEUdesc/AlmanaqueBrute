template <typename T, auto OP> struct op_stack {
    vector<pair<T, T>> st;
    T get() { return st.top().second; }
    void add(T element) { st.push(st.empty() ? element : OP(element, st.top())); }
    void remove() { st.pop_back(); }
};