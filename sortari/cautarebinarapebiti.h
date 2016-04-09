template < typename T > 
int binSearch(ResizableArray < T > a, T value) {
    int position = 0, step = (1 << 30);
    for (; step > 0; step >>= 1) {
        if (position + step < a.size() && a[position + step] <= value) {
            position += step;
        }
    }

    if (a[position] != value) {
        return -1;
    }

    return position;
}