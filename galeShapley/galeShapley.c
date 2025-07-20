#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *pref;      // preference list
    int next;       // next woman index to propose to
    int partner;    // -1 if free, otherwise woman index
} Man;

typedef struct {
    int *list;      // preference list
    int *rank;      // rank[m] = woman's opinion of man m
    int partner;    // fiancé or -1 if free
} Woman;

/* ----------- helpers ----------- */

static int free_man(const Man m[], int n)
{
    for (int i = 0; i < n; ++i)
        if (m[i].partner == -1)
            return i;
    return -1;
}

/* read exactly n integers in [0,n-1] into dst */
static void read_pref(int *dst, int n, const char *who, int idx)
{
    int j = 0;
    while (j < n) {
        int v;
        if (scanf("%d", &v) != 1) {
            puts("Input failure; aborting.");
            exit(1);
        }
        if (v < 0 || v >= n) {
            printf("%s %d: %d is out of range (0-%d).  Try again - ",
                   who, idx, v, n - 1);
            continue;               // ask again for this same position
        }
        dst[j++] = v;
    }
}

/* ----------- main ----------- */

int main(void)
{
    int n;
    printf("Number of pairs: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    Man   *men   = calloc(n, sizeof *men);
    Woman *women = calloc(n, sizeof *women);
    if (!men || !women) { perror("calloc"); return 1; }

    /* men’s preferences */
    for (int i = 0; i < n; ++i) {
        men[i].pref    = malloc(n * sizeof *men[i].pref);
        men[i].next    = 0;
        men[i].partner = -1;

        printf("Man %d preference list (top-bottom): ", i);
        read_pref(men[i].pref, n, "man", i);
    }

    /* women’s preferences + rank tables */
    for (int w = 0; w < n; ++w) {
        women[w].list    = malloc(n * sizeof *women[w].list);
        women[w].rank    = malloc(n * sizeof *women[w].rank);
        women[w].partner = -1;

        printf("Woman %d preference list (top-bottom): ", w);
        read_pref(women[w].list, n, "woman", w);

        for (int j = 0; j < n; ++j)
            women[w].rank[ women[w].list[j] ] = j;
    }

    /* ----------- Gale–Shapley loop ----------- */
    for (int m; (m = free_man(men, n)) != -1; ) {
        int w = men[m].pref[ men[m].next++ ];     // next woman to propose

        if (women[w].partner == -1) {
            /* she’s free → engage */
            men[m].partner   = w;
            women[w].partner = m;
        } else if (women[w].rank[m] < women[w].rank[ women[w].partner ]) {
            /* she prefers m → dump current fiancé */
            int dumped = women[w].partner;
            men[dumped].partner = -1;

            men[m].partner   = w;
            women[w].partner = m;
        }
        /* else she rejects; m stays free */
    }

    /* ----------- result ----------- */
    puts("\nMatches (man - woman):");
    for (int i = 0; i < n; ++i)
        printf("  %d - %d\n", i, men[i].partner);

    return 0;   /* (free omitted for brevity) */
}
