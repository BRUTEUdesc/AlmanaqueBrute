template <typename T, auto OP> struct op_stack : stack<T> {
    stack<T> st;
    T get() { return st.top(); }
    void add(T element) {
        this->push(element);
        st.push(st.empty() ? element : OP(element, st.top()));
    }
    void remove() {
        st.pop();
        this->pop();
    }
};