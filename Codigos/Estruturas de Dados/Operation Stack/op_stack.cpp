template <typename T> struct op_stack {
    stack<pair<T, T>> st;
    T result;
    T op(T a, T b) {
        return a; // TODO: op to compare
        // min(a, b);
        // gcd(a, b);
        // lca(a, b);
    }
    T get() { return result = st.top().second; }
    void add(T element) {
        result = st.empty() ? element : op(element, st.top().second);
        st.push({element, result});
    }
    void remove() {
        T removed_element = st.top().first;
        st.pop();
    }
};
