typedef struct zone_struct {
        ...
        ...
        ...
    spinlock_t lock;
    unsigned long free_pages;
    unsigned long pages_min;
    unsigned long pages_low;
    unsigned long pages_high;
    int need_balance;
        ...
        ...
        ...
} zone_t;