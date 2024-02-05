template <typename T, auto OP> struct op_queue : queue<T> {
    op_stack<T, OP> st1, st2;
    T get() {
        if (st1.empty()) {
            return st2.get();
        }
        if (st2.empty()) {
            return st1.get();
        }
        return OP(st1.get(), st2.get());
    }
    void add(T element) {
        this->push(element);
        st1.add(element);
    }
    void remove() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.add(st1.top());
                st1.remove();
            }
        }
        st2.remove();
        this->pop();
    }
};