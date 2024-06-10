template <typename T, auto OP>
struct op_queue {
    op_stack<T, OP> in, out;
    void push(T x) { in.push(x); }
    void pop() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        out.pop();
    }
    T get() {
        if (out.empty()) return in.get();
        if (in.empty()) return out.get();
        return OP(in.get(), out.get());
    }
    T front() {
        if (out.empty()) return in.bottom();
        return out.top();
    }
    T back() {
        if (in.empty()) return out.bottom();
        return in.top();
    }
};
