#include <stdio.h>
#include <time.h>
#include <stdlib.h>
extern char* tzname[];

int main() {
    time_t now;
    struct tm* sp;
    (void)time(&now);
    setenv("TZ","PST8",1);
    printf("%lld\n", now);
    printf("%s", ctime(&now));
    printf("%lld\n", now);
    sp = localtime(&now);
    printf("%d/%d/%02d %d:%02d %s\n",
        sp->tm_mon + 1, sp->tm_mday,
        sp->tm_year + 1900, sp->tm_hour,
        sp->tm_min, tzname[sp->tm_isdst]);
    printf("%lld\n", (sp->tm_year + 1900) * 365 * 24 * 60 * 60 + sp->tm_mon * 31 * 24 * 60 * 60  + sp->tm_min * 60);
    return 0;
}
