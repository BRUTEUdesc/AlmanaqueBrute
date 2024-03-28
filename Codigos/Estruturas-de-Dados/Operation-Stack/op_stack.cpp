template <typename T, auto OP> struct op_stack {
    vector<pair<T, T>> st;
    T get() { return st.back().second; }
    T top() { return st.back().first; }
    T bottom() { return st.front().first; }
    void push(T x) {
        auto snd = st.empty() ? x : OP(st.back().second, x);
        st.push_back({x, snd});
    }
    void pop() { st.pop_back(); }
    bool empty() { return st.empty(); }
    int size() { return (int)st.size(); }
};
