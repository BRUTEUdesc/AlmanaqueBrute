template <typename T> struct op_stack : stack<T> {
    stack<T> st;
    T op(T a, T b) {
        return min(a, b); // Operacao, pode ser qualquer uma
    }
    T get() {
        return st.top();
    }
    void add(T element) {
        this->push(element);
        st.push(st.empty() ? element : op(element, st.top()));
    }
    void remove() {
        st.pop();
        this->pop();
    }
};
