    for (int i = 0; i < n; ++i) {
        a[i] = num[i] / (1 << getTimes(num[i]));
        if (maxx == -1 || a[i] > a[maxx])
            maxx = i;
    }